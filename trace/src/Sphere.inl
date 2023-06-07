#pragma once

// ===========================================================================
// Sphere.inl
// ===========================================================================

using namespace std;

#include "Vec3.hpp"
#include "Sphere.hpp"

inline
Sphere::Sphere(double radius, Vec3 center, Vec3 color)
    : radius(radius), center(center), color(color) {}

inline
ostream& operator<<(ostream& os, const Sphere& s)
{
    os << "Sphere("
        << s.radius
        << ","
        << s.center
        << ","
        << s.color << ")";
    return os;
}
