/**
 * @file shape.h
 * @brief Shape consists of a set of vertices and connections
 */

#ifndef SHAPE_H
#define SHAPE_H

#include "vertex.h"
#include "../dynamic/dynamicset.h"
#include <list>

class Shape
{
private:
    std::list<Vertex> vertices;

public:
    /**
     * @brief Construct a new Shape object
     * 
     * @param n Number of vertices
     * @param superOrbitAngles Super orbit angle dynamics
     * @param subOrbitAngles   Sub orbit angle dynamics
     * @param superOrbitRadii  Super orbit radius dynamics
     * @param subOrbitRadii    Sub orbit radius dynamics
     * @param providerType type of input provided by vertices
     * @param t timer
     */
    Shape(int n,
          DynamicSet<float> &superOrbitAngles,
          DynamicSet<float> &subOrbitAngles,
          DynamicSet<float> &superOrbitRadii,
          DynamicSet<float> &subOrbitRadii,
          ProviderType providerType,
          DynamicSet<float> &red,
          DynamicSet<float> &green,
          DynamicSet<float> &blue,
          DynamicSet<float> &alpha,
          Timer &t);

    /**
     * @brief Draw the shape
     */
    void draw();
};

#endif