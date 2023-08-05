#pragma once

// ObjectVec.hpp

#include <vector>

#include "Object.hpp"

struct ObjectVec : vector<Object*>
{
    // Automatic destruction of Objects owned by the vector<Object *>
    ~ObjectVec();
};