/**
 * @file dynamicset.h
 * @brief DynamicSet is a collection of Dynamic objects that act
 *        similarly.
 */

#ifndef DynamicSET_H
#define DynamicSET_H

#include "dynamic.h"
#include "inputprovider.h"
#include "mapper.h"

#include <list>

template <typename T>
class DynamicSet
{
private:
    std::list<Dynamic<T> *> dynamics;
    MapperFunction fn;
    MapperParameters base;
    MapperParameters delta;
    int n;

public:
    ~DynamicSet();

    /**
     * @brief Construct a new DynamicSet object
     * 
     * @param fn Mapper function type
     * @param base Parameters for the first Dynamic
     * @param delta Parameter changes added after each generate call
     */
    DynamicSet(
        MapperFunction fn,
        MapperParameters base,
        MapperParameters delta);

    /**
     * @brief Create a new Dynamic and adjust parameters
     * 
     * @return Dynamic&
     */
    Dynamic<T> &generate(InputProvider &ip);
};

#endif