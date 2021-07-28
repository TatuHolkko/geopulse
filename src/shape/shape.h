/**
 * @file shape.h
 * @brief Shape consists of a set of vertices and connections
 */

#ifndef SHAPE_H
#define SHAPE_H

#include "vertex.h"
#include "../dynamic/timer.h"
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
     * @param red red dynamics
     * @param green green dynamics
     * @param blue blue dynamics
     * @param t timer
     */
    Shape(int n,
          DynamicSet<float> &angles,
          DynamicSet<float> &radii,
          DynamicSet<float> &red,
          DynamicSet<float> &green,
          DynamicSet<float> &blue,
          Timer &t);

    /**
     * @brief Draw the shape
     */
    void draw();
};

#endif