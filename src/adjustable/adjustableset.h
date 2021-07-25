/**
 * @file adjustableset.h
 * @brief AdjustableSet is a collection of Adjustable objects that act
 *        similarly.
 */

#ifndef ADJUSTABLESET_H
#define ADJUSTABLESET_H

#include "adjustable.h"
#include <list>

class AdjustableSet
{
private:
    std::list<Adjustable *> adjustables;
    MapFunction fn;
    MapperParameters base;
    MapperParameters delta;
    InputProvider *ip;
    int n;

public:
    AdjustableSet();
    ~AdjustableSet();

    /**
     * @brief Construct a new Adjustable Set object
     * 
     * @param fn Mapper function type
     * @param base Parameters for the first Adjustable
     * @param delta Parameter changes added after each generate call
     */
    AdjustableSet(
        MapFunction fn,
        MapperParameters base,
        MapperParameters delta,
        InputProvider &ip);

    /**
     * @brief Create a new Adjustable and adjust parameters
     * 
     * @return Adjustable&
     */
    Adjustable &generate();

    /**
     * @brief Create a constant Adjustable without changing the parameters
     * 
     * @param value The constant value
     * 
     * @return Adjustable& 
     */
    Adjustable &constant(float value);
};

#endif