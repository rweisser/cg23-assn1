#pragma once

// ===========================================================================
// Vec3 - Three dimensional vectors.  Implementation.
// 
// Everything is inline for speed.  The coordinates x, y any z are public
// for convenience.  The implementation file is Vec3Inline.h.  Vec3.cpp
// just defines Vec3::VEC_ZERO.
// 
// Vec3 holds a vector or a color.
// ===========================================================================

using namespace std;

#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <tuple>

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
	if (*this == Vec3::Vec3_ZERO)
		return Vec3::Vec3_ZERO;
	return *this / mag();
}

inline
string Vec3::str() const
{
	ostringstream oss;
	oss << "Vec3(" << x << "," << y << "," << z << ")";
	return oss.str();
}

inline
Vec3 Vec3::operator*(double k) const
{
	return Vec3(x * k, y * k, z * k);
}

inline
bool Vec3::operator==(const Vec3& v) const
{
	return x == v.x && y == v.y && z == v.z;
}

inline
bool Vec3::equalt(const Vec3& v) const
{
	// I used the following instead of
	//     return (*this - v).map < TOLERANCE;
	// to avoid allocating a Vec3 object.  It also
	// avoids using the sqrt function.
	return (x - v.x) * (x - v.x)
		 + (y - v.y) * (y - v.y)
		 + (z - v.z) * (z - v.z)
		 < TOLERANCE * TOLERANCE;
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
	return v * k;
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
