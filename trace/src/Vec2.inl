#pragma once

// ===========================================================================
// Vec2 - Two dimensional vectors.  Implementation of inline functions.
// 
// Everything is inline for speed.  The coordinates x any y are public
// for convenience.
// ===========================================================================

using namespace std;

#include <cmath>
#include <iostream>
#include <utility>
#include <stdexcept>
#include <string>
#include <sstream>

inline
Vec2::Vec2() : x(0), y(0) {}

inline
Vec2::Vec2(double x, double y) : x(x), y(y) {}

inline
Vec2::Vec2(const Vec2& v) : x(v.x), y(v.y) {}

template<class T1, class T2>
Vec2::Vec2(const pair<T1, T2>& p)
	: x(p.first), y(p.second) {}

inline
Vec2& Vec2::operator=(const Vec2& v)
{
	x = v.x;
	y = v.y;
	return *this;
}

// Euclidean norm
inline
double Vec2::norm() const
{
	return sqrt(x * x + y * y);
}

// radius (polar coordinate), same as norm
inline
double Vec2::r() const
{
	return norm();
}

// the angle between two vectors (in radians)
inline
double Vec2::angle(const Vec2& v) const
{
	if (*this == Vec2_ZERO || v == Vec2_ZERO)
		throw invalid_argument("zero vector");
	return acos((dot(v)) / (norm() * v.norm()));
}

// magnitude, same as norm
inline
double Vec2::mag() const
{
	return norm();
}

// theta (polar coordinate).  When y is negative, theta is returned
// as negative.  I'm not sure if this is right.
inline
double Vec2::theta() const
{
	// Get angle between *this and a vector along the x-axis.
	double a = angle(Vec2(1, 0));
	return y < 0 ? -a : a;
}

// dot product
inline
double Vec2::dot(const Vec2& v) const
{
	return x * v.x + y * v.y;
}

inline
Vec2 Vec2::normalize() const
{
	if (*this == Vec2::Vec2_ZERO)
		return Vec2::Vec2_ZERO;
	return *this / mag();
}

inline
string Vec2::str() const
{
	ostringstream oss;
	oss << "Vec2(" << x << "," << y << ")";
	return oss.str();
}


inline
Vec2 Vec2::operator*(double k) const
{
	return Vec2(x * k, y * k);
}

inline
bool Vec2::operator==(const Vec2& v) const
{
	return x == v.x && y == v.y;
}

inline
Vec2& Vec2::operator+=(const Vec2& v)
{
	x += v.x;
	y += v.y;
	return *this;
}

inline
Vec2 Vec2::operator-() const
{
	return Vec2(-x, -y);
}

inline
Vec2& Vec2::operator-=(const Vec2& v)
{
	x -= v.x;
	y -= v.y;
	return *this;
}

// ===========================================================================
// Vec2 non-member functions
// ===========================================================================

inline
Vec2 operator+(Vec2 v1, const Vec2& v2)
{
	return Vec2(v1) += v2;
}

inline
Vec2 operator-(Vec2 v1, const Vec2& v2)
{
	return Vec2(v1) -= v2;
}

inline
Vec2 operator*(const double k, const Vec2& v)
{
	return v * k;
}

inline
Vec2 operator/(const Vec2& v, double k)
{
	if (k == 0)
		throw invalid_argument("zero scalar divisor");

	return v * (1 / k);
}

inline
ostream& operator<<(ostream& os, const Vec2& v)
{
	os << v.str();
	return os;
}