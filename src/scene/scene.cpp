#include "scene.h"
#include <GL/glut.h>

#define PI 3.14159f

Scene::Scene(MapperSuperParameters angleSuperParams,
             MapperSuperParameters radiusSuperParams,
             MapperSuperParameters redSuperParams,
             MapperSuperParameters greenSuperParams,
             MapperSuperParameters blueSuperParams,
             MapperSuperParameters alphaSuperParams,
             Timer &t) : angleSuperset(angleSuperParams),
                         radiusSuperset(radiusSuperParams),
                         redSuperset(redSuperParams),
                         greenSuperset(greenSuperParams),
                         blueSuperset(blueSuperParams),
                         alphaSuperset(alphaSuperParams)

{
    //background
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    int n_vertices = 6;

    // adjust super orbit angle deltaBase offset so that each vertex has a default angle that will
    // spread the vertices evenly to create a regular polygon
    angleSuperParams.deltaBase.offset += 2.0f * PI / n_vertices;
    angleSuperset = DynamicSuperset<float>(angleSuperParams);

    for (int i = 0; i < 6; i++)
    {

        shapes.push_back(Shape(
            n_vertices,
            angleSuperset.generate(),
            radiusSuperset.generate(),
            redSuperset.generate(),
            greenSuperset.generate(),
            blueSuperset.generate(),
            alphaSuperset.generate(),
            t));
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