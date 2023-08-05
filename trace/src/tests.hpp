#pragma once

// Tests.hpp

// Tests for this project

#include "Globals.hpp"

struct Tests
{
    const Globals& g;

    Tests(const Globals& g);
    void test_parse();
    void test_intersect();
    void test_cross();
    void test_pixel_center();

private:
    void test_intersect2(Vec3& e, Vec3& d, Sphere& s);
    void test_cross2(const Vec3& v1, const Vec3& v2);
    void test_pixel_center2(double d, int x, int y);
};
