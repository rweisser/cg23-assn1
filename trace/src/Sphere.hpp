#pragma once

// ===========================================================================
// Sphere.hpp
// ===========================================================================

using namespace std;

#include "Object.hpp"

struct Sphere : Object
{
    double radius;
    Vec3 center;
    // Vec3 color;  // inherited from Object

    Sphere(double radius, Vec3 center, Vec3 color);
    virtual ~Sphere();

    bool intersect(const Vec3& e, const Vec3& d,
                   double &t1, double &t2) const;
    virtual double intersect(const Ray& ray) const override;
    virtual string str() const;
};

ostream& operator<<(ostream& os, const Sphere& s);

#include "Sphere.inl"
