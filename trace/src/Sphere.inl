#pragma once

// ===========================================================================
// Sphere.inl
// ===========================================================================

using namespace::std;

#include "Surface.hpp"
#include "Vec3.hpp"
#include "Sphere.hpp"

inline
Sphere::Sphere(double radius, Vec3 center,
               Vec3 ambient, Vec3 diffuse, Vec3 specular,
               float specpow, float reflect)
    : radius(radius), center(center),
      ambient(ambient), diffuse(diffuse), specular(specular),
      specpow(specpow), reflect(reflect)
    {}

