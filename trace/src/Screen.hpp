#pragma once

// ===========================================================================
// Screen.hpp
// ===========================================================================

using namespace::std;

#include <ostream>

#include "Vec3.hpp"

// This struct is used only for the look screen.
// It contains three normalized vectors for the coordinate system
// based on the camera screen.  These vectors must be normalized before
// they are assigned to this struct.
// It also contains the boundaries of the screen.
struct Screen
{
    Vec3 u;
    Vec3 v; // 
    Vec3 w; // Points from the center of the look screen to the eye.
    double left, right, top, bottom; 
    int pixelsh, pixelsv;

    Screen() { left = right = top = bottom = pixelsh = pixelsv = 0; }
};

inline
ostream& operator<<(ostream& os, const Screen& s)
{
    os << "Screen(u = " << s.u << ", v = " << s.v << ", z = " << s.w
       << ", left = " << s.left << ", right = " << s.right
       << ", top = " << s.top << ", bottom = " << s.bottom
       << ", pixelsh = " << s.pixelsh << "pixelsv = " << s.pixelsv
       << ")"
       << endl;
    return os;
}
