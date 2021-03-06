#include "color.h"
#include <utility>

Color::Color(const Dynamic<float> &red,
             const Dynamic<float> &green,
             const Dynamic<float> &blue) : red(&red),
                                           green(&green),
                                           blue(&blue)
{
}

RGB Color::get() const
{
    return {
        clamp(red->get()),
        clamp(green->get()),
        clamp(blue->get())};
}

float clamp(const float &value)
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

RGB operator+(const RGB &a, const RGB &b)
{
    return {
        clamp(a.R + b.R),
        clamp(a.G + b.G),
        clamp(a.B + b.B)};
}

RGB operator*(const RGB &a, const float &b)
{
    return {
        clamp(a.R * b),
        clamp(a.G * b),
        clamp(a.B * b)};
}