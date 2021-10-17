/**
 * @file sequence.h
 * @brief Sequence is an object that offers a stream of similar objects
 * 
 * The stream starts at a given object, after which a delta value is added to the starting
 * value for each next item in the sequence.
 */

#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <list>

template <typename T>
class Sequence
{
private:
    std::list<T> items;
    T base;
    T delta;

public:
    /**
     * @brief Construct a new Sequence object
     * 
     * @param base Starting value of the sequence
     * @param delta Difference between adjacent sequence objects
     */
    Sequence(T base, T delta);

    /**
     * @brief Add delta and create a new object
     * 
     * @return T&
     */
    T &next();
};

#endif