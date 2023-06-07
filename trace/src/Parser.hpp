#pragma once

// ===========================================================================
// Parser.hpp

// A parser for ray trace files
// ===========================================================================

using namespace std;

#include <cerrno>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

#include "Globals.hpp"

class Parser
{
    string   file_name;   // name of ray trace file
    ifstream ray_file;    // ray trace file
    unordered_map<string, Surface> surface_map;

    void parse_vec2(Vec2& v);
    void parse_vec3(Vec3& v);
    void parse_sphere();
    void parse_surface();
    void read_file();

public:

    // Parse the ray trace file into variables in g, which
    // contains global variables.  Since g is a reference, the
    // changes will be there after the Parser object is gone.
    void parse_file(const string& file_name);
};
