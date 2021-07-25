#include "mapper.h"
#include <cmath>

const float pi = 3.14159f;

Mapper::Mapper() : function(Sine)
{
}

Mapper::Mapper(MapFunction fn, float phase, float period, float amp, float offset)
{
    this->function = fn;
    this->phase = phase;
    this->period = period;
    this->amp = amp;
    this->offset = offset;
}

float Mapper::sine(float input)
{
    return offset + amp * sin((input + phase) / period * 2 * pi);
}

float Mapper::getValue(float input)
{
    return sine(input);
}