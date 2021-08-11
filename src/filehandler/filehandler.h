#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "../dynamic/mapper.h"
#include <list>
#include <string>

typedef struct FunctionProperty {
    float base;
    float dShape;
    float dVertex;
    float ddVertex;
} FunctionProperty;

typedef struct Function {
    MapperFunction type;
    FunctionProperty phase;
    FunctionProperty period;
    FunctionProperty amplitude;
    FunctionProperty offset;
} Function;

typedef struct ShapeGroup {
    int vertices;
    int amount;
    Function angle;
    Function radius;
} ShapeGroup;

typedef struct Phrase {
    std::list<ShapeGroup> groups;
    int duration;
} Phrase;

typedef struct Performance
{
    float bpm;
    std::list<Phrase> phrases;
} Performance;

void read(const std::string& filepath);

#endif