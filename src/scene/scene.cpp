#include "scene.h"
#include "../utility/utility.h"
#include <GL/glut.h>

Scene::Scene(const std::list<conf::Cluster> &clusters,
             Timer &t) : clusters({})
{
    //background
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    for (const conf::Cluster &clustConf : clusters)
    {
        this->clusters.push_back(Cluster(clustConf, t));
    }
}

void Scene::draw() const
{
    glClear(GL_COLOR_BUFFER_BIT);

    for (const Cluster &cluster : clusters)
    {
        cluster.draw();
    }

    glutSwapBuffers();
}