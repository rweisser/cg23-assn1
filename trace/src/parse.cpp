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

#include "tests.hpp" // XXX

extern G g; // global shared data

void   read_file();
void   parse_vec2(Vec2 &v);
void   parse_vec3(Vec3 &v);
void   parse_sphere();
void   parse_surface();
void   parse_light();
string next_token();
void   init_look_screen();

static ifstream ray_file;
unordered_map<string, Surface>* surface_map;
string push_back = ""; // token pushed backed into input stream

const double PI = 3.141592653589793;

void parse_file(const string& file_name)
{
    ray_file.open(file_name);
    surface_map = new unordered_map<string, Surface>;
    if (!ray_file) {
        cerr << file_name << ": ";
        cerr << strerror(errno) << endl;
        exit(1);
    }
    read_file(); // process the file
    test_surfaces(*surface_map); // XXX
    delete surface_map;
    ray_file.close();

    // If there are no light sources, add a default
    if (g.light_vec.empty()) {
        Light l(1, Vec3(1, -1, 1));
        g.light_vec.push_back(l);
    }

    init_look_screen();
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
        token = next_token();
    }
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
    Vec3  ambient  = (*surface_map)[surface_name].ambient;
    Vec3  diffuse  = (*surface_map)[surface_name].diffuse;
    Vec3  specular = (*surface_map)[surface_name].specular;
    float specpow  = (*surface_map)[surface_name].specpow; 
    float reflect  = (*surface_map)[surface_name].reflect;  
    Sphere s(radius, Vec3(x, y, z), ambient, diffuse, specular, specpow, reflect);
    g.sphere_vec.push_back(s);
}

string next_token()
{
    string token;
    if (push_back == "")
        ray_file >> token;
    else {
        token = push_back;
        push_back = "";
    }
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
    l.pos = { x, y, z };
    g.light_vec.push_back(l);
}

void init_look_screen() {
    Vec3 wtemp = g.eyep - g.lookp;
    double d = wtemp.mag();
    g.look_screen.w = wtemp.normalize();
    g.look_screen.u = g.up.cross(g.look_screen.w).normalize();
    g.look_screen.v = g.look_screen.w.cross(g.look_screen.u);

    // Horizontal fov
    int degrees = g.fov.x;
    double theta = degrees * PI / 180;
    g.look_screen.right = d * tan(theta / 2);
    g.look_screen.left = -g.look_screen.right;

    // Vertical fov
    degrees = g.fov.y;
    theta = degrees * PI / 180;
    g.look_screen.top = d * tan(theta / 2);
    g.look_screen.bottom = -g.look_screen.top;

    g.look_screen.pixelsh = g.screen_size.x;
    g.look_screen.pixelsv = g.screen_size.y;
}
