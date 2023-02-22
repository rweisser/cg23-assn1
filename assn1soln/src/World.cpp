// implementation code for World object
// World holds everything we know about the world.
// Code here initializes it based on file input

#include "World.hpp"
#include "Polygon.hpp"
#include "Sphere.hpp"
#include "Vec3.inl"
#include <math.h>
#include <istream>
#include <iostream>
#include <string>
#include <map>

// scoped global for what is enabled
World::Features World::enables;

// feature defaults
World::Features::Features()
{
    spheres = polygons = true;
}

// read input file
World::World(std::istream &ifile)
: eye(0,-8,0), width(512), height(512)
{
    int SphereCount = 0, PolyCount = 0;

    // temporary variables while parsing
    Vec3 look(0,0,0), up(0,1,0);
    float xfov=45, yfov=45;
    std::string surfname;

    // map of surface names to colors, only need while parsing
    std::map<std::string, Vec3> surfaceMap;
    Vec3 *currentColor = &surfaceMap[""];

    // parse file one token at a time
    std::string token;
    ifile >> token;
    while(! ifile.eof()) {
        if (token == "background")
            ifile >> objects.background[0] >> objects.background[1] >> objects.background[2];
        else if (token == "eyep")
            ifile >> eye[0] >> eye[1] >> eye[2];
        else if (token == "lookp")
            ifile >> look[0] >> look[1] >> look[2];
        else if (token == "up")
            ifile >> up[0] >> up[1] >> up[2];
        else if (token == "fov")
            ifile >> xfov >> yfov;
        else if (token == "screen")
            ifile >> width >> height;

        else if (token == "surface") {
            ifile >> surfname;
            currentColor = &surfaceMap[surfname];
        }

        else if (token == "diffuse")
            ifile >> (*currentColor)[0] >> (*currentColor)[1] >> (*currentColor)[2];

        else if (enables.polygons && (token == "polygon" || token == "triangle")) {
            ifile >> surfname;
            Polygon *poly = new Polygon(surfaceMap[surfname]);
            Vec3 vert;
            try { // read until stof throws on non-numeric token
                while(! ifile.eof()) {
                    ifile >> token; vert[0] = std::stof(token);
                    ifile >> token; vert[1] = std::stof(token);
                    ifile >> token; vert[2] = std::stof(token);
                    
                    if (ifile.eof()) break;
                    poly->addVertex(vert);
                }
            }
            catch(...) {}
            poly->closePolygon();
            objects.addObject(poly);
            ++PolyCount;

            // have an unused non-numeric token
            // skip token read at end of loop to process next iteration
            continue;
        }

         else if (enables.spheres && token == "sphere") {
            float radius;
            Vec3 center;
            ifile >> surfname >> radius >> center[0] >> center[1] >> center[2];
            objects.addObject(new Sphere(surfaceMap[surfname], center, radius));
            ++SphereCount;
        }

        ifile >> token;
    }

    // compute view basis
    w = eye - look;
    dist = length(w);
    w = normalize(w);
    u = normalize(cross(up, w));
    v = cross(w, u);

    // solve for screen edges
    right = dist * tanf(xfov * 3.1415926536f/360);
    left = -right;
    top = dist * tanf(yfov * 3.1415926536f/360);
    bottom = -top;

    // report loading stats
    std::cout << objects.size() << " Objects (" 
        << SphereCount << " Sphere" << (SphereCount == 1 ? "" : "s") << ", " 
        << PolyCount << " Polygon" << (PolyCount == 1 ? "" : "s") << ")\n";   
}
