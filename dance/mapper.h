/**
 * @brief Mapper is a class for defining a function and it's phase and 
 *        frequency parameters
 * 
 */

enum MapFunction
{
    Sine
};

// Mapper function and it's parameters
class Mapper
{
private:
    MapFunction function;
    float phase;
    float period;
    float amp;
    float offset;
    float sine(float input);

public:
    /**
     * @brief Construct a new Mapper object
     * 
     * @param fn Function type
     * @param phase A constant added to the input before evaluation
     * @param period Once input+phase goes beyond this value, the function 
     *               wraps back to the beginning
     * @param amp Scaling of the function
     * @param offset Final offset added to the function value
     */
    Mapper(MapFunction fn, float phase, float period, float amp, float offset);
    Mapper();
    float getValue(float input);
};