#include "../shape/shape.h"
#include "../dynamic/dynamicsuperset.h"
#include "../dynamic/inputprovider.h"
#include <list>

#ifndef SCENE_H
#define SCENE_H

class Scene
{
    float beat;
    std::list<Shape> shapes;
    DynamicSuperset<float> angleSuperset;
    DynamicSuperset<float> radiusSuperset;

    DynamicSuperset<float> redSuperset;
    DynamicSuperset<float> greenSuperset;
    DynamicSuperset<float> blueSuperset;

public:

    /**
     * @brief Construct a new Scene object
     * 
     * @param anglengleSuperParams angle dynamics parameters
     * @param radiusSuperParams radius dynamics parameters
     * @param redSuperParams red dynamics params
     * @param greenSuperParams green dynamics params
     * @param blueSuperParams blue dynamics params
     * @param t 
     */
    Scene(MapperSuperParameters anglengleSuperParams, 
          MapperSuperParameters radiusSuperParams,
          MapperSuperParameters redSuperParams, 
          MapperSuperParameters greenSuperParams,
          MapperSuperParameters blueSuperParams,
          Timer &t);

    void draw();
};

#endif