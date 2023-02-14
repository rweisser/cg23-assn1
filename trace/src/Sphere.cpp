// ===========================================================================
// Sphere.cpp
// ===========================================================================

using namespace::std;

#include "Sphere.hpp"

// ===========================================================================
// Sphere::intersect
// 
// Returns true if the ray from e in the direction d intersects this,
// otherwise false.  If true, the two values of t, will be in t1 and t2,
// with the lowest in t1.  Either t1 or t2 might be negative.
// If false, t1 and t2 will be unchanged.
// ===========================================================================
bool Sphere::intersect(const Vec3& e, const Vec3& d, double& t1, double& t2)
{
    Vec3 g = e - center;
    double discriminant = 
        d.dot(g) * d.dot(g) - d.dot(d) * (g.dot(g) - radius * radius);
    if (discriminant < 0)
        return false;
    t1 = ((-d).dot(g) - discriminant) / d.dot(d);
    return true;
}
