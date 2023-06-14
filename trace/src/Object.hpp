#pragma once

// Object.hpp

// ===========================================================================
// Abstract base class for screen objects
// ===========================================================================

#include "Vec3.hpp"

class Ray;

struct Object
{
    Vec3 color;

    Object(Vec3 color = Vec3::Vec3_ZERO);
    virtual ~Object() = 0;

    virtual double intersect(const Ray& ray) = 0;
};
