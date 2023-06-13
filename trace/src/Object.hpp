#pragma once

// Object.hpp

// ===========================================================================
// Base class for screen objects
// ===========================================================================

#include "Ray.hpp"
#include "Vec3.hpp"

struct Object
{
    Object(Vec3 color);
    Object(const Object& o) = delete;
    Vec3& operator=(const Object& o) = delete;
    virtual ~Object();

    Vec3 color;

    virtual double intersect(Ray r) = 0;
};
