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
    float sine(const float &input) const;
    float halfSine(const float &input) const;

public:
    /**
     * @brief Construct a new Mapper object
     * 
     * @param fn Function type
     * @param params Parameters for the function
     */
    Function(const FunctionType fn, const conf::FunctionParameters &params);
    Function();
    float getValue(const float &input) const;
};

#endif