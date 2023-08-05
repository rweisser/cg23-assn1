#pragma once

// Object.hpp

// ===========================================================================
// Abstract base class for screen objects
// ===========================================================================

#include <Vec3.hpp>

class Ray;

struct Object
{
    Vec3 color;

    Object(Vec3 color);
    virtual ~Object() = 0;

    virtual double intersect(const Ray& ray) const = 0;
    virtual string str() const = 0;
};

ostream& operator<<(ostream& os, const Object& o);
