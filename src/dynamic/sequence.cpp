#include "sequence.h"
#include "../utility/utility.h"

template <typename T>
Sequence<T>::Sequence(
    const T &base,
    const T &delta) : items({}),
                      base(base),
                      delta(delta),
                      index(-1),
                      step(forward)
{
}

template <typename T>
T &Sequence<T>::next()
{
    index += step;

    if(index < 0)
    {
        throw "Sequence::next() call would reduce index below 0";
    }

    if(index + 1 > items.size())
    {
        T new_item = base + delta * items.size();
        items.push_back(new_item);
    }

    return items.at(index);
}

template <typename T>
void Sequence<T>::reset()
{
    index = 0;
}

template <typename T>
void Sequence<T>::reflect(bool inclusive)
{
    switch(step)
    {
        case forward:
            step = backward;
            break;
        case backward:
            step = forward;
            break;
    }
    if(inclusive)
    {
        index -= step;
    }
}

template class Sequence<conf::FunctionParameters>;
template class Sequence<conf::Sequence<conf::FunctionParameters>>;
