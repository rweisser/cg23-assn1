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
// It also contains origin and the boundaries of the screen.
// A pixel center at (x, y) on the screen is found by the expression
// lp + (x + 0.5 / screen_size.x) * v 
struct Screen
{
    Vec3 u;  // Unit vector pointing up from lp.
    Vec3 v;  // Unit vector pointing to right of lp.
    Vec3 w;  // Points from the center of the look screen to the eye.
    Vec3 lp; // The center of the look screen, comes from lookp in the input
             // file.
    double left, right, top, bottom; 
    int pixelsh, pixelsv;

    // The default constructor initializes the numeric values.  The vectors
    // are initialized to the zero vector by the Vec3 default constructor.
    // The useful initialization of the one and only screen object is
    // in the init_look_function in Trace.cpp.
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
