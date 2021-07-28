/**
 * @file vertex.h
 * @brief The building component of shapes. Vertex obnjects are describe
 *        with two polar coordinates, describin a sub and a super orbit.
 */

#ifndef VERTEX_H
#define VERTEX_H

#include <utility>
#include "../dynamic/dynamic.h"
#include "../dynamic/dynamicset.h"
#include "../color/color.h"

class Vertex
{
    Dynamic<float> *a;
    Dynamic<float> *r;
    Color color;

public:
    /**
     * @brief Construct a new Vertex object
     * 
     * @param angle angle
     * @param radius radius
     * @param red red value
     * @param green green value
     * @param blue blue value
     */
    Vertex(Dynamic<float> &angle,
           Dynamic<float> &radius,
           Dynamic<float> &red,
           Dynamic<float> &green,
           Dynamic<float> &blue);

    /**
     * @brief Get cardinal coordinates
     * 
     * @return std::pair<float,float> (x,y)
     */
    std::pair<float, float> getPos();

    /**
     * @brief Get the Color of this vertex
     * 
     * @return RGB
     */
    RGB getColor();
};

#endif