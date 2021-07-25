/**
 * @brief Mapper is a class for defining a function and it's phase and 
 *        frequency parameters
 * 
 */

#ifndef MAPPER_H
#define MAPPER_H

enum MapFunction
{
    Sine
};

/**
 * @brief Parameters for a given mapper function 
 *
 * @param phase A constant added to the input before evaluation
 * @param period Once input+phase goes beyond this value, the function 
 *               wraps back to the beginning
 * @param amp Scaling of the function
 * @param offset Final offset added to the function value
 */
typedef struct MapperParameters
{
    float phase;
    float period;
    float amp;
    float offset;
} MapperParameters;

MapperParameters operator+(
    const MapperParameters &a,
    const MapperParameters &b);

MapperParameters operator*(
    const MapperParameters &a,
    const int n);

// Mapper function and it's parameters
class Mapper
{
private:
    MapFunction function;
    MapperParameters params;
    float sine(float input);

public:
    /**
     * @brief Construct a new Mapper object
     * 
     * @param fn Function type
     * @param params Parameters for the function
     */
    Mapper(MapFunction fn, MapperParameters params);
    Mapper();
    float getValue(float input);
};

#endif