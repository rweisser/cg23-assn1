#pragma once

#include <iostream>

#include "Vec3.hpp"

struct Light
{
    Light();
    Light(float intensity, Vec3 loc);

    float intensity;
    Vec3 pos; // position of light source

    string str() const;
};

ostream& operator<<(ostream& os, const Light& l);
