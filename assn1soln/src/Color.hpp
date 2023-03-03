// really basic type for unsigned byte colors
#pragma once

#include "Vec3.hpp"

// intentionally a POD (plain old data) type
// can have constructors & member functions, but nothing virtual
struct Color {
	unsigned char r, g, b;		// public access to color data

	// constructor from Vec3
	Color(const Vec3 v = Vec3()) {
		r = (unsigned char)(255.f * v[0]);
        g = (unsigned char)(255.f * v[1]);
        b = (unsigned char)(255.f * v[2]);
	}
};
