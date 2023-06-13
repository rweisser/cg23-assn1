#pragma once

// ===========================================================================
// Sphere.hpp
// ===========================================================================

using namespace std;

#include "Object.hpp"
#include "Ray.hpp"
#include "Vec3.hpp"

struct Sphere : Object
{
    double radius;
    Vec3 center;
    // Vec3 color;  // inherited from Object

    Sphere(double radius, Vec3 center, Vec3 color);

    bool intersect(const Vec3& e, const Vec3& d,
                   double &t1, double &t2) const;
    double intersect(Ray ray) { return 0; }
};

#include "Sphere.inl"
