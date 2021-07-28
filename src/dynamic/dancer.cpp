#include "dancer.h"

template<typename T>
Dancer<T>::Dancer()
{
    this->inputProvider = nullptr;
    this->mapper = Mapper();
}

template<typename T>
Dancer<T>::Dancer(Mapper m, InputProvider &ip)
{
    this->inputProvider = &ip;
    this->mapper = m;
}

template<typename T>
T Dancer<T>::get()
{
    float input = inputProvider->provideInput();
    return static_cast<T>(mapper.getValue(input));
}

template class Dancer<float>;
template class Dancer<int>;