
#ifndef COLOR_H
#define COLOR_H

#include "../dynamic/dynamic.h"

typedef struct RGB
{
    float R;
    float G;
    float B;
} RGB;

RGB operator+(const RGB a, const RGB b);
RGB operator*(const RGB a, const float b);

float clamp(float value);

class Color
{
private:
    Dynamic<float> *red;
    Dynamic<float> *green;
    Dynamic<float> *blue;

public:
    Color();
    Color(Dynamic<float> &red,
          Dynamic<float> &green,
          Dynamic<float> &blue);

    RGB get();
};

#endif