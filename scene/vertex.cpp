#include "vertex.h"
#include <cmath>

Vertex::Vertex(float a, float b, float r, float s)
{
    this->a = a;
    this->b = b;
    this->r = r;
    this->s = s;
}

std::pair<float, float> Vertex::getPos()
{
    float x = sin(a) * r;
    float y = cos(a) * r;
    x += sin(b) * s;
    y += cos(b) * s;
    return std::make_pair(x, y);
}