// Trace.cpp

// For shared_data.hpp to work correctly, MAIN must be defined in this file,
// but must not be defined in any other file.
#define MAIN

#include "Color.hpp"
#include "Config.h"

#include <algorithm>
#include <chrono>
#include <cstdint>
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

void test_parse()
{
	cout << "background: " << background << endl;
	cout << "eyep: " << eyep << endl;
	cout << "lookp: " << lookp << endl;
	cout << "up: " << up << endl;
	cout << "fov: " << fov << endl;
	cout << "screen" << screen << endl;
	cout << endl;
	for (auto iter = surface_map.cbegin(); iter != surface_map.cend(); iter++) {
		cout << iter->first << " -> " << iter->second << endl;
	}
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
	cout << "color = " << surface_map[s.surface_name].color << endl;
}

void test_intersect()
{
	cout << "starting test_intersect" << endl;

	test_intersect2(
		Vec3(1, 1, 0),  // e
		Vec3(1, 0, 0),  // d
		Sphere("sph001", 1, Vec3(4, 1, 0))); // s

	test_intersect2(
		Vec3(1, 1, 0),  // e
		Vec3(1, 0, 0),  // d
		Sphere("sph001", 3, Vec3(4, 1, 0))); // s

	test_intersect2(
		Vec3(1, 1, 0),  // e
		Vec3(1, 0, 0),  // d
		Sphere("sph001", 5, Vec3(4, 1, 0))); // s

	test_intersect2(
		Vec3(1, 1, 1),  // e
		Vec3(2, 2, 2),  // d
		Sphere("sph001", 1, Vec3(3, 3, 3))); // s

	test_intersect2(
		Vec3(1, 1, 1),  // e
		Vec3(2, 2, 2),  // d
		Sphere("sph001", 0.5, Vec3(3, 3, 3))); // s

	test_intersect2(
		Vec3(1, 1, 1),  // e
		Vec3(2, 2, 2),  // d
		Sphere("sph001", 0.5, Vec3(20, 20, 20))); // s

	test_intersect2(
		Vec3(1, 1, 1),  // e
		Vec3(2, 2, 2),  // d
		Sphere("sph001", 0.5, Vec3(20, 0, 0))); // s
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		cout << "usage: " << usage << endl;
		exit(1);
	}
	char* file_name_arg = argv[1];
	string file_name(PROJECT_DATA_DIR);
	file_name += file_name_arg;
	parse_file(file_name);

	// test_parse(); return 0;
	test_intersect();

	// platform-independent timing[
    auto startTime = std::chrono::high_resolution_clock::now();

	// hard-coded data for a 4x4 image
	int width = 4, height = 4;
	std::vector<uColor> image {
		{255, 255,   0}, {255, 255,   0}, {255, 255,   0}, {255,   0,   0},
		{  0,   0, 255}, {  0,   0,   0}, { 85,  85,  85}, {255,   0,   0},
		{  0,   0, 255}, {170, 170, 170}, {255, 255, 255}, {255,   0,   0},
		{  0,   0, 255}, {  0, 255,   0}, {  0, 255,   0}, {  0, 255,   0}
	};

	// open ppm output file in trace directory
	std::string ppmname = std::string(PROJECT_BASE_DIR) + "trace.ppm";
	std::fstream ppmfile(ppmname, std::ios::out | std::ios::binary);
	if(ppmfile.fail()) {
		std::cerr << "Error opening " << ppmname << '\n';
		return 1;
	}

	// output ppm format: text header then raw binary data
	ppmfile << "P6\n" << width << " " << height << "\n255\n";
	ppmfile.write((char*)(&image[0]), width * height * sizeof(uColor));

	// report final timing
    auto endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> elapsed = endTime - startTime;
    std::cout << elapsed.count() << " seconds\n";
    return 0;
}
