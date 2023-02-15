#pragma once

// ===========================================================================
// Vec3 - Three dimensional vectors.  Header.
// 
// Everything is inline for speed.  The coordinates x, y any z are public
// for convenience.  The implementation file is Vec3Inline.h.  Vec3.cpp
// just defines Vec3::VEC_ZERO.
// 
// Vec3 holds a vector or a color.
// ===========================================================================

using namespace std;

#include <iostream>
#include <string>
#include <tuple>

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

	template<class T1, class T2, class T3>
	Vec3& operator=(const tuple<T1, T2, T3>& t); // assignment from tuple

	double norm() const;                // Euclidean norm
	double angle(const Vec3& v) const;  // angle in radians with other vector
	double mag() const;                 // magnitude, same as norm
	double dot(const Vec3& v) const;    // dot product
	Vec3 cross(const Vec3& v) const;    // cross product
	Vec3 normalize() const;             // change length to 1
	string str() const;                 // stringify

	Vec3 operator*(double k) const;     // scalar multiplication
	bool operator==(const Vec3& v) const;
	Vec3& operator+=(const Vec3& v);
	Vec3 operator-() const;
	Vec3& operator-=(const Vec3& v);

	// To avoid confusion when using a vector to represent the look screen,
	// I added the following so that I can use u, v, and w instead of
	// x, y, and z.
	int  u() const   { return x; }
	void u(double u) { x = u; }
	int  v() const   { return y; }
	void v(double v) { y = v; }
	int  w() const   { return z; }
	void w(double w) { z = w; }
}; // Vec3

Vec3 operator+(Vec3 v1, const Vec3& v2);         // vector addition  
Vec3 operator-(Vec3 v1, const Vec3& v2);         // vector substraction
Vec3 operator*(double k, const Vec3& v);         // scalar multiplication
Vec3 operator/(const Vec3& v, double k);         // scalar division
ostream& operator<<(ostream& os, const Vec3& v); // output as string
string ToString(const Vec3& v);                  // stringify for test
                                                 //     framework

// ===========================================================================
// Include the implementation of the online and template functions.
// ===========================================================================
#include "Vec3.inl"
