#include "shape.h"
#include "../adjustable/inputprovider.h"
#include <list>


#ifndef SCENE_H
#define SCENE_H

class Scene 
{
    float beat;
    std::list<Shape> shapes;
    AdjustableSet adset;

public:
    Scene(InputProvider& ip);
    void draw();
};

#endif