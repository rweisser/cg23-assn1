#pragma once
// G.cpp

#include <unordered_map>
#include <vector>

#include "Screen.hpp"
#include "Sphere.hpp"
#include "Vec2.hpp"
#include "Vec3.hpp"

// A struct to hold global variables.  There will be one instance of this
// struct which will be global in Trace.cpp and extern in any other files which
// need it (like parse.cpp).
struct Gj
{
    Vec3 background;
    Vec3 eyep;
    Vec3 lookp;
    Vec3 up;
    Vec2 fov;
    Vec2 screen_size;
    unordered_map<string, Surface>* surface_map;
    vector<Sphere> sphere_vec;
    Screen look_screen;
};
