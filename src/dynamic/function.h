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
     * @brief Construct a new Function object
     * 
     * @param fn Function type
     * @param params Parameters for the function
     */
    Function(const FunctionType fn, const conf::FunctionParameters &params);

    /**
     * @brief Construct a new Function object with default parameters
     * 
     */
    Function();

    /**
     * @brief Get the value of the function for a given input
     * 
     * @param input Input variable of the function
     * @return float Value of the function
     */
    float getValue(const float &input) const;
};

#endif