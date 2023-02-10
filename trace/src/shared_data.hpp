#pragma once

// ===========================================================================
// Shared data
// ===========================================================================

#include "Vec3.hpp"

#if defined MAIN
    #define EXTERN
#else
    #define EXTERN extern
#endif

EXTERN Vec3 background;
EXTERN Vec3 eyep;
EXTERN Vec3 lookp;
EXTERN Vec3 up;