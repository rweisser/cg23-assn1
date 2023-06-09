// Globals.cpp

// Global data

#include "Globals.hpp"

/*
 * A struct to hold global data.  There will be one instance of this
 * created in Trace.cpp.
 * struct Globals
 * {
 *     Vec3 background;  // bg color
 *     Vec3 eyep;
 *     Vec3 lookp;
 *     Vec3 up;
 *     Vec2 fov;
 *     Vec2 screen_size;
 *     Screen look_screen;
 *     vector<Sphere> sphere_vec;
 * 
 *     string str();
 * };
 * 
 * ostream& operator<<(ostream& os, const G& g);
 */

string Globals::str() const
{
    ostringstream oss;
    oss << "background: "  << background  << endl;
    oss << "eyep: "        << eyep        << endl;
    oss << "lookp: "       << lookp       << endl;
    oss << "up: "          << up          << endl;
    oss << "fov: "         << fov         << endl;
    oss << "fov: "         << fov         << endl;
    oss << "look_screen: " << look_screen << endl;
    
    int i = 1;
    oss << "Spheres:" << endl;
    for (vector<Sphere>::const_iterator s_iter = sphere_vec.cbegin();
         s_iter != sphere_vec.cend();
         s_iter++, i++)
        oss << i << ": " << *s_iter << endl;

    return oss.str();
}

ostream& operator<<(ostream& os, const Globals& g)
{
    os << g.str();
    return os;
}
