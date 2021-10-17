/**
 * @brief Function is a class for defining a function and it's parameters
 * 
 */

#ifndef FUNCTION_H
#define FUNCTION_H

#include "../utility/utility.h"

conf::FunctionParameters operator+(
    const conf::FunctionParameters &a,
    const conf::FunctionParameters &b);

conf::FunctionParameters operator*(
    const conf::FunctionParameters &a,
    const int n);

class Function
{
private:
    FunctionType type;
    conf::FunctionParameters params;
    float sine(float input);
    float halfSine(float input);

public:
    /**
     * @brief Construct a new Mapper object
     * 
     * @param fn Function type
     * @param params Parameters for the function
     */
    Function(FunctionType fn, conf::FunctionParameters params);
    Function();
    float getValue(float input);
};

#endif