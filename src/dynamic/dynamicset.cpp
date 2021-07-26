#include "dynamicset.h"
#include "../dance/dance.h"

template <typename T>
DynamicSet<T>::~DynamicSet()
{
    for (Dynamic<T> *dyn : dynamics)
    {
        delete dyn;
    }
}

template <typename T>
DynamicSet<T>::DynamicSet(
    MapperFunction fn,
    MapperParameters base,
    MapperParameters delta,
    InputProvider &ip) : fn(fn),
                         base(base),
                         delta(delta),
                         ip(&ip),
                         n(0)
{
}

template <typename T>
Dynamic<T> &DynamicSet<T>::generate()
{
    MapperParameters newParams = base + delta * n;
    Mapper mapper = Mapper(fn, newParams);
    Dynamic<T> *dyn = new Dancer<T>(mapper, *ip);

    dynamics.push_back(dyn);

    n++;

    return *dyn;
}

template class DynamicSet<float>;
template class DynamicSet<int>;