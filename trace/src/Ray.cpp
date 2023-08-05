// Ray.cpp

#include<iostream>

#include "Ray.hpp"

Ray::Ray(Vec3 start, Vec3 dir) : start(start), dir(dir) {}

string Ray::str() const
{
    ostringstream oss;
    oss << "Ray("
        << start
        << ","
        << dir
        << ")";
    return oss.str();
}

ostream& operator<<(ostream& os, const Ray& r)
{
    os << r.str();
    return os;
}