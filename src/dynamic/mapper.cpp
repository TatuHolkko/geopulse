#include "mapper.h"
#include "../utility/utility.h"
#include <cmath>

Mapper::Mapper()
{
    this->function = Sine;
    this->params = MapperParameters{0};
}

Mapper::Mapper(MapperFunction fn, MapperParameters params)
{
    this->function = fn;
    this->params = params;
}

float Mapper::getValue(float input)
{
    switch (this->function)
    {
    case HalfSine:
        return halfSine(input);
        break;
    
    case Sine:
        return sine(input);
        break;
    }
    throw "Logic error";
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

float Mapper::sine(float input)
{
    return params.offset + params.amp * sin((input + params.phase) / params.period * 2 * PI);
}

float Mapper::halfSine(float input)
{
    float remainder = fmod(input + params.phase, params.period / 2);
    return params.offset + params.amp * sin((remainder/params.period) * 2 * PI - PI / 2);
}