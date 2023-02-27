// Light.cpp

#include "Light.hpp"

Light::Light() : intensity(0) {}

Light::Light(float intensity, const Vec3 loc)
    : intensity(intensity), loc(loc) {}
