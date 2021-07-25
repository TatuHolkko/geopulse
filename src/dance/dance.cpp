#include "dance.h"

Dancer::Dancer()
{
    this->inputProvider = nullptr;
    this->mapper = Mapper();
}

Dancer::Dancer(Mapper m, InputProvider &ip)
{
    this->inputProvider = &ip;
    this->mapper = m;
}

float Dancer::get()
{
    float input = inputProvider->provideInput();
    return mapper.getValue(input);
}