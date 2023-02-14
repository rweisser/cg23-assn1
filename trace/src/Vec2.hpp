#pragma once

// ===========================================================================
// Vec2 - Two dimensional vectors.  Header.
// 
// Everything is inline for speed.  The coordinates x any y are public
// for convenience.  The implementation file is Vec2Inline.h.  There is
// no Vec2.cpp file.
// ===========================================================================

using namespace std;

#include <string>
#include <iostream>
#include <utility>

struct Vec2
{
	double x, y;

	static const Vec2 Vec2_ZERO;        // zero vector

	Vec2();
	Vec2(double x, double y);
	Vec2(const Vec2& v);

	template<class T1, class T2>
	Vec2(const pair<T1, T2>& p);        // construct from pair

	Vec2& operator=(const Vec2& v);

	double norm() const;                // Euclidean norm
	double r() const;                   // radius (polar), same as norm
	double angle(const Vec2& v) const;  // angle in radians with other vector
	double mag() const;                 // magnitude, same as norm
	double theta() const;               // theta (polar)
	string str() const;                 // stringify
	double dot(const Vec2& v) const;    // dot product
	Vec2 normalize() const;             // change to length 1

	bool operator==(const Vec2& v) const;
	Vec2& operator+=(const Vec2& v);
	Vec2 operator-() const;
	Vec2& operator-=(const Vec2& v);
}; // Vec2

Vec2 operator+(Vec2 v1, const Vec2& v2);         // vector addition  
Vec2 operator-(Vec2 v1, const Vec2& v2);         // vector substraction
Vec2 operator*(double k, const Vec2& v);         // scalar multiplication
Vec2 operator*(const Vec2& v, double k);         // scalar multiplication
Vec2 operator/(const Vec2& v, double k);         // scalar division
ostream& operator<<(ostream& os, const Vec2& v); // output as string

// ===========================================================================
// Include the implementation of the online and template functions.
// ===========================================================================
#include "Vec2.inl"
