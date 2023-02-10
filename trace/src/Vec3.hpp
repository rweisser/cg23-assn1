#pragma once

// ===========================================================================
// Vec3 - Three dimensional vectors.  Header.
// 
// Everything is inline for speed.  The coordinates x, y any z are public
// for convenience.  The implementation file is Vec3Inline.h.  There is
// no Vec3.cpp file.
// ===========================================================================

#include <iostream>
#include <string>
#include <tuple>
using namespace std;

struct Vec3
{
	double x, y, z;

	static const Vec3 Vec3_ZERO;        // zero vector

	Vec3();
	Vec3(double x, double y, double z);
	Vec3(const Vec3& v);

	template<class T1, class T2, class T3>
	Vec3(const tuple<T1, T2, T3>& t);   // construct from tuple

	Vec3& operator=(const Vec3& v);

	double norm() const;                // Euclidean norm
	double angle(const Vec3& v) const;  // angle in radians with other vector
	double mag() const;                 // magnitude, same as norm
	double dot(const Vec3& v) const;    // dot product
	Vec3 cross(const Vec3& v) const;    // cross product
	Vec3 normalize() const;             // change length to 1
	string str() const;                 // stringify

	bool operator==(const Vec3& v) const;
	Vec3& operator+=(const Vec3& v);
	Vec3 operator-() const;
	Vec3& operator-=(const Vec3& v);
}; // Vec3

const Vec3 Vec3::Vec3_ZERO(0, 0, 0);

Vec3 operator+(Vec3 v1, const Vec3& v2);         // vector addition  
Vec3 operator-(Vec3 v1, const Vec3& v2);         // vector substraction
Vec3 operator*(double k, const Vec3& v);         // scalar multiplication
Vec3 operator*(const Vec3& v, double k);         // scalar multiplication
Vec3 operator/(const Vec3& v, double k);         // scalar division
ostream& operator<<(ostream& os, const Vec3& v); // output as string
string ToString(const Vec3& v);                  // stringify for test
                                                 //     framework

// ===========================================================================
// Include the implementation of the online and template functions.
// ===========================================================================
#include "Vec3Inline.h"
