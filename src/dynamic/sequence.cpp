#include "sequence.h"
#include "../utility/utility.h"

template <typename T>
Sequence<T>::Sequence(
    T base,
    T delta) : items({}),
               base(base),
               delta(delta)
{
}

template <typename T>
T &Sequence<T>::next()
{
    T new_item = base + delta * items.size();

    items.push_back(new_item);

    return items.back();
}

template class Sequence<conf::FunctionParameters>;
template class Sequence<conf::Sequence<conf::FunctionParameters>>;
