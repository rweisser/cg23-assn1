#pragma once

// ===========================================================================
// Screen.hpp
// ===========================================================================

using namespace::std;

#include "Vec3.hpp"

// Screen contains three normalized vectors for the coordinate system
// based on the camera screen.  The are normalized by the constructor.
struct Screen
{
    Vec3 u, v, w;
};
