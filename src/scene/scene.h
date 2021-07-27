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
    /**
     * @brief Construct a new Scene object
     * 
     * @param superOrbitAngleSuperParams super orbit angle parameters
     * @param subOrbitAngleSuperParams sub orbit angle parameters
     * @param superOrbitRadiusSuperParams super orbit radius parameters
     * @param subOrbitRadiusSuperParams sub orbit radius parameters
     * @param veretxProviderType type of input provided by the vertices
     * @param ip input provider for vertices
     */
    Scene(MapperSuperParameters superOrbitAngleSuperParams, 
          MapperSuperParameters subOrbitAngleSuperParams,
          MapperSuperParameters superOrbitRadiusSuperParams,
          MapperSuperParameters subOrbitRadiusSuperParams,
          ProviderType veretxProviderType,
          InputProvider &ip);

    void draw();
};

#endif