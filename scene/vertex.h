/**
 * @file vertex.h
 * @brief The building component of shapes. Vertex obnjects are describe
 *        with two polar coordinates, describin a sub and a super orbit.
 */
#include <utility>
#include "../dance/timer.h"

class Vertex
{

    float a;
    float b;
    float r;
    float s;
    InputProvider* t;

public:
    /**
     * @brief Construct a new Vertex object
     * 
     * @param a Super orbit angle
     * @param b Sub orbit angle
     * @param r Super orbit radius
     * @param s Sub orbit radius
     */
    Vertex(float a, float b, float r, float s, InputProvider& t);

    /**
     * @brief Get cardinal coordinates
     * 
     * @return std::pair<float,float> (x,y)
     */
    std::pair<float, float> getPos();
};