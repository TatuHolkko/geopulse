#include "adjustableset.h"

AdjustableSet::AdjustableSet()
{
    this->fn = Sine;
    this->base = MapperParameters{0};
    this->delta = MapperParameters{0};
    this->ip = nullptr;
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
}

Adjustable &AdjustableSet::generate()
{
    int numAdjustables = adjustables.size();
    MapperParameters newParams = base + delta * numAdjustables;
    Mapper mapper = Mapper(fn, newParams);
    Adjustable *adj = new Adjustable(0, false, mapper, *ip);

    adjustables.push_back(adj);

    return *adj;
}