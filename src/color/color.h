
#ifndef COLOR_H
#define COLOR_H

#include "../dynamic/dynamic.h"

typedef struct RGBA {
    float R;
    float G;
    float B;
    float A;
} RGBA;

RGBA operator+(const RGBA a, const RGBA b);
RGBA operator*(const RGBA a, const float b);

float clamp(float value);

class Color
{
private:
    Dynamic<float> *red;
    Dynamic<float> *green;
    Dynamic<float> *blue;
    Dynamic<float> *alpha;

public:
    Color();
    Color(Dynamic<float> &red,
          Dynamic<float> &green,
          Dynamic<float> &blue,
          Dynamic<float> &alpha);
    
    RGBA get();
};

#endif