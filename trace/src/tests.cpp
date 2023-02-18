// ===========================================================================
// tests.cpp
// ===========================================================================

#include "algorithm"
#include <iostream>

#include "shared_data.hpp"

void test_parse()
{
	cout << "background: " << background << endl;
	cout << "eyep: " << eyep << endl;
	cout << "lookp: " << lookp << endl;
	cout << "up: " << up << endl;
	cout << "fov: " << fov << endl;
	cout << "screen_size: " << screen_size << endl;
	// cout << endl;
	// for (auto iter = surface_map->cbegin(); iter != surface_map->cend(); iter++) {
	//	 cout << iter->first << " -> " << iter->second << endl;
	// }
	cout << endl;
	for_each(sphere_vec.cbegin(), sphere_vec.cend(), [](const Sphere& s) { cout << s << endl; });
}

void test_intersect2(Vec3& e, Vec3& d, Sphere& s)
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

void test_intersect()
{
	cout << "starting test_intersect" << endl;

	test_intersect2(
		Vec3(1, 1, 0),  // e
		Vec3(1, 0, 0),  // d
		Sphere("sph001", 1, Vec3(4, 1, 0), Vec3(0, 0, 0)) // s
	);

	test_intersect2(
		Vec3(1, 1, 0),  // e
		Vec3(1, 0, 0),  // d
		Sphere("sph001", 3, Vec3(4, 1, 0), Vec3(0, 0, 0)) // s
	);

	test_intersect2(
		Vec3(1, 1, 0),  // e
		Vec3(1, 0, 0),  // d
		Sphere("sph001", 5, Vec3(4, 1, 0), Vec3(0, 0, 0)) // s
	);

	test_intersect2(
		Vec3(1, 1, 1),  // e
		Vec3(2, 2, 2),  // d
		Sphere("sph001", sqrt(3), Vec3(3, 3, 3), Vec3(0, 0, 0)) // s
	);

	test_intersect2(
		Vec3(1, 1, 1),  // e
		Vec3(2, 2, 2),  // d
		Sphere("sph001", 0.5, Vec3(3, 3, 3), Vec3(0, 0, 0)) // s
	);

	test_intersect2(
		Vec3(1, 1, 1),  // e
		Vec3(2, 2, 2),  // d
		Sphere("sph001", 0.5, Vec3(20, 20, 20), Vec3(0, 0, 0)) // s
	);

	test_intersect2(
		Vec3(1, 1, 1),  // e
		Vec3(2, 2, 2),  // d
		Sphere("sph001", 0.5, Vec3(20, 0, 0), Vec3(0, 0, 0)) // s
	);
}

void test_cross2(const Vec3& v1, const Vec3& v2)
{
	cout << v1 << " X " << v2 << " = " << v1.cross(v2) << endl;
	cout << v2 << " X " << v1 << " = " << v2.cross(v1) << endl;
}

void test_cross()
{
	test_cross2(Vec3(1, 2, 3), Vec3(1, 1, 1));
	test_cross2(Vec3(1, 0, 0), Vec3(0, 1, 0));
	test_cross2(Vec3(1, -1, -1), Vec3(10, 11, 12));
}

