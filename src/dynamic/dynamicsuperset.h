/**
 * @file dynamicsuperset.h
 * @brief DynamicSuperset creates simialrily transforming DynamicSet objects.
 */

#ifndef DYNAMICSUPERSET_H
#define DYNAMICSUPERSET_H

#include "dynamicset.h"
#include "inputprovider.h"
#include <list>

/**
 * @brief Parameters for creating several similar Mapper parameter sets
 * 
 * @param base First grand base parameter set from which subsequent base instances are varied from
 * @param baseDelta Changes to grand base after a single base instance is created
 * @param deltaBase Changes to base instance after a single parameter subset is created
 * @param deltaBaseDelta Changes to the deltaBase after a single base instance is created
 */
typedef struct MapperSuperParameters
{
    MapperFunction function;
    MapperParameters base;
    MapperParameters baseDelta;
    MapperParameters deltaBase;
    MapperParameters deltaBaseDelta;
} SuperParameters;

template<typename T>
class DynamicSuperset
{
private:
    std::list<DynamicSet<T> *> superset;
    MapperSuperParameters params;
    InputProvider *ip;
    int n;

public:
    ~DynamicSuperset();

    /**
     * @brief Construct a new DynamicSuperSet object
     * 
     * @param base Base parameters for the first DynamicSet
     * @param subdelta Changes to the subset parameters after each Dynamic creation
     * @param subdeltadelta Changes of the subdelta after each set creation
     * @param superdelta Changes of the subset base after each set creation
     * @param ip Input provider
     */
    DynamicSuperset(
        MapperSuperParameters params,
        InputProvider &ip);

    /**
     * @brief Create a new DynamicSet and adjust parameters
     * 
     * @return DynamicSet&
     */
    DynamicSet<T> &generate();
};

#endif