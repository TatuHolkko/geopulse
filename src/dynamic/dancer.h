/**
 * @file dance.h
 * @brief A Dancer object describes a value that changes over time.
 * 
 * The input provider given in the constructor will be called each 
 * time the value of the Dancer object is retrieved with the get() call.
 * The return value of the input provider together with the mapper function
 * will dictate what the value is.
 */

#ifndef DANCE_H
#define DANCE_H

#include "mapper.h"
#include "dynamic.h"
#include "inputprovider.h"

template<typename T>
class Dancer : public Dynamic<T>
{
private:
    Mapper mapper;
    InputProvider* inputProvider;
    float sine(float value);

public:
    Dancer();
    /**
     * @brief Construct a new Dancer object
     * 
     * @param m Mapper object describing the behavior of the value
     * @param ip input provider for the input into the mapper
     */
    Dancer(Mapper m, InputProvider& ip);

    /**
     * @brief Call the input provider and feed it to the mapper, which will
     *        return the final value
     * 
     * @return float
     */
    T get();
};

#endif