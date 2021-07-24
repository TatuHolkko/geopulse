/**
 * @file dance.h
 * @brief A Dancer object describes a value that changes over time.
 * 
 * The input provider given in the constructor will be called each 
 * time the value of the Dancer object is retrieved with the get() call.
 * The return value of the input provider together with the mapper function
 * will dictate what the value is.
 */

#include "mapper.h"
#include "inputprovider.h"
#include "../dance/inputprovider.h"

class Dancer
{
private:
    Mapper mapper;
    InputProvider* inputProvider;
    float sine(float value);

public:
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
    float get();
};