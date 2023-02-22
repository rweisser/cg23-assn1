// sphere objects
#pragma once

// other classes we use DIRECTLY in the interface
#include "Object.hpp"
#include "Vec3.hpp"

// sphere objects
class Sphere : public Object {
    Vec3 C;
    float R;

    // derived, for intersection testing
    float Rsquared;

public: // constructors
    Sphere(const Vec3 color, const Vec3 center, float radius);

public: // object functions
    float intersect(const Ray &ray) const override;
};
