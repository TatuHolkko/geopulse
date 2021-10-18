#ifndef LOGGER_H
#define LOGGER_H

#include "utility.h"

#include <string>

typedef struct {
    str_cit iterator;
} InternalPoint;

typedef struct {
    str_cit iterator;
} ExternalPoint;

typedef struct {
    InternalPoint start;
    InternalPoint end;
} InternalRange;

typedef struct {
    ExternalPoint start;
    ExternalPoint end;
} ExternalRange;

class Logger
{
    const str& original_fileContent;
    const str& internal_fileContent;

    int lineNumber(ExternalPoint point);

    ExternalRange getLine(int location);

    void printRange(StrRange message, bool indent);

    void printString(const str& message);

    int getLocation(InternalPoint point);
    
    void printError(ExternalRange defect, const str& message);

public:

    Logger(const str &original, const str &stripped);

    void errorPoint(InternalPoint defect, const str &message);

    void errorRange(InternalRange defect, const str &message);
};

#endif