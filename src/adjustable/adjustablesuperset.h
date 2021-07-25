/**
 * @file adjustablesuperset.h
 * @brief AdjustableSuperSet creates simialrily transforming AdjustableSet objects.
 */

#ifndef ADJUSTABLESUPERSET_H
#define ADJUSTABLESUPERSET_H

#include "adjustableset.h"
#include <list>

class AdjustableSuperSet {
private:
    std::list<AdjustableSet *> superset;
    MapFunction fn;
    MapperParameters base;
    MapperParameters subdelta;
    MapperParameters subdeltadelta;
    MapperParameters superdelta;
    InputProvider *ip;
    int n;

public:
    ~AdjustableSuperSet();

    /**
     * @brief Construct a new AdjustableSuperSet object
     * 
     * @param fn Mapper function type
     * @param base Base parameters for the first AdjustableSet
     * @param subdelta Changes to the subset parameters after each Adjustable creation
     * @param subdeltadelta Changes of the subdelta after each set creation
     * @param superdelta Changes of the subset base after each set creation
     * @param ip Input provider
     */
    AdjustableSuperSet(
        MapFunction fn,
        MapperParameters base,
        MapperParameters subdelta,
        MapperParameters subdeltadelta,
        MapperParameters superdelta,
        InputProvider &ip);

    /**
     * @brief Create a new AdjustableSet and adjust parameters
     * 
     * @return AdjustableSet&
     */
    AdjustableSet &generate();

};

#endif