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
    Dynamic<float> *r;
    Color color;

public:
    /**
     * @brief Construct a new Vertex object
     * 
     * @param angle angle
     * @param radius radius
     * @param providerType type of input provided by this vertex
     * @param colorFunction function type for color
     * @param red red value
     * @param green green value
     * @param blue blue value
     * @param alpha alpha value
     */
    Vertex(Dynamic<float> &angle,
           Dynamic<float> &radius,
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