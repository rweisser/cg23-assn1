#pragma once

// G.hpp

#include <iostream>
#include <vector>

#include "Screen.hpp"
#include "Sphere.hpp"
#include "Surface.hpp"
#include "Vec2.hpp"
#include "Vec3.hpp"

using namespace std;


// A struct to hold global data.  There will be one instance of this
// created in Trace.cpp.
struct G
{
    Vec3 background;  // bg color
    Vec3 eyep;
    Vec3 lookp;
    Vec3 up;
    Vec2 fov;
    Vec2 screen_size;
    Screen look_screen;
    vector<Sphere> sphere_vec;

    string str() const;
};

ostream& operator<<(ostream& os, const G& g);
