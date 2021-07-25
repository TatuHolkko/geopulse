#include "adjustableset.h"

AdjustableSet::AdjustableSet()
{
    this->fn = Sine;
    this->base = MapperParameters{0};
    this->delta = MapperParameters{0};
    this->ip = nullptr;
    this->n = 0;
}

AdjustableSet::~AdjustableSet(){
    for(Adjustable* adj : adjustables){
        delete adj;
    }
}

AdjustableSet::AdjustableSet(
    MapFunction fn,
    MapperParameters base,
    MapperParameters delta,
    InputProvider &ip)
{
    this->fn = fn;
    this->base = base;
    this->delta = delta;
    this->ip = &ip;
    this->n = 0;
}

Adjustable &AdjustableSet::generate()
{
    MapperParameters newParams = base + delta * n;
    Mapper mapper = Mapper(fn, newParams);
    Adjustable *adj = new Adjustable(0, false, mapper, *ip);

    adjustables.push_back(adj);

    n++;

    return *adj;
}

Adjustable &AdjustableSet::constant(float value){
    Adjustable *adj = new Adjustable(value);
    adjustables.push_back(adj);
    return *adj;
}
