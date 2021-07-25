/**
 * @file adjustable.h
 * @brief Adjustable is a class that offers the possibility to either animate
 *        a value using a Dancer or fix the value to a constant.
 * 
 */

#ifndef ADJUSTABLE_H
#define ADJUSTABLE_H

#include "../dance/dance.h"

class Adjustable
{
private:
    float defaultValue;
    Dancer dancer;
    bool fixed;

public:
    /**
     * @brief Construct a new Adjustable object
     * 
     * @param value Default value to use when fixed
     * @param fixed If true use default value instead of the Dancer object
     * @param m Mapper for the Dancer object
     * @param ip input provider
     */
    Adjustable(float value, bool fixed, Mapper m, InputProvider &ip);
    /**
     * @brief Construct a new Adjustable object that is fixed
     * 
     * @param value Default value
     * 
     */
    Adjustable(float value);
    /**
     * @brief Construct a new Adjustable object defaulting to zero and fixed
     * 
     */
    Adjustable();

    /**
     * @brief Get the current value
     * 
     * @return float 
     */
    float get();

    /**
     * @brief Set whether to use the default value or not
     * 
     * @param value True for default value, false for Dancer object
     */
    void setFixed(bool value);
};

#endif