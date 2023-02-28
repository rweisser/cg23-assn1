#pragma once

// ===========================================================================
// parse.cpp
// 
// Functions to parse the input file into global variables.
// ===========================================================================

using namespace std;

#include <cerrno>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "G.hpp"
#include "Sphere.hpp"

extern G g; // global shared data

void   read_file();
void   parse_vec2(Vec2 &v);
void   parse_vec3(Vec3 &v);
void   parse_sphere();
void   parse_surface();
void   parse_light();
string next_token();

static ifstream ray_file;
unordered_map<string, Surface>* surface_map;
string push_back = ""; // token pushed backed into input stream

void parse_file(const string& file_name)
{
    ray_file.open(file_name);
    surface_map = new unordered_map<string, Surface>;
    if (!ray_file) {
        cerr << file_name << ": ";
        cerr << strerror(errno) << endl;
        exit(1);
    }
    read_file();                // process the file
    delete surface_map;
    ray_file.close();
}

void read_file()
{
    // read a keyword
    // ignore tokens we don't care about
    string token;
    token = next_token();
    while (! ray_file.eof()) {
        if (token == "background")
            parse_vec3(g.background);
        else if (token == "eyep")
            parse_vec3(g.eyep);
        else if (token == "lookp")
            parse_vec3(g.lookp);
        else if (token == "up")
            parse_vec3(g.up);
        else if (token == "fov")
            parse_vec2(g.fov);
        else if (token == "screen")
            parse_vec2(g.screen_size);
        else if (token == "surface")
            parse_surface();
        else if (token == "sphere")
            parse_sphere();
        else if (token == "maxdepth")
            ray_file >> g.maxdepth;
        else if (token == "cutoff")
            ray_file >> g.cutoff;
        else if (token == "light")
            parse_light();
    }
    // If there are no light sources, add a default
    if (g.light_vec.empty()) {
        Light l(1, Vec3(1, -1, 1));
        g.light_vec.push_back(l);
    }
    token = next_token();
}

// ===========================================================================
// Parse functions.
// =================F==========================================================

// parse background, fov, and screen
void parse_vec2(Vec2& v) {
    double x, y;
    ray_file >> x >> y;
    v = { x, y };
}

// parse background color, eyep, lookp, and up
void parse_vec3(Vec3 &v) {
    double x, y, z;
    ray_file >> x >> y >> z;
    v = { x, y, z };
}

void parse_surface()
{
    string token;
    double r, x, y, z;
    Surface s;

    ray_file >> s.name;
    while (1) {
        ray_file >> token;
        if (token == "ambient") {
            ray_file >> x >> y >> z;
            s.ambient = { x, y, z };
        }
        else if (token == "diffuse") {
            ray_file >> x >> y >> z;
            s.diffuse = { x, y, z };
        }
        else if (token == "specular") {
            ray_file >> x >> y >> z;
            s.specular = { x, y, z };
        }
        else if (token == "specpow")
            ray_file >> s.specpow;
        else if (token == "reflect")
            ray_file >> s.reflect;
        else {
            push_back = token;
            break;
        }
    }
    surface_map->insert({ s.name, s });
}

void parse_sphere()
{
    string surface_name;
    double radius, x, y, z;
    ray_file >> surface_name >> radius >> x >> y >> z;
    Vec3 diffuse = (*surface_map)[surface_name].diffuse;
    Sphere s(surface_name, radius, Vec3(x, y, z), diffuse);
    g.sphere_vec.push_back(s);
}

string next_token()
{
    string token;
    if (push_back != "") {
        token = push_back;
        push_back = "";
    }
    ray_file >> token;
    return token;
}

// All our light sources are points
void parse_light()
{
    Light l;
    string dummy;
    double x, y, z;

    ray_file >> l.intensity;
    ray_file >> dummy;  // skip "point"
    ray_file >> x >> y >> z;
}

