#include "dynamicset.h"
#include "dancer.h"

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
    MapperParameters delta) : fn(fn),
                              base(base),
                              delta(delta),
                              n(0)
{
}

template <typename T>
Dynamic<T> &DynamicSet<T>::generate(InputProvider &ip)
{
    MapperParameters newParams = base + delta * n;
    Mapper mapper = Mapper(fn, newParams);
    Dynamic<T> *dyn = new Dancer<T>(mapper, ip);

    dynamics.push_back(dyn);

    n++;

    return *dyn;
}

template class DynamicSet<float>;
template class DynamicSet<int>;