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
    unordered_map<string, Surface>* surface_map;
    vector<Sphere> sphere_vec;
    Screen look_screen;
    Light amb_light;
    vector<Light> light_vec;
*/

// Construct the global data struct with default values
G::G() : eyep(0, -8, 0),
maxdepth(15),
lookp(0, 0, 0),
up(0, 0, 1),
fov{45, 45},
cutoff(.002),
surface_map(0),
amb_light(Light(1,Vec3(1, -1, 1 ))
{}