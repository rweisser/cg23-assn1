// Globals.cpp

// Global data
 
/*
 * A struct to hold global data.  There will be one instance of this
 * created in Trace.cpp.
 * struct Globals
 * {
 *     static const double PI;
 *
 *     Vec3 background;  // bg color
 *     Vec3 eyep;
 *     Vec3 lookp;
 *     Vec3 up;
 *     Vec2 fov;
 *     Vec2 screen_size;
 *     Screen look_screen;
 *     vector<Sphere> sphere_vec;
 *
 *     string str() const;
 * };
 *
 * ostream& operator<<(ostream& os, const G& g);
 */

#include "Globals.hpp"
#include "Screen.hpp"

struct Screen;

const double Globals::PI = 3.141592653589793;

string Globals::str() const
{
    ostringstream oss;
    oss << "background: "  << background  << endl;
    oss << "eyep: "        << eyep        << endl;
    oss << "lookp: "       << lookp       << endl;
    oss << "up: "          << up          << endl;
    oss << "fov: "         << fov         << endl;
    oss << "look_screen: " << look_screen << endl;
    
    int i = 1;
    oss << "Objects:" << endl;
    for   (vector<Object *>::const_iterator o_iter = object_vec.cbegin();
           o_iter != object_vec.cend();
           o_iter++, i++)
        oss << i << ": " << **o_iter << endl;

    return oss.str();
}

ostream& operator<<(ostream& os, const Globals& g)
{
    os << g.str();
    return os;
}
