#pragma once

// ===========================================================================
// Functions to parse the input file into global variables.
// =================F==========================================================

#include <cerrno>
#include <fstream>
#include <iostream>
#include <string>

#include "shared_data.hpp"

using namespace std;

void read_file();
void parse_vector(Vec3 &v);
void parse_surface();

static ifstream ray_file;

void parse_file(const char* const file_name)
{
    ray_file.open(file_name, ios::in);
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
    string key_word;
    while (!ray_file.eof()) {
        ray_file >> key_word;
        if (key_word == "background") {
            parse_vector(background);
        }
        else if (key_word == "eyep") {
            parse_vector(eyep);
        }
        else if (key_word == "lookp") {
            parse_vector(lookp);
        }
        else if (key_word == "up") {
            parse_vector(up);
        }
        else if (key_word == "surface") {
            parse_surface();
        }
    }
}

// ===========================================================================
// Parse functions.
// =================F==========================================================

// parse background color, eyep, lookp, and up
void parse_vector(Vec3 &v) {
    double x, y, z;
    ray_file >> x >> y >> z;
    v = tuple<double, double, double>(x, y, z);
}

void parse_surface()
{
    string name;
    string key_word;
    double r, x, y, z;

    ray_file >> name;
    ray_file >> key_word;
    if (key_word == "diffuse") {
        ray_file >> r >> x >> y >> z;
    }
}
