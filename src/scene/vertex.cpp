#include "vertex.h"
#include "../dance/dance.h"
#include <cmath>

Vertex::Vertex(Dynamic<float> &angle,
               Dynamic<float> &radius,
               ProviderType providerType,
               Dynamic<float> &red,
               Dynamic<float> &green,
               Dynamic<float> &blue,
               Dynamic<float> &alpha) : providerType(providerType),
                                        a(&angle),
                                        r(&radius),
                                        color(red, green, blue, alpha)
{
}

std::pair<float, float> Vertex::getPos()
{
    float x = sin(a->get()) * r->get();
    float y = cos(a->get()) * r->get();
    return std::make_pair(x, y);
}

RGBA Vertex::getColor()
{
    return color.get();
}

float Vertex::provideInput()
{
    if (providerType == Radius)
    {
        return r->get();
    }
    return a->get();
}