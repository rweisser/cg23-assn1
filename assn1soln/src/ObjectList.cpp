// implementation code for ObjectList class
// list of objects in scene

#include "ObjectList.hpp"
#include "Object.hpp"
#include "Ray.hpp"
#include <iostream>

static std::size_t RayCount = 0, IsectCount = 0;

// destructor: report ray stats and delete all contained objects
ObjectList::~ObjectList() {
    std::cout << RayCount << " Photon Ray" << (RayCount == 1 ? "" : "s") << '\n';
    std::cout << IsectCount << " Intersection" << (IsectCount == 1 ? "" : "s") << '\n';

    for(auto obj : objects)
        delete obj;
}

// trace ray r through all objects, returning first intersection
Vec3 ObjectList::trace(const Ray &r) const
{
    ++RayCount;
    
    // initially null object at furthest distance
    Object *hitObj = nullptr;
    float hitT = Ray::infinity;

    // check all objects for a closer intersection
    for(auto obj : objects) {
        ++IsectCount;
        float current = obj->intersect(r);
        if (current < hitT) {
            hitT = current;
            hitObj = obj;
        }
    }

    // color of hit object, or background if none
    return hitObj ? hitObj->color : background;
}
