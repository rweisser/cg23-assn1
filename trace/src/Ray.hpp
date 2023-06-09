#pragma once

// Ray.hpp

struct Ray
{
    double start;    // start of ray
    double dir;      // direction or ray

    Ray(double start, double dir) : start(start), dir(dir) {}
};
