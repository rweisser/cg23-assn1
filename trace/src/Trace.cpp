// ===========================================================================
// Trace.cpp
// ===========================================================================

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

#include "G.hpp"
#include "parse.hpp"
#include "Sphere.hpp"
#include "Surface.hpp"
#include "Vec3.hpp"

#include "tests.hpp" // XXX

using namespace std;

G g; // Global shared data

const char* usage = "Trace filename";

Vec3 pixel_center(double d, int x, int y);
void write_pixel(const Vec3& color);
double find_closest(const Vec3& e, const Vec3& d, Vec3& c);
void ray_trace();
void write_ppm_file_header();

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
	parse_file(file_name);
	cout << "finished parsing input" << endl;

	test_parse(); // XXX
	return 0;

	// open ppm output file in trace directory
	string ppmname = std::string(PROJECT_BUILD_DIR) + "trace.ppm";
	ppmfile.open(ppmname, std::ios::out | std::ios::binary);
	if (ppmfile.fail()) {
		std::cerr << "Error opening " << ppmname << '\n';
		return 1;
	}
	write_ppm_file_header();
	ray_trace();
	ppmfile.close();
	cout << "trace completed" << endl;

	// report final timing
    auto endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> elapsed = endTime - startTime;
    std::cout << elapsed.count() << " seconds\n";
    return 0;
}

// returns center of the pixel at (x, y).
// d is the distance from eyep to lookp.
// x and y are the screen coordinates.
Vec3 pixel_center(double d, int x, int y)
{
	// I did all these assignments to make the following code easier to
	// understand.  I hope the compiler optimizes all of the away.
	double left     = g.look_screen.left;
	double right    = g.look_screen.right;
	double top      = g.look_screen.top;
	double bottom   = g.look_screen.bottom;
	double pixelsh  = g.look_screen.pixelsh;
	double pixelsy  = g.look_screen.pixelsv;

	double screen_u = left + (right - left) * (x + 0.5) / pixelsh;
	double screen_v = top + (bottom - top)  * (y + 0.5) / pixelsy;
	return g.eyep - d * g.look_screen.w
		 + screen_u   * g.look_screen.u
	     + screen_v   * g.look_screen.v;
}

// Finds the closest object intersected by the ray from e in the direction
// that goes through pc (pixel center.  The return value is the closest
// distance factor t1 or t2.  The distance factor t as a value such that
// e + t * (e - pc) hits the surface of an object.  The color of the object
// is returned in color.  If no object is intersected, find_closest
// returns a negative value and leaves color unchanged.
double find_closest(const Vec3& e, const Vec3& pc, Vec3 &color)
{
	double closest   = DBL_MAX;
	double t1        = DBL_MAX;
	double t2        = DBL_MAX;
	double dist      = 0;
	for (Sphere s : g.sphere_vec) {
		bool found_intersection = s.intersect(e, pc, t1, t2);
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
	return closest == DBL_MAX ? -1 : closest;
}

void ray_trace()
{
	Vec3 pc;         // pixel center or other ray origin
	double t = 0;    // distance factor of closest object, if exists
	Vec3 color;      // color of closest object, if exists
	double d = (g.eyep - g.lookp).mag(); // distance from eyep to lookp
	int y;
	for (y = 0; y < g.screen_size.y; y++) {
		if (y % 100 == 0 && y > 0)
			cout << y << " rows traced" << endl;
		for (int x = 0; x < g.screen_size.x; x++) {
			pc = pixel_center(d, x, y);
			t = find_closest(g.eyep, pc - g.eyep, color);
			if (t <= 0)
				write_pixel(g.background);
			else
				write_pixel(color);
		}
	}
	cout << y << " rows traced" << endl;
}

void write_pixel(const Vec3& color)
{
	uColor c;
	c.r = min(255, static_cast<int>(color.x * 255));
	c.g = min(255, static_cast<int>(color.y * 255));
	c.b = min(255, static_cast<int>(color.z * 255));
	ppmfile.write((char *) &c, sizeof c);
}

void write_ppm_file_header() {
	ppmfile << "P6\n"
		    << g.screen_size.x
		    << " " 
		    << g.screen_size.y
		    << "\n255\n";
}