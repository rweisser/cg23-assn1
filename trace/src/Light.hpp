#pragma once

#include "Vec3.hpp"

struct Light
{
    Light();
    Light(float intensity, Vec3 loc);

    float intensity;
    Vec3 loc;
};