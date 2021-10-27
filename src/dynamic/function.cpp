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
        break;

    case Sine:
        return sine(input);
        break;
    }
    throw "Logic error";
}

float Function::sine(const float &input) const
{
    return params.offset + params.amp * sin((input + params.phase) / params.period * 2 * PI);
}

float Function::halfSine(const float &input) const
{
    float remainder = fmod(input + params.phase, params.period);
    return params.offset + params.amp * sin((remainder / params.period / 2) * 2 * PI - PI / 2);
}