#include "shape.h"
#include "../adjustable/inputprovider.h"
#include <list>


#ifndef SCENE_H
#define SCENE_H

class Scene 
{
    float beat;
    std::list<Shape> shapes;

public:
    Scene(InputProvider& t);
    void draw();
};

#endif