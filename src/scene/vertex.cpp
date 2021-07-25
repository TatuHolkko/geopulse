#include "vertex.h"
#include "../dance/dance.h"
#include <cmath>

Vertex::Vertex(Adjustable &a, Adjustable &b, Adjustable &r, Adjustable &s)
{
    this->a = &a;
    this->b = &b;
    this->r = &r;
    this->s = &s;
}

std::pair<float, float> Vertex::getPos()
{
    float x = sin(a->get()) * r->get();
    float y = cos(a->get()) * r->get();
    x += sin(b->get()) * s->get();
    y += cos(b->get()) * s->get();
    return std::make_pair(x, y);
}