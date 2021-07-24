#include "vertex.h"
#include "../dance/dance.h"
#include <cmath>

Vertex::Vertex(float a, float b, float r, float s, InputProvider &t)
{
    this->a = a;
    this->b = b;
    this->r = r;
    this->s = s;
    this->t = &t;
}

std::pair<float, float> Vertex::getPos()
{
    Dancer angle = Dancer(Mapper(Sine, 0, 4, 0.1, 0.5), *t);
    float x = sin(a) * r*angle.get();
    float y = cos(a) * r*angle.get();
    x += sin(b) * s;
    y += cos(b) * s;
    return std::make_pair(x, y);
}