// Screen.inl

using namespace std;

#include <iostream>

#include "Screen.hpp"

// Output of Screen object
inline
string Screen::str() const
{
    ostringstream os;
    os << "Screen(" << endl
        << "    u = " << u << "," << endl
        << "    v = " << v << "," << endl
        << "    w = " << w << "," << endl
        << "    lp = " << lp << "," << endl
        << "    left = " << left << ", right = " << right << "," << endl
        << "    top = " << top << ", bottom = " << bottom << "," << endl
        << "    pixelsh = " << pixelsh << ", pixelsv = " << pixelsv
        << ")" << endl;
    return os.str();
}

inline
ostream& operator<<(ostream& os, const Screen& s)
{
    os << s.str();
    return os;
}