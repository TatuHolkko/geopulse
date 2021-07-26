#include "shape.h"
#include "../dynamic/dynamicsuperset.h"
#include "../dynamic/inputprovider.h"
#include <list>

#ifndef SCENE_H
#define SCENE_H

class Scene
{
    float beat;
    std::list<Shape> shapes;
    DynamicSuperset<float> superOrbitAngleSuperset;
    DynamicSuperset<float> subOrbitAngleSuperset;
    DynamicSuperset<float> superOrbitRadiusSuperset;
    DynamicSuperset<float> subOrbitRadiusSuperset;

public:
    Scene(MapperFunction fn,
          MapperSuperParameters superOrbitAngleSuperParams,
          MapperSuperParameters subOrbitAngleSuperParams,
          MapperSuperParameters superOrbitRadiusSuperParams,
          MapperSuperParameters subOrbitRadiusSuperParams,
          InputProvider &ip);

    void draw();
};

#endif