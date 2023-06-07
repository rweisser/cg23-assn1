#pragma once

// ===========================================================================
// Sphere.hpp
// ===========================================================================

using namespace std;

#include "Vec3.hpp"

struct Sphere
{
    double radius;
    Vec3 center;
    Vec3 color;  // color is picked up from the sphere's Surface entry

    Sphere(double radius, Vec3 center, Vec3 color);

    bool intersect(const Vec3& e, const Vec3& d,
                   double &t1, double &t2) const;
};

#include "Sphere.inl"
