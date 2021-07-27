#include "vertex.h"
#include "../dance/dance.h"
#include <cmath>

Vertex::Vertex(Dynamic<float> &a, Dynamic<float> &b, Dynamic<float> &r, Dynamic<float> &s, ProviderType providerType)
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

float Vertex::provideInput(){
    if (providerType == Radius){
        return r->get();
    }
    return a->get(); 
}