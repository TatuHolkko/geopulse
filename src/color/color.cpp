#include "color.h"
#include <utility>

Color::Color(Dynamic<float> &red,
             Dynamic<float> &green,
             Dynamic<float> &blue,
             Dynamic<float> &alpha) : red(&red),
                                      green(&green),
                                      blue(&blue),
                                      alpha(&alpha)
{
}

RGBA Color::get()
{
    return {
        clamp(red->get()),
        clamp(green->get()),
        clamp(blue->get()),
        clamp(alpha->get())};
}

float clamp(float value)
{
    if (value > 1)
    {
        return 1;
    }
    if (value < 0)
    {
        return 0;
    }
    return value;
}

RGBA operator+(const RGBA a, const RGBA b)
{
    return {
        clamp(a.R + b.R),
        clamp(a.G + b.G),
        clamp(a.B + b.B),
        clamp(a.A + b.A)};
}

RGBA operator*(const RGBA a, const float b)
{
    return {
        clamp(a.R * b),
        clamp(a.G * b),
        clamp(a.B * b),
        clamp(a.A * b)};
}