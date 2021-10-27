/**
 * @file dance.h
 * @brief An Deviator object describes a value that changes over time.
 * 
 * The input provider given in the constructor will be called each 
 * time the value of the Deviator object is retrieved with the get() call.
 * The return value of the input provider together with the mapper function
 * will dictate what the value is.
 */

#ifndef DEVIATOR_H
#define DEVIATOR_H

#include "function.h"
#include "dynamic.h"
#include "inputprovider.h"
#include "utility.h"

template <typename T>
class Deviator : public Dynamic<T>
{
private:
    Function function;
    InputProvider *inputProvider;

public:
    /**
     * @brief Construct a new Deviator object
     * 
     * @param function Function configuration object describing the behavior of the value
     * @param ip input provider for the input into the mapper
     */
    Deviator(const conf::Function &function, InputProvider &ip);

    /**
     * @brief Call the input provider and feed it to the mapper, which will
     *        return the final value
     * 
     * @return float
     */
    T get() const;
};

#endif