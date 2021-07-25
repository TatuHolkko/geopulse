#include "shape.h"
#include "../adjustable/adjustablesuperset.h"
#include "../adjustable/inputprovider.h"
#include <list>


#ifndef SCENE_H
#define SCENE_H

class Scene 
{
    float beat;
    std::list<Shape> shapes;
    AdjustableSuperSet superset;

public:

    Scene(
        MapFunction fn,
        MapperParameters base,
        MapperParameters subdelta,
        MapperParameters subdeltadelta,
        MapperParameters superdelta,
        InputProvider& ip);

    void draw();
};

#endif