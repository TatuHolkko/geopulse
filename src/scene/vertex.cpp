#include "vertex.h"
#include "../dance/dance.h"
#include <cmath>

Vertex::Vertex(Dynamic<float> &superAngle,
               Dynamic<float> &subAngle,
               Dynamic<float> &superRadius,
               Dynamic<float> &subRadius,
               ProviderType providerType,
               Dynamic<float> &red,
               Dynamic<float> &green,
               Dynamic<float> &blue,
               Dynamic<float> &alpha) : color(red, green, blue, alpha)
{                                         
    this->a = &superAngle;
    this->b = &subAngle;
    this->r = &superRadius;
    this->s = &subRadius;
    this->providerType = providerType;
}

std::pair<float, float> Vertex::getPos()
{
    float x = sin(a->get()) * r->get();
    float y = cos(a->get()) * r->get();
    x += sin(b->get()) * s->get();
    y += cos(b->get()) * s->get();
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