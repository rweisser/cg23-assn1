// Trace.cpp

// For shared_data.hpp to work correctly, MAIN must be defined in this file,
// but must not be defined in any other file.
#define MAIN

#include "Color.hpp"
#include "Config.h"

#include <algorithm>
#include <chrono>
#include <cstdint>
#include <float.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "shared_data.hpp"
#include "Sphere.hpp"
#include "Surface.hpp"
#include "Vec3.hpp"
#include "parse.hpp"

using namespace std;

const char* usage = "Trace filename";
const double PI = 3.141592653589793;

Vec3 pixel_center(int x, int y);
void inline write_pixel(const Vec3& color);
void init_look_screen();
void ray_trace();

static ofstream ppmfile;

void test_parse()
{
	cout << "background: " << background << endl;
	cout << "eyep: " << eyep << endl;
	cout << "lookp: " << lookp << endl;
	cout << "up: " << up << endl;
	cout << "fov: " << fov << endl;
	cout << "screen_size: " << screen_size << endl;
	// cout << endl;
	// for (auto iter = surface_map->cbegin(); iter != surface_map->cend(); iter++) {
	//	 cout << iter->first << " -> " << iter->second << endl;
	// }
	cout << endl;
	for_each(sphere_vec.cbegin(), sphere_vec.cend(), [](const Sphere& s) { cout << s << endl; });
}

void test_intersect2(Vec3& e, Vec3& d, Sphere& s)
{
	cout << endl;
	cout << "e = " << e << ", d = " << d << ", s = " << s << endl;
	double t1 = -1000000, t2 = -1000000;
	bool res = s.intersect(e, d, t1, t2);
	cout << "length of d - e is " << (d - e).mag() << endl;
	cout << "result = " << res
		<< ", t1 = " << t1
		<< ", t2 = " << t2 << endl;
	cout << "color = " << s.color << endl;
}

void test_intersect()
{
	cout << "starting test_intersect" << endl;

	test_intersect2(
		Vec3(1, 1, 0),  // e
		Vec3(1, 0, 0),  // d
		Sphere("sph001", 1, Vec3(4, 1, 0), Vec3(0, 0, 0)) // s
	);

	test_intersect2(
		Vec3(1, 1, 0),  // e
		Vec3(1, 0, 0),  // d
		Sphere("sph001", 3, Vec3(4, 1, 0), Vec3(0, 0, 0)) // s
	);
		
	test_intersect2(
		Vec3(1, 1, 0),  // e
		Vec3(1, 0, 0),  // d
		Sphere("sph001", 5, Vec3(4, 1, 0), Vec3(0, 0, 0)) // s
	);

	test_intersect2(
		Vec3(1, 1, 1),  // e
		Vec3(2, 2, 2),  // d
		Sphere("sph001", sqrt(3), Vec3(3, 3, 3), Vec3(0, 0, 0)) // s
	);

	test_intersect2(
		Vec3(1, 1, 1),  // e
		Vec3(2, 2, 2),  // d
		Sphere("sph001", 0.5, Vec3(3, 3, 3), Vec3(0, 0, 0)) // s
	);

	test_intersect2(
		Vec3(1, 1, 1),  // e
		Vec3(2, 2, 2),  // d
		Sphere("sph001", 0.5, Vec3(20, 20, 20), Vec3(0, 0, 0)) // s
	);

	test_intersect2(
		Vec3(1, 1, 1),  // e
		Vec3(2, 2, 2),  // d
		Sphere("sph001", 0.5, Vec3(20, 0, 0), Vec3(0, 0, 0)) // s
	);
}

void test_cross2(const Vec3& v1, const Vec3& v2)
{
	cout << v1 << " X " << v2 << " = " << v1.cross(v2) << endl;
	cout << v2 << " X " << v1 << " = " << v2.cross(v1) << endl;
}

void test_cross()
{
	test_cross2(Vec3(1, 2, 3), Vec3(1, 1, 1));
	test_cross2(Vec3(1, 0, 0), Vec3(0, 1, 0));
	test_cross2(Vec3(1, -1, -1), Vec3(10, 11, 12));
}

int main(int argc, char **argv)
{
	// platform-independent timing
	auto startTime = std::chrono::high_resolution_clock::now();

	if (argc != 2) {
		cout << "usage: " << usage << endl;
		exit(1);
	}
	char* file_name_arg = argv[1];
	string file_name(PROJECT_DATA_DIR);
	file_name += file_name_arg;
	surface_map = new unordered_map<string, Surface>;
	parse_file(file_name);
	delete surface_map;
	cout << "finished parsing input" << endl;

	// test_parse(); return 0;
	// test_intersect(); return 0;
	test_cross(); return 0;
	
	init_look_screen();
	// cout << look_screen;

	// open ppm output file in trace directory
	string ppmname = std::string(PROJECT_BASE_DIR) + "trace.ppm";
	ppmfile.open(ppmname, std::ios::out | std::ios::binary);
	if (ppmfile.fail()) {
		std::cerr << "Error opening " << ppmname << '\n';
		return 1;
	}

	ray_trace();

	ppmfile.close();

	// hard-coded data for a 4x4 image
	//int width = 4, height = 4;
	//std::vector<uColor> image {
	//	{255, 255,   0}, {255, 255,   0}, {255, 255,   0}, {255,   0,   0},
	//	{  0,   0, 255}, {  0,   0,   0}, { 85,  85,  85}, {255,   0,   0},
	//	{  0,   0, 255}, {170, 170, 170}, {255, 255, 255}, {255,   0,   0},
	//	{  0,   0, 255}, {  0, 255,   0}, {  0, 255,   0}, {  0, 255,   0}
	//};

	//// output ppm format: text header then raw binary data
	//ppmfile << "P6\n" << width << " " << height << "\n255\n";
	//ppmfile.write((char*)(&image[0]), width * height * sizeof(uColor));

	// report final timing
    auto endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> elapsed = endTime - startTime;
    std::cout << elapsed.count() << " seconds\n";
    return 0;
}

void init_look_screen() {
	Vec3 wtemp = eyep - lookp;
	double d = wtemp.mag();
	look_screen.w = wtemp.normalize();
	look_screen.u = up.cross(look_screen.w).normalize();
	look_screen.v = look_screen.w.cross(look_screen.u);

	// Horizontal fov
	int degrees = fov.x;
	double theta = degrees * PI / 180;
	double right = d * tan(theta / 2);
	look_screen.left = -right;
	look_screen.right = right;
	
	// Vertical fov
	degrees = fov.y;
	theta = degrees * PI / 180;
	double top = d * tan(theta / 2);
	look_screen.bottom = -top;
	look_screen.top = top;

	look_screen.pixelsh = screen_size.x;
	look_screen.pixelsv = screen_size.y;
}

inline
Vec3 pixel_center(int x, int y)
{
	return look_screen.lp
         + (x + 0.5) * look_screen.v
	     + (y + 0.5) * look_screen.u;
}

void ray_trace()
{
	for (int y = 0; y < screen_size.y; y++)
		for (int x = 0; x < screen_size.x; x++) {
			Vec3 pc = pixel_center(x, y);
			Vec3 ray = eyep - pc;
			double t = DBL_MAX;
			Vec3 color;
			// check intersections
			if (t == DBL_MAX)
				; // write out background color
			else
				; // write out pixel color
		}
}

void inline write_pixel(const Vec3& color)
{
	int x = min(255, static_cast<int>(color.x * 255));
	int y = min(255, static_cast<int>(color.y * 255));
	int z = min(255, static_cast<int>(color.z * 255));
}
