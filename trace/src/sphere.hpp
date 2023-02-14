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
};

#include "sphere.inl"
