// ===========================================================================
// Sphere.cpp
// ===========================================================================

/*
 * struct Sphere : Object
 * {
 *     // Vec3 color;  // inherited from Object
 *
 *     double radius;
 *     Vec3 center;
 *
 *     Sphere();
 *     Sphere(double radius, Vec3 center, Vec3 color);
 *     virtual ~Sphere();
 *
 *     bool intersect(const Vec3& e, const Vec3& d,
 *         double& t1, double& t2) const;
 *     virtual double intersect(const Ray& ray) override;
 * };
 *
 * ostream& operator<<(ostream& os, const Sphere& s);
 */

using namespace std;

#include "Sphere.hpp"

#include "Ray.hpp"

Sphere::Sphere(double radius, Vec3 center, Vec3 color)
    : Object(color), radius(radius), center(center)
{}

Sphere::~Sphere() {}

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

// If the ray hits the sphere, intersect returns the distance to the sphere.
// If ray.start is inside the sphere, it returns the distance to the
// sphere in the direction (ray.dir) of the ray.  If the ray hits the sphere in
// two places, it returns the closest one.  If the ray misses the sphere
// altogether, it returns INFINITY.
double Sphere::intersect(const Ray& ray) const
{
    //static int n = 0; // XXX

    Vec3 g = ray.start - center; // distance from eye to sphere
    Vec3 d = ray.dir;
    double discriminant =
        d.dot(g) * d.dot(g) - d.dot(d) * (g.dot(g) - radius * radius);
    if (discriminant < 0) // ray missed the sphere
        return INFINITY;

    //cout << "XXX n = " << ++n << endl;
    //cout << "XXX non-negative discriminant = " << discriminant << endl;
    //cout << "XXX ray = " << ray << endl;
    //cout << "XXX sphere = " << *this << endl;
    
    // Check closer distance (subtract the discriminant).
    double distance = ((-d).dot(g) - sqrt(discriminant)) / d.dot(d);
    //cout << "XXX distance1 = " << distance << endl;
    if (distance > Vec3::TOLERANCE) // ray hit near side of sphere
        return distance;
    // If here, the closer distance was negative (or too close) so check
    // the other distance.
    distance = ((-d).dot(g) + sqrt(discriminant)) / d.dot(d);
    //cout << "XXX distance2 = " << distance << endl;
    if (distance > Vec3::TOLERANCE) // ray hit far side of sphere
        return distance;
    //cout << "XXX no hit" << endl;
    return INFINITY; // sphere is behind the eye
}
