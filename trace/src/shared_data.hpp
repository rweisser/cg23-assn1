#pragma once

// ===========================================================================
// shared_data.hpp
// 
// Shared global variables
// ===========================================================================

using namespace::std;

#include <unordered_map>
#include <vector>

#include "Screen.hpp"
#include "Sphere.hpp"
#include "Surface.hpp"
#include "Vec2.hpp"
#include "Vec3.hpp"

#if defined MAIN
    #define EXTERN
#else
    #define EXTERN extern
#endif

EXTERN Vec3 background;
EXTERN Vec3 eyep;
EXTERN Vec3 lookp;
EXTERN Vec3 up;
EXTERN Vec2 fov;
EXTERN Vec2 screen_size;
EXTERN unordered_map<string, Surface>* surface_map;
EXTERN vector<Sphere> sphere_vec;
EXTERN Screen look_screen;
