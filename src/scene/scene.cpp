#include "scene.h"
#include <GL/glut.h>

Scene::Scene(
    MapFunction fn,
    MapperParameters base,
    MapperParameters subdelta,
    MapperParameters subdeltadelta,
    MapperParameters superdelta,
    InputProvider &ip) : superset(AdjustableSuperSet(fn,
                                                     base,
                                                     subdelta,
                                                     subdeltadelta,
                                                     superdelta,
                                                     ip))

{
    //background
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    //drawing color
    glColor3f(0.0f, 1.0f, 0.0f);

    for(int i = 0; i < 6; i++){
        shapes.push_back(Shape(6+2*i, superset.generate()));
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