// Everything we know about the world
#pragma once

// other classes we use DIRECTLY in our interface
#include "Vec3.hpp"
#include "ObjectList.hpp"
#include <fstream>

class World {
public: // public data
    // feature flags
    struct Features {
        bool spheres : 1;
        bool polygons : 1;

        Features();
    };
    static Features enables;

    // image size
    int width, height;

    // view origin and basis parameters
    Vec3 eye, w, u, v;
    float dist, left, right, bottom, top;


    // list of objects in the scene
    ObjectList objects;

public:                                 
    // constructor: read world data from a file
    World(std::istream &ifile); 
};
