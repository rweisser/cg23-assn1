// G.cpp

#include "G.hpp"

/*
    Vec3 background;
    Vec3 eyep;
    Vec3 lookp;
    Vec3 up;
    Vec2 fov;
    Vec2 screen_size;
    int maxdepth;
    float cutoff;
    vector<Sphere> sphere_vec;
    Screen look_screen;
    vector<Light> light_vec;
*/

// Construct the global data struct with default values
G::G() : background(1, 1, 1), // default to white
         lookp(0, 0, 0),
         eyep(0, -8, 0),
         up(0, 1, 0),
         fov{45, 45},
         screen_size(512, 512),
         maxdepth(15),
         cutoff(.002)
         {}       