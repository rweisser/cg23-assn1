// ObjectVec.cpp

#include "ObjectVec.hpp"

ObjectVec::~ObjectVec()
{
    for (Object* o : *this)
        delete o;
}