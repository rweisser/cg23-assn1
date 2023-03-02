// G.cpp

#include <algorithm>

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
    Screen look_screen;
    vector<Sphere> sphere_vec;
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

ostream& operator<<(ostream& os, const G& g)
{
    cout << "background: " << g.background << endl;
    cout << "eyep: " << g.eyep << endl;
    cout << "lookp: " << g.lookp << endl;
    cout << "up: " << g.up << endl;
    cout << "fov: " << g.fov << endl;
    cout << "screen_size: " << g.screen_size << endl;
    cout << "max_depth: " << g.maxdepth << endl;
    cout << "cutoff: " << g.cutoff << endl;
    cout << "look_screen: " << g.look_screen << endl;
    int i = 1;
    cout << "Spheres:" << endl;
    for (vector<Sphere>::const_iterator s_iter = g.sphere_vec.cbegin();
            s_iter != g.sphere_vec.cend();
            s_iter++, i++)
        cout << i << ": " << *s_iter << endl;
    cout << "Lights:" << endl;
    for_each(g.light_vec.cbegin(), g.light_vec.cend(), [](const Light& l) { cout << l << endl; });

    return os;
}
