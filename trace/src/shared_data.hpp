#pragma once

// ===========================================================================
// Shared data.
// Global variables.
// Structures:  surface and sphere.
// ===========================================================================

#include <unordered_map>
#include <vector>

#include "Vec3.hpp"

#if defined MAIN
    #define EXTERN
#else
    #define EXTERN extern
#endif

struct surface
{
    string name;
    Vec3 color;
};

struct sphere
{
    string surface;    // the surface supplies the color
    double radius;
    Vec3 center;
};

EXTERN Vec3 background;
EXTERN Vec3 eyep;
EXTERN Vec3 lookp;
EXTERN Vec3 up;
EXTERN unordered_map<string, surface> surfaces;

// Can't initialize an extern
#if defined MAIN
    vector<sphere> spheres(1000);
#else
    extern vector<sphere> spheres;
#endif

