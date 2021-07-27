#include "scene.h"
#include <GL/glut.h>

#define PI 3.14159f

Scene::Scene(
    MapperSuperParameters superOrbitAngleSuperParams,
    MapperSuperParameters subOrbitAngleSuperParams,
    MapperSuperParameters superOrbitRadiusSuperParams,
    MapperSuperParameters subOrbitRadiusSuperParams,
    InputProvider &ip) : superOrbitAngleSuperset(superOrbitAngleSuperParams,
                                                 ip),

                         subOrbitAngleSuperset(subOrbitAngleSuperParams,
                                               ip),

                         superOrbitRadiusSuperset(superOrbitRadiusSuperParams,
                                                  ip),

                         subOrbitRadiusSuperset(subOrbitRadiusSuperParams,
                                                ip)

{
    //background
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    //drawing color
    glColor3f(0.0f, 1.0f, 0.0f);

    int n_vertices = 6;

    for (int i = 0; i < 6; i++)
    {
        
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