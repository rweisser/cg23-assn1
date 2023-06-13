#pragma once

// ===========================================================================
// Sphere.inl
// ===========================================================================

using namespace std;

inline
ostream& operator<<(ostream& os, const Sphere& s)
{
    os << "Sphere("
        << s.radius
        << ","
        << s.center
        << ","
        << s.color << ")";
    return os;
}
