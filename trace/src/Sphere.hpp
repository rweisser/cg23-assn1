#pragma once

// ===========================================================================
// Sphere.hpp
// ===========================================================================

using namespace::std;

#include "Vec3.hpp"

struct Sphere
{
    // XXX string surface_name; // the surface supplies the color
    double radius;
    Vec3   center;
    Vec3   ambient;   // ambient color
    Vec3   diffuse;   // diffuse color
    Vec3   specular;  // specular color
    float  specpow;   // specular hightlight exponent
    float  reflect;   // reflectivity

    Sphere(double radius, Vec3 center,
           Vec3 ambient, Vec3 diffuse, Vec3 specular,
           float specpow, float reflect);

    bool intersect(const Vec3& e, const Vec3& d,
                   double &t1, double &t2) const;
    string str() const;
};

ostream& operator<<(ostream& os, const Sphere& s);

#include "Sphere.inl"
