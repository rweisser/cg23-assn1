// Object.cpp

#include "Object.hpp"
#include "Vec3.hpp"

Object::Object(Vec3 color) : color(color) {}

Object::~Object() {}

ostream& operator<<(ostream& os, const Object& o)
{
    os << o.str();
    return os;
}