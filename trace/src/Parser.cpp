// ===========================================================================
// Parser.cpp

// A parser for ray trace files
// ===========================================================================

using namespace std;

#include "Parser.hpp"

// ===========================================================================
// Public member functions
// ===========================================================================

void Parser::parse_file(const string& file_name)
{
    ray_file.open(file_name);
    if (!ray_file) {
        cerr << file_name << ": ";
        cerr << strerror(errno) << endl;
        exit(1);
    }
    read_file();                // process the file
    ray_file.close();
    g.look_screen.init(g);      // g.look_screen needs the info in g to
                                // initialize itself.
}

// ===========================================================================
// Private member functions
// ===========================================================================

void Parser::read_file()
{
    // read a keyword
    // ignore tokens we don't care about
    string token;
    while (1) {
        ray_file >> token;
        if (ray_file.eof())
            break;
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
    }
}

// parse background, fov, and screen
void Parser::parse_vec2(Vec2& v) {
    double x, y;
    ray_file >> x >> y;
    v = { x, y };
}

// parse background color, eyep, lookp, and up
void Parser::parse_vec3(Vec3& v) {
    double x, y, z;
    ray_file >> x >> y >> z;
    v = { x, y, z };
}

void Parser::parse_surface()
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
            surface_map.insert({ s.name, s });
            return;
        }
    }
}

void Parser::parse_sphere()
{
    string surface_name;
    double radius, x, y, z;
    ray_file >> surface_name >> radius >> x >> y >> z;
    Vec3 color = surface_map[surface_name].color;
    Sphere* sp = new Sphere(radius, Vec3(x, y, z), color);
    // g.sphere_vec.push_back(s); // XXX delete this line
    // g.object_vec has the responsibility to delete s.
    g.object_vec.push_back(sp);
}
