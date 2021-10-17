#ifndef LOGGER_H
#define LOGGER_H

#include "utility.h"

#include <string>


class Logger
{
    const str& original_fileContent;
    const str& internal_fileContent;

    int lineNumber(int location);

    StrRange getLine(int location);

    void printRange(StrRange message, bool indent);

    void printString(const str& message);

    void step(str_cit& iterator);

    int getLocation(str_cit internalLocation);
    
public:

    Logger(const str &original, const str &stripped);

    void errorPoint(str_cit iterator, const str &message);

    void errorRange(StrRange range, const str &message);
};

#endif