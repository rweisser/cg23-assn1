// basic starter code for ray tracing assignment

#include "Color.hpp"
#include "Config.h"

#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <chrono>
#include <cstdint>

#define MAIN
#include "shared_data.hpp"

#include "Vec3.hpp"
#include "parse.hpp"

int main()
{
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
