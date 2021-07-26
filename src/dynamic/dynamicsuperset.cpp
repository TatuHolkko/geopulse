#include "dynamicsuperset.h"

template<typename T>
DynamicSuperset<T>::DynamicSuperset(
    MapperFunction fn,
    MapperSuperParameters params,
    InputProvider &ip) : fn(fn),
                         params(params),
                         ip(&ip),
                         n(0)
{
}

template<typename T>
DynamicSuperset<T>::~DynamicSuperset()
{
    for (DynamicSet<T> *dynset : superset)
    {
        delete dynset;
    }
}

template<typename T>
DynamicSet<T> &DynamicSuperset<T>::generate()
{
    MapperParameters newBase = params.base + params.baseDelta * n;
    MapperParameters newDelta = params.deltaBase + params.deltaBaseDelta * n;
    DynamicSet<T> *dynset = new DynamicSet<T>(fn, newBase, newDelta, *ip);

    superset.push_back(dynset);

    n++;

    return *dynset;
}

template class DynamicSuperset<float>;
template class DynamicSuperset<int>;
