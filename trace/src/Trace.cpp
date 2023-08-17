// ===========================================================================
// Trace.cpp
// ===========================================================================

#include <chrono>

#include "Color.hpp"
#include "Config.h"
#include "Globals.hpp"
#include "Parser.hpp"
#include "Ray.hpp"
#include "Sphere.hpp"
#include "Surface.hpp"
#include "Tests.hpp"
#include "Vec3.hpp"

using namespace std;

const char* usage = "Trace filename";

void inline write_pixel(const Vec3& color);
Vec3 find_closest(const Ray& ray);
void ray_trace();
void inline write_pixel(const Vec3& color);
void write_ppm_file_header();

Globals g; // global data

static ofstream ppmfile;

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

	// The parser reads a .ray file and loads the information in the Globals
	// instance g.
	Parser* parser = new Parser(g);
	parser->parse_file(file_name);
	delete parser;

	//Tests tests(g); // XXX
	//tests.test_parse(); // XXX
	//cout << "XXX =======================================================" << endl;
	//cout << "XXX g.object_vec.size() = " << g.object_vec.size() << endl;
	//return 1; // XXX

	// open ppm output file in trace directory
	string ppmname = string(PROJECT_BUILD_DIR) + "trace.ppm";
	ppmfile.open(ppmname, ios::out | ios::binary);
	if (ppmfile.fail()) {
		cerr << "Error opening " << ppmname << '\n';
		return 1;
	}
	write_ppm_file_header();
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

	// report final timing
    auto endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> elapsed = endTime - startTime;
    std::cout << elapsed.count() << " seconds\n";
    return 0;
}

/*
// Finds the closest object intersected by the ray from e in the direction
// of d.  The return value is the distance factor closest.  The color of the
// object is returned in color.  If no object is intersected, find_closest
// returns a negative value and leaves color unchanged.
double find_closest(const Vec3& e, const Vec3& d, Vec3 &color)
{
	double closest   = INFINITY;
	double t1        = INFINITY;
	double t2        = INFINITY;
	double dist      = 0;
	for (const Sphere& s : g.sphere_vec) {
		bool found_intersection = s.intersect(e, d, t1, t2);
		if (!found_intersection)
			continue;
		if (t1 <= 0 && t2 <= 0)
			continue;
		dist = t1 > 0 ? t1 : t2;
		if (dist < closest) {
			closest = dist;
			color = s.color;
		}
	}
	return closest == INFINITY? -1 : closest;
}
*/

// Finds the closest object intersected by the ray from e in the direction
// of d.  Returns the color of the nearest object, if found.  Otherwise,
// returns the background color.
Vec3 find_closest(const Ray& ray)
{
	double closest = INFINITY;
	Vec3   color   = g.background;
	for (const Object* o : g.object_vec) {
		// Find distance to object
		double t = o->intersect(ray);
		if (t == INFINITY)
			continue;
		if (Vec3::TOLERANCE < t && t < closest) {
			color = o->color;
		}
		// distance is negative or too close to zero, so loop
	}
	return color;
}

void ray_trace()
{
	double d = (g.eyep - g.lookp).mag(); // distance from eyep to lookp
	int y;
	for (y = 0; y < g.screen_size.y; y++) {
		if (y % 100 == 0 && y > 0)
			cout << y << " rows traced" << endl;
		for (int x = 0; x < g.screen_size.x; x++) {
			Vec3 pc = g.look_screen.pixel_center(g.eyep, d, x, y);
			Ray ray(g.eyep, pc - g.eyep);
			Vec3 color = find_closest(ray);
			write_pixel(color);
		}
	}
	cout << y << " rows traced, trace completed" << endl;
}

/*
void ray_trace()
{
	Vec3 pc;         // pixel center
	double t = 0;    // distance factor of closest object, if exists
	Vec3 color;      // color of closest object, if exists
	double d = (g.eyep - g.lookp).mag(); // distance from eyep to lookp
	int y;
	for (y = 0; y < g.screen_size.y; y++) {
		if (y % 100 == 0 && y > 0)
			cout << y << " rows traced" << endl;
		for (int x = 0; x < g.screen_size.x; x++) {
			pc = g.look_screen.pixel_center(g.eyep, d, x, y);
			t = find_closest(g.eyep, pc - g.eyep, color);
			if (t <= 0)
				write_pixel(g.background);
			else
				write_pixel(color);
		}
	}
	cout << y << " rows traced, trace completed" << endl;
}
*/

void inline write_pixel(const Vec3& color)
{
	uColor c;
	c.r = min(255, static_cast<int>(color.x * 255));
	c.g = min(255, static_cast<int>(color.y * 255));
	c.b = min(255, static_cast<int>(color.z * 255));
	ppmfile.write((char *) &c, sizeof c);
}

void write_ppm_file_header() {
	ppmfile << "P6\n" << g.screen_size.x << " " << g.screen_size.y << "\n255\n";
}