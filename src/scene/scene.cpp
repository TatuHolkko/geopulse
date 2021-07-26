#include "scene.h"
#include <GL/glut.h>

Scene::Scene(
    MapperFunction fn,
    MapperSuperParameters superOrbitAngleSuperParams,
    MapperSuperParameters subOrbitAngleSuperParams,
    MapperSuperParameters superOrbitRadiusSuperParams,
    MapperSuperParameters subOrbitRadiusSuperParams,
    InputProvider &ip) : superOrbitAngleSuperset(fn,
                                                 superOrbitAngleSuperParams,
                                                 ip),

                         subOrbitAngleSuperset(fn,
                                               subOrbitAngleSuperParams,
                                               ip),

                         superOrbitRadiusSuperset(fn,
                                                  superOrbitRadiusSuperParams,
                                                  ip),

                         subOrbitRadiusSuperset(fn,
                                                subOrbitRadiusSuperParams,
                                                ip)

{
    //background
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    //drawing color
    glColor3f(0.0f, 1.0f, 0.0f);

    for (int i = 0; i < 3; i++)
    {
        int n_vertices = 6;
        shapes.push_back(Shape(
            n_vertices,
            superOrbitAngleSuperset.generate(),
            subOrbitAngleSuperset.generate(),
            superOrbitRadiusSuperset.generate(),
            subOrbitRadiusSuperset.generate()));
    }
}

void Scene::draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    for (Shape &shape : shapes)
    {
        shape.draw();
    }

    glutSwapBuffers();
}