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
    AdjustableSet* adjustables;

public:
    /**
     * @brief Construct a new Shape object
     *
     * @param n Number of vertices
     * @param adjustables adjustables for the vertices
     */
    Shape(int n, AdjustableSet& adjustables);

    /**
     * @brief Draw the shape
     */
    void draw();
};

#endif