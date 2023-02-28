// Light.cpp

#include <sstream>

#include "Light.hpp"

Light::Light() : intensity(0) {}

Light::Light(float intensity, const Vec3 pos)
    : intensity(intensity), pos(pos) {}

string Light::str() const
{
    ostringstream oss;
    oss << "Light(" << intensity << "," << pos;
    return oss.str();
}

ostream& operator<<(ostream& os, const Light& l)
{
    os << l.str();
    return os;
}