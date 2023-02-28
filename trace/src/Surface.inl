#pragma once

// ===========================================================================
// Surface.inl
// ===========================================================================

using namespace::std;

#include "Vec3.hpp"

inline
Surface::Surface()
    : name(""), specpow(0), reflect(0) {}

inline
Surface::Surface(string name, Vec3 ambient, Vec3 diffuse, Vec3 specular,
                 float specpow = 0, float reflect = 0)
    : name(name), ambient(ambient), diffuse(diffuse), specular(specular),
      specpow(specpow), reflect(reflect) {}

inline
ostream& operator<<(ostream& os, const Surface& s)
{
    os << "Surface("
        << s.name
        << ","
        << s.diffuse
        << ")";
    return os;
}
