		**Sample solution for CMSC 435/634 assignment 1**

Command-line Options
====================
-help		print help message

-polygons	disable polygon rendering
+polygons	enable polygon rendering (default)

-spheres	disable sphere rendering
+spheres	enable sphere rendering (default)

If the final argument starts with /, it is assumed to be an absolute path. Otherwise, it is assumed to be in the data directory


Source Files
============
* Config.h.in: used by CMake to #define base, build, and data paths

* Vec3.hpp: 3D float vector class
* Vec3.inl: Inline function implementations for Vec3

* Color.hpp: unsigned char color class

* Trace.cpp: main program, including argument parsing, loop over pixels, and ppm output

* World.hpp, World.cpp: parse ray file and collect information about the world

* Ray.hpp, Ray.cpp: Ray object with start point and direction

* Object.hpp, Object.cpp: Base class for all objects, includes color and virtual intersection function

* Sphere.hpp, Sphere.cpp: Sphere object derived from Object base class

* Polygon.hpp, Polygon.cpp: Polygon object derived from Object base class

* ObjectList.hpp, ObjectList.cpp: list of objects in the world, includes trace function that loops over all objects for one ray and returns the color of the closest one.


.ray Format Data Files
======================

* balls.ray: 
	Result of running standard procedural database balls generator at default settings:
		balls -r 8
	7381 spheres with a common reflective material
	1 polygon base plane

* balls3.ray
	SPD balls generator at level 3
		balls -s 3 -r 8
	820 spheres with a common reflective material
	1 polygon base plane

* balls3-color.ray
	balls3 post-processed to have a different random diffuse color per sphere
	Useful for telling if the ray ordering is correct

* balls3-cases.ray
	balls3-color with a manually added enclosing sphere and one behind the viewer

* balls3-twist.ray
	balls3-color with the look point moved up in z, and up vector twisted enough to make the orange sphere line up vertically above the large green sphere

* test1x1.ray
	Simple hand-written test file with one sphere

* gears2.ray
	SPD gears generator at level 2
		gears -s 2 -r 8
	1169 polygons with 9 materials
	Most of the polygons are 4-vertex quads, but 16 of them (tops and bottoms of each gear) are 114-vertex concave polygons.
