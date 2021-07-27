/**
 * @file vertex.h
 * @brief The building component of shapes. Vertex obnjects are describe
 *        with two polar coordinates, describin a sub and a super orbit.
 */

#ifndef VERTEX_H
#define VERTEX_H

#include <utility>
#include "../dance/timer.h"
#include "../dynamic/dynamic.h"

// if used as an input provider, what property to return
enum ProviderType {
    Radius,
    Angle
};

class Vertex : public InputProvider
{
    ProviderType providerType;
    Dynamic<float> *a;
    Dynamic<float> *b;
    Dynamic<float> *r;
    Dynamic<float> *s;

public:
    /**
     * @brief Construct a new Vertex object
     * 
     * @param a Super orbit angle
     * @param b Sub orbit angle
     * @param r Super orbit radius
     * @param s Sub orbit radius
     * @param providerType type of input provided by the vertex
     */
    Vertex(Dynamic<float> &a, Dynamic<float> &b, Dynamic<float> &r, Dynamic<float> &s, ProviderType providerType);

    /**
     * @brief Get cardinal coordinates
     * 
     * @return std::pair<float,float> (x,y)
     */
    std::pair<float, float> getPos();

    /**
     * @brief Return value dictated by providerType
     * 
     * @return float 
     */
    float provideInput();
};

#endif