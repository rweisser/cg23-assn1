// ===========================================================================
// Sphere.cpp
// ===========================================================================

using namespace std;

#include "Sphere.hpp"

Sphere::Sphere(double radius, Vec3 center, Vec3 color)
    : Object(color), radius(radius), center(center)
{
    /* empty */
}

Sphere::~Sphere()
{
    /* empty */
}

// ===========================================================================
// Sphere::intersect
// 
// Returns true if the ray from e in the direction d intersects this,
// otherwise false.  If true, the two values of t  will go into t1 and t2,
// with the lowest in t1.  Either t1 or t2 might be negative.
// If false, t1 and t2 will be unchanged.
// ===========================================================================
bool Sphere::intersect(const Vec3& e, const Vec3& d, double& t1, double& t2) const
{
    Vec3 g = e - center;
    double discriminant = 
        d.dot(g) * d.dot(g) - d.dot(d) * (g.dot(g) - radius * radius);
    if (discriminant < 0)
        return false;
    t1 = ((-d).dot(g) - sqrt(discriminant)) / d.dot(d);
    t2 = ((-d).dot(g) + sqrt(discriminant)) / d.dot(d);
    return true;
}

double Sphere::intersect(const Ray& ray) { return 0; }
