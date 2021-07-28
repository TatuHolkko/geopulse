#include "vertex.h"
#include <cmath>

Vertex::Vertex(Dynamic<float> &angle,
               Dynamic<float> &radius,
               Dynamic<float> &red,
               Dynamic<float> &green,
               Dynamic<float> &blue) : a(&angle),
                                        r(&radius),
                                        color(red, green, blue)
{
}

Point Vertex::getPos()
{
    float x = sin(a->get()) * r->get();
    float y = cos(a->get()) * r->get();
    return {x, y};
}

RGB Vertex::getColor()
{
    return color.get();
}
