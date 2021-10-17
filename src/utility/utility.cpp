#include "utility.h"

conf::FunctionParameters operator*(const conf::FunctionParameters &lhs, const int &rhs)
{
    conf::FunctionParameters f = {
        .phase = lhs.phase * rhs,
        .period = lhs.period * rhs,
        .amp = lhs.amp * rhs,
        .offset = lhs.offset * rhs};
    return f;
}

conf::FunctionParameters operator+(const conf::FunctionParameters &lhs,
                                   const conf::FunctionParameters &rhs)
{
    conf::FunctionParameters f = {
        .phase = lhs.phase + rhs.phase,
        .period = lhs.period + rhs.period,
        .amp = lhs.amp + rhs.amp,
        .offset = lhs.offset + rhs.offset};
    return f;
}

conf::Sequence<conf::FunctionParameters> operator*(const conf::Sequence<conf::FunctionParameters> &lhs, const int &rhs)
{
    conf::Sequence<conf::FunctionParameters> s = {
        .base = lhs.base * rhs,
        .delta = lhs.delta * rhs};
    return s;
}

conf::Sequence<conf::FunctionParameters> operator+(const conf::Sequence<conf::FunctionParameters> &lhs,
                                                   const conf::Sequence<conf::FunctionParameters> &rhs)
{
    conf::Sequence<conf::FunctionParameters> s = {
        .base = lhs.base + rhs.base,
        .delta = lhs.delta + rhs.delta};
    return s;
}