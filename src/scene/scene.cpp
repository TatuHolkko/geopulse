#include "scene.h"
#include <GL/glut.h>

#define PI 3.14159f

Scene::Scene(MapperSuperParameters superOrbitAngleSuperParams,
             MapperSuperParameters subOrbitAngleSuperParams,
             MapperSuperParameters superOrbitRadiusSuperParams,
             MapperSuperParameters subOrbitRadiusSuperParams,
             ProviderType veretxProviderType,
             MapperSuperParameters redSuperParams,
             MapperSuperParameters greenSuperParams,
             MapperSuperParameters blueSuperParams,
             MapperSuperParameters alphaSuperParams,
             Timer &t) : superOrbitAngleSuperset(superOrbitAngleSuperParams),
                         subOrbitAngleSuperset(subOrbitAngleSuperParams),
                         superOrbitRadiusSuperset(superOrbitRadiusSuperParams),
                         subOrbitRadiusSuperset(subOrbitRadiusSuperParams),
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
    superOrbitAngleSuperParams.deltaBase.offset += 2.0f * PI / n_vertices;
    superOrbitAngleSuperset = DynamicSuperset<float>(superOrbitAngleSuperParams);

    for (int i = 0; i < 6; i++)
    {

        shapes.push_back(Shape(
            n_vertices,
            superOrbitAngleSuperset.generate(),
            subOrbitAngleSuperset.generate(),
            superOrbitRadiusSuperset.generate(),
            subOrbitRadiusSuperset.generate(),
            veretxProviderType,
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