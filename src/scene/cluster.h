#ifndef CLUSTER_H
#define CLUSTER_H

#include "../dynamic/sequence.h"
#include "../shape/shape.h"
#include <list>

class Cluster
{
    std::list<Shape> shapes;

public:
    /**
     * @brief Construct a new Cluster object
     * 
     * @param conf Configuration
     * @param t Timer
     */
    Cluster(conf::Cluster conf, Timer &t);

    /**
     * @brief Draw all shapes of this cluster
     * 
     */
    void draw() const;
};

#endif