#include "mapper.h"
#include <cmath>

const float pi = 3.14159f;

Mapper::Mapper()
{
    this->function = Sine;
    this->params = MapperParameters{0};
}

Mapper::Mapper(MapFunction fn, MapperParameters params)
{
    this->function = fn;
    this->params = params;
}

float Mapper::sine(float input)
{
    return params.offset + params.amp * sin((input + params.phase) / params.period * 2 * pi);
}

float Mapper::getValue(float input)
{
    return sine(input);
}

MapperParameters operator+(
    const MapperParameters &a,
    const MapperParameters &b)
{
    MapperParameters result;
    result.phase  = a.phase  + b.phase;
    result.period = a.period + b.period;
    result.amp    = a.amp    + b.amp;
    result.offset = a.offset + b.offset;
    return result;
}

MapperParameters operator*(
    const MapperParameters &a,
    const int n)
{
    MapperParameters result;
    result.phase  = a.phase  * n;
    result.period = a.period * n;
    result.amp    = a.amp    * n;
    result.offset = a.offset * n;
    return result;
}