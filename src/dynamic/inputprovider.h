/**
 * @brief Interface for classes that can offer input into a Dancer object Mapper
 */

#ifndef INPUTPROVIDER_H
#define INPUTPROVIDER_H

class InputProvider
{
public:
    virtual ~InputProvider(){};
    virtual float provideInput() = 0;
};

#endif