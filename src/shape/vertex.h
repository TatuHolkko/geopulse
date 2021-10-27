/**
 * @file vertex.h
 * @brief The building component of shapes. Vertex obnjects are describe
 *        with two polar coordinates, describin a sub and a super orbit.
 */

#ifndef VERTEX_H
#define VERTEX_H

#include "utility.h"
#include "dynamic.h"
#include "color.h"

class Vertex
{
    const Dynamic<float> *a;
    const Dynamic<float> *r;
    const Color color;

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
    Vertex(const Dynamic<float> &angle,
           const Dynamic<float> &radius,
           const Dynamic<float> &red,
           const Dynamic<float> &green,
           const Dynamic<float> &blue);

    /**
     * @brief Get cardinal coordinates
     * 
     * @return Point (x,y)
     */
    Point getPos() const;

    /**
     * @brief Get the Color of this vertex
     * 
     * @return RGB
     */
    RGB getColor() const;
};

#endif