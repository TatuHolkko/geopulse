/**
 * @file sequence.h
 * @brief Sequence is an object that offers a stream of similar objects
 * 
 * The stream starts at a given object, after which a delta value is added to the starting
 * value for each next item in the sequence.
 */

#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <vector>

enum Step
{
    forward = 1,
    backward = -1
};

template <typename T>
class Sequence
{
private:
    std::vector<T> items;
    T base;
    T delta;
    int index;
    Step step;

public:
    /**
     * @brief Construct a new Sequence object
     * 
     * @param base Starting value of the sequence
     * @param delta Difference between adjacent sequence objects
     */
    Sequence(const T &base, const T &delta);

    /**
     * @brief Create a new object adjusted by delta
     * 
     * @return T&
     */
    T &next();

    /**
     * @brief Change the direction of delta
     * 
     * @param inclusive if true, next() will not add delta during next call
     * 
     * The inclusive parameter in effect determines whether the mirror
     * is placed at an element or in between two elements
     */
    void reflect(bool inclusive);

    /**
     * @brief Reset current item to base
     */
    void reset();
};

#endif