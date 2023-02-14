#pragma once

// ===========================================================================
// Sphere.hpp
// ===========================================================================

using namespace::std;

#include "Vec3.hpp"

struct Sphere
{
    string surface_name; // the surface supplies the color
    double radius;
    Vec3 center;

    Sphere(string surface_name, double radius, Vec3 center);
    Vec3 color();

    bool intersect(const Vec3& e, const Vec3& d, double &t1, double &t2);
};

#include "Sphere.inl"
