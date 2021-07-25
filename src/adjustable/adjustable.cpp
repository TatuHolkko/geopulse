#include "adjustable.h"


Adjustable::Adjustable(){
    this->defaultValue = 0;
    this->dancer = Dancer();
    this->fixed = true;
}

Adjustable::Adjustable(float value){
    this->defaultValue = value;
    this->dancer = Dancer();
    this->fixed = true;
}

Adjustable::Adjustable(float value, bool fixed, Mapper m, InputProvider& ip){
    this->defaultValue = value;
    this->dancer = Dancer(m, ip);
    this->fixed = fixed;
}

float Adjustable::get(){
    if (fixed){
        return defaultValue;
    }
    return dancer.get();
}

void Adjustable::setFixed(bool value){
    fixed = value;
}