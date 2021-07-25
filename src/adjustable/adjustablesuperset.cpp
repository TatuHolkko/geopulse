#include "adjustablesuperset.h"

AdjustableSuperSet::AdjustableSuperSet(
    MapFunction fn,
    MapperParameters base,
    MapperParameters subdelta,
    MapperParameters subdeltadelta,
    MapperParameters superdelta,
    InputProvider &ip) : fn(fn),
                         base(base),
                         subdelta(subdelta),
                         subdeltadelta(subdeltadelta),
                         superdelta(superdelta),
                         ip(&ip),
                         n(0)
{
}

AdjustableSuperSet::~AdjustableSuperSet()
{
    for (AdjustableSet *adset : superset)
    {
        delete adset;
    }
}

AdjustableSet &AdjustableSuperSet::generate()
{
    MapperParameters newBase = base + superdelta * n;
    MapperParameters newDelta = subdelta + subdeltadelta * n;
    AdjustableSet *adset = new AdjustableSet(fn, newBase, newDelta, *ip);

    superset.push_back(adset);

    n++;

    return *adset;
}