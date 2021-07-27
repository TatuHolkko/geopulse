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

    DynamicSuperset<float> redSuperset;
    DynamicSuperset<float> greenSuperset;
    DynamicSuperset<float> blueSuperset;
    DynamicSuperset<float> alphaSuperset;

public:
    /**
     * @brief Construct a new Scene object
     * 
     
     * @param timer
     */

    /**
     * @brief Construct a new Scene object
     * 
     * @param superOrbitAngleSuperParams super orbit angle parameters
     * @param subOrbitAngleSuperParams sub orbit angle parameters
     * @param superOrbitRadiusSuperParams super orbit radius parameters
     * @param subOrbitRadiusSuperParams sub orbit radius parameters
     * @param veretxProviderType type of input provided by the vertices
     * @param redSuperParams red params
     * @param greenSuperParams green params
     * @param blueSuperParams blue params
     * @param alphaSuperParams alpha params
     * @param t 
     */
    Scene(MapperSuperParameters superOrbitAngleSuperParams, 
          MapperSuperParameters subOrbitAngleSuperParams,
          MapperSuperParameters superOrbitRadiusSuperParams,
          MapperSuperParameters subOrbitRadiusSuperParams,
          ProviderType veretxProviderType,
          MapperSuperParameters redSuperParams, 
          MapperSuperParameters greenSuperParams,
          MapperSuperParameters blueSuperParams,
          MapperSuperParameters alphaSuperParams,
          Timer &t);

    void draw();
};

#endif