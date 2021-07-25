/**
 * @file vertex.h
 * @brief The building component of shapes. Vertex obnjects are describe
 *        with two polar coordinates, describin a sub and a super orbit.
 */

#ifndef VERTEX_H
#define VERTEX_H

#include <utility>
#include "../dance/timer.h"
#include "../adjustable/adjustable.h"

class Vertex
{

    Adjustable *a;
    Adjustable *b;
    Adjustable *r;
    Adjustable *s;

public:
    /**
     * @brief Construct a new Vertex object
     * 
     * @param a Super orbit angle
     * @param b Sub orbit angle
     * @param r Super orbit radius
     * @param s Sub orbit radius
     */
    Vertex(Adjustable &a, Adjustable &b, Adjustable &r, Adjustable &s);

    /**
     * @brief Get cardinal coordinates
     * 
     * @return std::pair<float,float> (x,y)
     */
    std::pair<float, float> getPos();
};

#endif