
#ifndef COLOR_H
#define COLOR_H

#include "../dynamic/dynamic.h"

typedef struct RGB
{
    float R;
    float G;
    float B;
} RGB;

RGB operator+(const RGB &a, const RGB &b);
RGB operator*(const RGB &a, const float &b);

float clamp(const float &value);

class Color
{
private:
    const Dynamic<float> *red;
    const Dynamic<float> *green;
    const Dynamic<float> *blue;

public:
    Color();
    Color(const Dynamic<float> &red,
          const Dynamic<float> &green,
          const Dynamic<float> &blue);
    /**
     * @brief Get values for all dynamics and combine them to an RGB struct
     * 
     * @return RGB 
     */
    RGB get() const;
};

#endif