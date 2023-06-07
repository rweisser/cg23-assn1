#pragma once

// ===========================================================================
// Screen.hpp
// ===========================================================================

using namespace std;

#include <ostream>

#include "Vec3.hpp"

// This struct is used only for the look screen.
// It contains three normalized vectors for the coordinate system
// based on the camera screen.  These vectors must be normalized before
// they are assigned to this struct.
// It also contains origin and the boundaries of the screen.
struct Screen
{
    Vec3 u;  // Unit vector pointing up from lp.
    Vec3 v;  // Unit vector pointing to right of lp.
    Vec3 w;  // Points from the center of the look screen to the eye.
    Vec3 lp; // The center of the look screen, comes from lookp in the input
             // file.
    double left, right, top, bottom; // screen bounaries
    int pixelsh, pixelsv;            // number of horiz/vert pixels

    // The default constructor initializes the numeric values.  The vectors
    // are initialized to the zero vector by the Vec3 default constructor.
    // The initialization of the one and only screen object is
    // in the init_look_function in Trace.cpp.
    Screen() { left = right = top = bottom = pixelsh = pixelsv = 0; }
};

inline
ostream& operator<<(ostream& os, const Screen& s)
{
    os << "Screen(" << endl
        << "u = " << s.u << "," << endl
        << "v = " << s.v << "," << endl
        << "w = " << s.w << "," << endl
        << "lp = " << s.lp << "," << endl
        << "left = " << s.left << ", right = " << s.right << "," << endl
        << "top = " << s.top << ", bottom = " << s.bottom << "," << endl
        << "pixelsh = " << s.pixelsh << ", pixelsv = " << s.pixelsv
        << ")" << endl;
    return os;
}
