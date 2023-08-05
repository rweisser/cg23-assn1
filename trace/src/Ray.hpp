#pragma once

// Ray.hpp

#include <Vec3.hpp>

struct Ray
{
    Vec3 start;    // start of ray
    Vec3 dir;      // direction or ray

    Ray(Vec3 start, Vec3 dir);
    string str() const;
};

ostream& operator<<(ostream& os, const Ray& r);
