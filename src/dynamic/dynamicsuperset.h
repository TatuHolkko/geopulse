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
    int n;

public:
    ~DynamicSuperset();

    /**
     * @brief Construct a new DynamicSuperset object
     * 
     * @param params super parameters
     */
    DynamicSuperset(MapperSuperParameters params);

    /**
     * @brief Create a new DynamicSet and adjust parameters
     * 
     * @return DynamicSet&
     */
    DynamicSet<T> &generate();
};

#endif