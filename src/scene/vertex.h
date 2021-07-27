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
#include "../dynamic/dynamicset.h"
#include "../color/color.h"

// if used as an input provider, what property to return
enum ProviderType
{
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
    Color color;

public:
    /**
     * @brief Construct a new Vertex object
     * 
     * @param superAngle super orbit angle
     * @param subAngle sub orbit angle
     * @param superRadius super orbit radius
     * @param subRadius sub orbit radius
     * @param providerType type of input provided by this vertex
     * @param colorFunction function type for color
     * @param red red value
     * @param green green value
     * @param blue blue value
     * @param alpha alpha value
     */
    Vertex(Dynamic<float> &superAngle,
           Dynamic<float> &subAngle,
           Dynamic<float> &superRadius,
           Dynamic<float> &subRadius,
           ProviderType providerType,
           Dynamic<float> &red,
           Dynamic<float> &green,
           Dynamic<float> &blue,
           Dynamic<float> &alpha);

    /**
     * @brief Get cardinal coordinates
     * 
     * @return std::pair<float,float> (x,y)
     */
    std::pair<float, float> getPos();

    /**
     * @brief Get the Color of this vertex
     * 
     * @return RGBA 
     */
    RGBA getColor();

    /**
     * @brief Return value dictated by providerType
     * 
     * @return float 
     */
    float provideInput();
};

#endif