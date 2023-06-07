#pragma once

// ===========================================================================
// Surface.hpp
// ===========================================================================

using namespace std;

#include <string>

#include "Vec3.hpp"

struct Surface
{
    string name;
    Vec3 color;

    Surface();
    Surface(string name, Vec3 color);
};

#include "Surface.inl"
