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
     * @param angles angle dynamics
     * @param radii radius dynamics
     * @param providerType type of input provided by vertices
     * @param t timer
     */
    Shape(int n,
          DynamicSet<float> &angles,
          DynamicSet<float> &radii,
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