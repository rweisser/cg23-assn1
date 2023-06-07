#pragma once

// ===========================================================================
// parse.cpp
// 
// Functions to parse the input file into global variables.
// ===========================================================================
/*
using namespace std;

#include <cerrno>
#include <fstream>
#include <iostream>
#include <string>

#include "shared_data.hpp"
#include "Sphere.hpp"

void   parse_vec2(Vec2 &v);
void   parse_vec3(Vec3 &v);
void   parse_sphere();
void   parse_surface();
void   read_file();

static ifstream ray_file;

void parse_file(const string& file_name)
{
    ray_file.open(file_name);
    if (!ray_file) {
        cerr << file_name << ": ";
        cerr << strerror(errno) << endl;
        exit(1);
    }
    read_file();                // process the file
    ray_file.close();
}

void read_file()
{
    // read a keyword
    // ignore tokens we don't care about
    string token;
    while (1) {
        ray_file >> token;
        if (ray_file.eof())
            break;
        if (token == "background")
            parse_vec3(background);
        else if (token == "eyep")
            parse_vec3(eyep);
        else if (token == "lookp")
            parse_vec3(lookp);
        else if (token == "up")
            parse_vec3(up);
        else if (token == "fov")
            parse_vec2(fov);
        else if (token == "screen")
            parse_vec2(screen_size);
        else if (token == "surface")
             parse_surface();
        else if (token == "sphere")
            parse_sphere();
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
    string name;
    string token;
    double r, x, y, z;

    ray_file >> name;
    while (1) {
        ray_file >> token;
        if (token == "diffuse") {
            ray_file >> x >> y >> z;
            Surface s(name, { x, y, z });
            surface_map->insert({ s.name, s });
            return;
        }
    }
}

void parse_sphere()
{
    string surface_name;
    double radius, x, y, z;
    ray_file >> surface_name >> radius >> x >> y >> z;
    Vec3 color = (*surface_map)[surface_name].color;
    Sphere s(surface_name, radius, Vec3(x, y, z), color);
    sphere_vec.push_back(s);
}
*/
