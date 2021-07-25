/**
 * @file shape.h
 * @brief Shape consists of a set of vertices and connections
 */

#ifndef SHAPE_H
#define SHAPE_H

#include "vertex.h"
#include "../adjustable/adjustableset.h"
#include <list>

class Shape
{

    std::list<Vertex> vertices;
    AdjustableSet adjustables;

public:
    /**
     * @brief Construct a new Shape object
     *
     * @param n Number of vertices
     * @param r Radius
     * @param ip input provider for adjustables
     */
    Shape(int n, float r, InputProvider& ip);

    /**
     * @brief Draw the shape
     */
    void draw();
};

#endif