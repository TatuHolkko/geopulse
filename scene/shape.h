/**
 * @file shape.h
 * @brief Shape consists of a set of vertices and connections
 */
#include "vertex.h"
#include <list>

class Shape
{

    std::list<Vertex> vertices;

public:
    /**
     * @brief Construct a new Shape object
     *
     * @param n Number of vertices
     * @param r Radius
     */
    Shape(int n, float r);

    /**
     * @brief Draw the shape
     */
    void draw();
};