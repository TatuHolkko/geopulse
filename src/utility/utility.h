#ifndef UTILITY_H
#define UTILITY_H

#define PI 3.1415926535f

#include <list>
#include <string>

typedef std::string str;
typedef str::const_iterator str_cit;

typedef struct StrRange
{
    str_cit start;
    str_cit end;
} StrRange;

typedef struct Point
{
    float x;
    float y;
} Point;

enum FunctionType
{
    Sine,
    HalfSine,
    Square,
    Saw,
    Tri
};

namespace conf
{
    template <typename T>
    struct Sequence
    {
        T base;
        T delta;
    };

    typedef struct FunctionParameters
    {
        float phase;
        float period;
        float amp;
        float offset;
    } FunctionParameters;

    typedef struct DeviatorSequence
    {
        FunctionType type;
        Sequence<FunctionParameters> paramSequence;
    } DeviatorSequence;

    typedef struct DeviatorSequenceSequence
    {
        FunctionType type;
        Sequence<Sequence<FunctionParameters>> paramSequenceSequence;
    } DeviatorSequenceSequence;

    typedef struct Function
    {
        FunctionType type;
        FunctionParameters params;
    } Function;

    typedef struct Cluster
    {
        int vertices;
        int amount;
        DeviatorSequenceSequence angle;
        DeviatorSequenceSequence radius;
        DeviatorSequenceSequence red;
        DeviatorSequenceSequence green;
        DeviatorSequenceSequence blue;
    } Cluster;

    typedef struct Phrase
    {
        float duration;
        std::list<Cluster> clusters;
    } Phrase;

    typedef struct Performance
    {
        float bpm;
        std::list<Phrase> phrases;
    } Performance;
} // namespace conf

conf::FunctionParameters operator*(const conf::FunctionParameters &lhs,
                                   const int &rhs);

conf::FunctionParameters operator+(const conf::FunctionParameters &lhs,
                                   const conf::FunctionParameters &rhs);

conf::Sequence<conf::FunctionParameters> operator*(const conf::Sequence<conf::FunctionParameters> &lhs,
                                                   const int &rhs);

conf::Sequence<conf::FunctionParameters> operator+(const conf::Sequence<conf::FunctionParameters> &lhs,
                                                   const conf::Sequence<conf::FunctionParameters> &rhs);
#endif