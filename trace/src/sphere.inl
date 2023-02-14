#pragma once

// ===========================================================================
// Sphere.inl
// ===========================================================================

using namespace::std;

#include "shared_data.hpp"
#include "Surface.hpp"
#include "Vec3.hpp"

inline
Sphere::Sphere(string surface_name, double radius, Vec3 center)
    : surface_name(surface_name), radius(radius), center(center) {}

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
