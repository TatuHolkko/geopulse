#include "dance.h"

Dancer::Dancer(Mapper m, InputProvider& ip) {
    this->inputProvider = &ip;
    this->mapper = m;
}

float Dancer::get(){
    float input = inputProvider->provideInput();
    return mapper.getValue(input);
}