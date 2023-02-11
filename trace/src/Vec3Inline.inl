#pragma once

// ===========================================================================
// Vec3 - Three dimensional vectors.  Implementation of inline functions.
// 
// All member functions are inline for speed.  The coordinates x, y any z
// are public for convenience.
// ===========================================================================

#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <tuple>
using namespace std;

inline
Vec3::Vec3() : x(0), y(0), z(0) {}

inline
Vec3::Vec3(double x, double y, double z) : x(x), y(y), z(z) {}

inline
Vec3::Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}

template<class T1, class T2, class T3>
Vec3::Vec3(const tuple<T1, T2, T3>& t)
	: x(get<0>(t)), y(get<1>(t)), z(get<2>(t)) {}

inline
Vec3& Vec3::operator=(const Vec3& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}

template<class T1, class T2, class T3>
Vec3& Vec3::operator=(const tuple<T1, T2, T3>& t)
{
	x = get<0>(t);
	y = get<1>(t);
	z = get<2>(t);
	return *this;
}

// Euclidean norm
inline
double Vec3::norm() const
{
	return sqrt(x * x + y * y + z * z);
}

// the angle between two vectors (in radians)
inline
double Vec3::angle(const Vec3& v) const
{
	if (*this == Vec3_ZERO || v == Vec3_ZERO)
		throw invalid_argument("zero vector");
	return acos((dot(v)) / (norm() * v.norm()));
}

// magnitude, same as norm
inline
double Vec3::mag() const
{
	return norm();
}

// dot product
inline
double Vec3::dot(const Vec3& v) const
{
	return x * v.x + y * v.y + z * v.z;
}

// cross product
inline
Vec3 Vec3::cross(const Vec3& v) const
{
	return Vec3( (y * v.z - z * v.y),
		    // - (x * v.z - z * v.x),
		         (z * v.x - x * v.z),
		         (x * v.y - y * v.x) );
}

// normalize - change length to 1
inline
Vec3 Vec3::normalize() const
{
}

inline
string Vec3::str() const
{
	ostringstream oss;
	oss << "Vec3(" << x << "," << y << "," << z << ")";
	return oss.str();
}

inline
bool Vec3::operator==(const Vec3& v) const
{
	return x == v.x && y == v.y && z == v.z;
}

inline
Vec3& Vec3::operator+=(const Vec3& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

inline
Vec3 Vec3::operator-() const
{
	return Vec3(-x, -y, -z);
}

inline
Vec3& Vec3::operator-=(const Vec3& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

inline
Vec3 operator+(Vec3 v1, const Vec3& v2)
{
	return Vec3(v1) += v2;
}

inline
Vec3 operator-(Vec3 v1, const Vec3& v2)
{
	return Vec3(v1) -= v2;
}

// ===========================================================================
// Vec3 non-member functions
// ===========================================================================


inline
Vec3 operator*(double k, const Vec3& v)
{
	return Vec3(v.x * k, v.y * k, v.z * k);
}

inline
Vec3 operator*(const Vec3& v, double k)
{
	return k * v;
}

inline
Vec3 operator/(const Vec3& v, double k)
{
	return v * (1 / k);
}

inline
ostream& operator<<(ostream& os, const Vec3& v)
{
	os << v.str();
	return os;
}

inline
string ToString(const Vec3& v)
{
	return v.str();
}
