#include "cluster.h"
#include "shape.h"
#include "inputprovider.h"
#include <list>

#ifndef SCENE_H
#define SCENE_H

class Scene
{
    std::list<Cluster> clusters;

public:
    /**
     * @brief Construct a new Scene object
     * 
     * @param clusters list of cluster configurations
     * @param t timer
     */
    Scene(const std::list<conf::Cluster> &clusters,
          Timer &t);

    /**
     * @brief Draw all clusters in this scene
     * 
     */
    void draw() const;
};

#endif