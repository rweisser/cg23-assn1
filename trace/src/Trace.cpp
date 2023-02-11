// basic starter code for ray tracing assignment

// For shared_data.hpp to work correctly, MAIN must be defined in this file,
// but must not be defined in any other file.
#define MAIN

#include "Color.hpp"
#include "Config.h"

#include <chrono>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "shared_data.hpp"

#include "Vec3.hpp"
#include "parse.hpp"

const char* usage = "Trace filename";

using namespace std;
int main(int argc, char **argv)
{
	if (argc != 2) {
		cout << "usage: " << usage << endl;
		exit(1);
	}
	char* file_name_arg = argv[1];

	parse_file(file_name);
	cout << "background: " << background << endl;
	cout << "eyep: " << eyep << endl;
	cout << "lookp: " << lookp << endl;
	cout << "up: " << up << endl;
	return 0;

	// platform-independent timing
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
