#include "deviator.h"

template <typename T>
Deviator<T>::Deviator(const conf::Function &function, InputProvider &ip)
{
    this->inputProvider = &ip;
    this->function = Function(function.type, function.params);
}

template <typename T>
T Deviator<T>::get() const
{
    float input = inputProvider->provideInput();
    return static_cast<T>(function.getValue(input));
}

template class Deviator<float>;
