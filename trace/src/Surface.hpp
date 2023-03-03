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
    Surface(string name, Vec3 ambient, Vec3 diffuse, Vec3 specular,
            float specpow /* = 0 */, float reflect /* = 0 */);
};

ostream& operator<<(ostream& os, const Surface& s);

#include "Surface.inl"
