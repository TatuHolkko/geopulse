/**
 * @file shape.h
 * @brief Shape consists of a set of vertices and connections
 */

#ifndef SHAPE_H
#define SHAPE_H

#include "vertex.h"
#include "../dynamic/timer.h"
#include "../dynamic/deviator.h"
#include "../utility/utility.h"
#include <list>

class Shape
{
private:
    std::list<Deviator<float>> deviators;
    std::list<Vertex> vertices;

public:
    /**
     * @brief Construct a new Shape object
     * 
     * @param n Number of vertices
     * @param angleConf angle dynamics
     * @param radiusConf radius dynamics
     * @param redConf red dynamics
     * @param greenConf green dynamics
     * @param blueConf blue dynamics
     * @param t timer
     */
    Shape(int n,
          conf::DeviatorSequence angleConf,
          conf::DeviatorSequence radiusConf,
          conf::DeviatorSequence redConf,
          conf::DeviatorSequence greenConf,
          conf::DeviatorSequence blueConf,
          Timer &t);

    /**
     * @brief Draw the shape
     */
    void draw();
};

#endif