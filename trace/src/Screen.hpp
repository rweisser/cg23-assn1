#pragma once

// ===========================================================================
// Screen.hpp
// ===========================================================================

#include "Globals.hpp"
#include <Vec3.hpp>

// This struct is used only for the look screen.
// It contains three normalized vectors for the coordinate system
// based on the camera screen.  These vectors must be normalized before
// they are assigned to this struct.
// It also contains origin and the boundaries of the screen.
struct Screen
{
    Screen();
    void init(const Globals& g);
    Vec3 pixel_center(const Vec3& eyep, double d, int x, int y) const;
    string str() const;

    Vec3 u;  // Unit vector pointing up from lp.
    Vec3 v;  // Unit vector pointing to right of lp.
    Vec3 w;  // Points from the center of the look screen to the eye.
    Vec3 lp; // The center of the look screen, comes from lookp in the input
             // file.
    double left, right, top, bottom; // screen bounaries
    int pixelsh, pixelsv;            // number of horiz/vert pixels
};

ostream& operator<<(ostream& os, const Screen& s);

#include "Screen.inl"