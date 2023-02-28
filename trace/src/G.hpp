#pragma once
// G.cpp

#include <iostream>
#include <vector>

#include "Light.hpp"
#include "Screen.hpp"
#include "Sphere.hpp"
#include "Vec2.hpp"
#include "Vec3.hpp"

// A struct to hold global variables.  There will be one instance of this
// struct which will be global in Trace.cpp and extern in any other files which
// need it (like parse.cpp).
struct G
{
    G();

    Vec3 background;
    Vec3 eyep;
    Vec3 lookp;
    Vec3 up;
    Vec2 fov;
    Vec2 screen_size;
    int maxdepth;
    float cutoff;
    Screen look_screen;
    vector<Sphere> sphere_vec;
    vector<Light> light_vec;
};

ostream& operator<<(ostream& os, const G& g);
