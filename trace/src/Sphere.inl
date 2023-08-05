#pragma once

// ===========================================================================
// Sphere.inl
// ===========================================================================

using namespace std;

#include <iostream>

#include "Sphere.hpp"

inline
string Sphere::str() const
{
    ostringstream os;
    os << "Sphere("
       << radius
       << ","
       << center
       << ","
       << color
       << ")";
    return os.str();
}

inline
ostream& operator<<(ostream& os, const Sphere& s)
{
    os << s.str();
    return os;
}
