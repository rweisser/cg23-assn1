#pragma once

// ===========================================================================
// Shared data.
// Global variables.
// Structures:  surface and sphere.
// ===========================================================================

#include <unordered_map>
#include <vector>

#include "Vec2.hpp"
#include "Vec3.hpp"

#if defined MAIN
    #define EXTERN
#else
    #define EXTERN extern
#endif

struct sphere;
struct surface;

EXTERN Vec3 background;
EXTERN Vec3 eyep;
EXTERN Vec3 lookp;
EXTERN Vec3 up;
EXTERN Vec2 fov;
EXTERN Vec2 screen;
EXTERN unordered_map<string, surface> surfaces;
EXTERN vector<sphere> spheres;

struct surface
{
    string name;
    Vec3 color;
};

inline
ostream& operator<<(ostream& os, const surface& s)
{
    os << "surface("
       << s.name 
       << ","
       << s.color
       << ")";
    return os;
}

struct sphere
{
    string surface_name; // the surface supplies the color
    double radius;
    Vec3 center;

    Vec3 color()
    {
        return surfaces[surface_name].color;
    }
};

inline
ostream& operator<<(ostream& os, const sphere& s)
{
    os << "sphere("
       << s.surface_name
       << ","
       << s.radius << 
       ","
       << s.center << ")";
    return os;
}

