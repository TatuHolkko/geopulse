#include "function.h"
#include "../utility/utility.h"
#include <cmath>

Function::Function()
{
    this->type = Sine;
    this->params = conf::FunctionParameters{0};
}

Function::Function(const FunctionType fn, const conf::FunctionParameters &params)
{
    if (params.period == 0)
    {
        throw "Period can not be zero!";
    }
    this->type = fn;
    this->params = params;
}

float Function::getValue(const float &input) const
{
    switch (this->type)
    {
    case HalfSine:
        return halfSine(input);

    case Sine:
        return sine(input);

    case Square:
        return square(input);

    case Saw:
        return saw(input);

    case Tri:
        return tri(input);
    }
    throw "Logic error";
}

float Function::sine(const float &input) const
{
    return params.offset + params.amp * sin((input + params.phase) / params.period * 2 * PI);
}

float Function::halfSine(const float &input) const
{
    float remainder = periodize(input);
    return params.offset + params.amp * sin((remainder / params.period / 2) * 2 * PI - PI / 2);
}

float Function::square(const float &input) const
{
    float remainder = periodize(input);
    if (remainder > params.period / 2)
    {
        return params.offset + params.amp;
    }
    else
    {
        return params.offset - params.amp;
    }
}

float Function::saw(const float &input) const
{
    float remainder = periodize(input);
    return params.offset + ((2 * remainder / params.period) - 1) * params.amp;
}

float Function::tri(const float &input) const
{
    float remainder = periodize(input);
    int sign = 1;
    if (remainder > (params.period / 2))
    {
        remainder -= params.period / 2;
        sign = -1;
    }
    return params.offset + sign * ((remainder / (params.period / 4) - 1) * params.amp);
}

float Function::periodize(const float& input) const
{
    return fmod(input + params.phase, params.period);
}