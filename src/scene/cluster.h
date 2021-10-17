#ifndef CLUSTER_H
#define CLUSTER_H

#include "../dynamic/sequence.h"
#include "../shape/shape.h"
#include <list>

class Cluster
{
    std::list<Shape> shapes;

public:
    Cluster(conf::Cluster conf, Timer &t);

    void draw();
};

#endif