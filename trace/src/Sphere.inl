#pragma once

// ===========================================================================
// Sphere.inl
// ===========================================================================

using namespace::std;

#include "shared_data.hpp"
#include "Surface.hpp"
#include "Vec3.hpp"
#include "Sphere.hpp"

extern unordered_map<string, Surface> surface_map;

inline
Sphere::Sphere(string surface_name, double radius, Vec3 center)
    : surface_name(surface_name), radius(radius), center(center) {}

inline
Vec3 Sphere::color()
{
    return surface_map[surface_name].color;
}

inline
ostream& operator<<(ostream& os, const Sphere& s)
{
    os << "Sphere("
        << s.surface_name
        << ","
        << s.radius <<
        ","
        << s.center << ")";
    return os;
}
