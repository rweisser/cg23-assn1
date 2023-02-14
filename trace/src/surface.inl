#pragma once

// ===========================================================================
// Surface.inl
// ===========================================================================

using namespace::std;

#include "Vec3.hpp"

inline
Surface::Surface()
    : name(""), color(Vec3::Vec3_ZERO) {}

inline
Surface::Surface(string name, Vec3 color)
    : name(name), color(color) {}

inline
ostream& operator<<(ostream& os, const Surface& s)
{
    os << "Surface("
        << s.name
        << ","
        << s.color
        << ")";
    return os;
}
