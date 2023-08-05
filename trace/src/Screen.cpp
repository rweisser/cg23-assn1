// Screen.cpp

/*
 * struct Screen
 * {
 * 	Screen();
 * 	void init(const Globals& g);
 * 	Vec3 pixel_center(Vec3& eyep, double d, int x, int y) const;
 * 	string str() const;
 * 
 * 	Vec3 u;  // Unit vector pointing up from lp.
 * 	Vec3 v;  // Unit vector pointing to right of lp.
 * 	Vec3 w;  // Points from the center of the look screen to the eye.
 * 	Vec3 lp; // The center of the look screen, comes from lookp in the input
 * 			 // file.
 * 	double left, right, top, bottom; // screen bounaries
 * 	int pixelsh, pixelsv;            // number of horiz/vert pixels
 * };
 */

#include "Globals.hpp"
#include "Screen.hpp"

// The default constructor initializes the numeric values.  The vectors
// are initialized to the zero vector by the Vec3 default constructor.
// The initialization of the one and only screen object is
// in the init function.
Screen::Screen()
	: left(0),
	  right(0),
	  top(0),
	  bottom(0),
	  pixelsh(0),
	  pixelsv(0)
{}

void Screen::init(const Globals& g)
{
	Vec3 wtemp = g.eyep - g.lookp;
	double d = wtemp.mag();
	w = wtemp.normalize();
	u = g.up.cross(w).normalize();
	v = w.cross(u);

	// Horizontal fov
	int degrees = g.fov.x;
	double theta = degrees * Globals::PI / 180;
	right = d * tan(theta / 2);
	left = -right;

	// Vertical fov
	degrees = g.fov.y;
	theta = degrees * Globals::PI / 180;
	top = d * tan(theta / 2);
	bottom = -top;

	pixelsh = g.screen_size.x;
	pixelsv = g.screen_size.y;
}

// returns center of the pixel at (x, y).
// eyep is the camera position.
// d is the distance from eyep to lookp.
// x and y are the screen coordinates.
Vec3 Screen::pixel_center(const Vec3& eyep, double d, int x, int y) const
{
	double screen_u = left + (right - left) * (x + 0.5) / pixelsh;
	double screen_v = top + (bottom - top) * (y + 0.5) / pixelsv;

	return eyep - d * w + u * screen_u + v * screen_v;	
}
