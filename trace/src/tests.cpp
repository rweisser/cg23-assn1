// Tests.cpp

// Tests for this project

#include <algorithm>

#include "Tests.hpp"

Tests::Tests(const Globals& g) : g(g) {}

void Tests::test_parse()
{
	cout << g.str() << endl;
}

void Tests::test_intersect()
{
	cout << "starting test_intersect" << endl;

	test_intersect2(
		Vec3(1, 1, 0),  // e
		Vec3(1, 0, 0),  // d
		Sphere(1, Vec3(4, 1, 0), Vec3(0, 0, 0)) // s
	);

	test_intersect2(
		Vec3(1, 1, 0),  // e
		Vec3(1, 0, 0),  // d
		Sphere(3, Vec3(4, 1, 0), Vec3(0, 0, 0)) // s
	);

	test_intersect2(
		Vec3(1, 1, 0),  // e
		Vec3(1, 0, 0),  // d
		Sphere(5, Vec3(4, 1, 0), Vec3(0, 0, 0)) // s
	);

	test_intersect2(
		Vec3(1, 1, 1),  // e
		Vec3(2, 2, 2),  // d
		Sphere(sqrt(3), Vec3(3, 3, 3), Vec3(0, 0, 0)) // s
	);

	test_intersect2(
		Vec3(1, 1, 1),  // e
		Vec3(2, 2, 2),  // d
		Sphere(0.5, Vec3(3, 3, 3), Vec3(0, 0, 0)) // s
	);

	test_intersect2(
		Vec3(1, 1, 1),  // e
		Vec3(2, 2, 2),  // d
		Sphere(0.5, Vec3(20, 20, 20), Vec3(0, 0, 0)) // s
	);

	test_intersect2(
		Vec3(1, 1, 1),  // e
		Vec3(2, 2, 2),  // d
		Sphere(0.5, Vec3(20, 0, 0), Vec3(0, 0, 0)) // s
	);
}

void Tests::test_intersect2(Vec3& e, Vec3& d, Sphere& s)
{
	cout << endl;
	cout << "e = " << e << ", d = " << d << ", s = " << s << endl;
	double t1 = -1000000, t2 = -1000000;
	bool res = s.intersect(e, d, t1, t2);
	cout << "length of d - e is " << (d - e).mag() << endl;
	cout << "result = " << res
		<< ", t1 = " << t1
		<< ", t2 = " << t2 << endl;
	cout << "color = " << s.color << endl;
}

void Tests::test_cross()
{
	test_cross2(Vec3(1, 2, 3), Vec3(1, 1, 1));
	test_cross2(Vec3(1, 0, 0), Vec3(0, 1, 0));
	test_cross2(Vec3(1, -1, -1), Vec3(10, 11, 12));
}

void Tests::test_cross2(const Vec3& v1, const Vec3& v2)
{
	cout << v1 << " X " << v2 << " = " << v1.cross(v2) << endl;
	cout << v2 << " X " << v1 << " = " << v2.cross(v1) << endl;
}

void Tests::test_pixel_center()
{
	double d = (g.eyep - g.lookp).mag();
	cout << "g.eyep.mag() = " << g.eyep.mag() << endl;
	cout << "d = " << d << endl;
	cout << "g.eyep - d * w = " << g.eyep - d * g.look_screen.w << endl;
	test_pixel_center2(d, 0, 0);
	test_pixel_center2(d, 511, 0);
	test_pixel_center2(d, 0, 511);
	test_pixel_center2(d, 511, 511);
	test_pixel_center2(d, 127, 127);
}

void Tests::test_pixel_center2(double d, int x, int y)
{
	cout << x << " " << y << " -> "
		 << g.look_screen.pixel_center(g.eyep, d, x, y)
		 << endl;
}
