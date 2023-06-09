#pragma once

// Object.hpp

// ===========================================================================
// Base class for screen objects
// ===========================================================================

#include "Ray.hpp"
#include "Vec3.hpp"

struct Object
{
    Vec3 color;

    Object(Vec3 color) : color(color) {}
    Object(const Object& o) = delete;
    Vec3& operator=(const Object& o) = delete;
    virtual ~Object() {};

    virtual double intersect(Ray r) = 0;
};
