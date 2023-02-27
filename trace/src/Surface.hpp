#pragma once

// ===========================================================================
// Surface.hpp
// ===========================================================================

using namespace::std;

#include <string>

#include "Vec3.hpp"

struct Surface
{
    string name;
    Vec3 ambient;
    Vec3 diffuse;
    Vec3 specular;
    float specpow;
    float reflect;

    Surface();
    Surface(string name, Vec3 ambient, Vec3 diffuse, Vec3 specular, float specpow, float reflect);
};

#include "Surface.inl"
