#include "vertex.h"
#include <cmath>

Vertex::Vertex(const Dynamic<float> &angle,
               const Dynamic<float> &radius,
               const Dynamic<float> &red,
               const Dynamic<float> &green,
               const Dynamic<float> &blue) : a(&angle),
                                             r(&radius),
                                             color(red, green, blue)
{
}

Point Vertex::getPos() const
{
    float x = sin(a->get()) * r->get();
    float y = cos(a->get()) * r->get();
    return {x, y};
}

RGB Vertex::getColor() const
{
    return color.get();
}
