#include "scene.h"
#include <GL/glut.h>

Scene::Scene(InputProvider &ip)
{
    //background
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    //drawing color
    glColor3f(0.0f, 1.0f, 0.0f);

    MapperParameters base = {0, 2, 0.1, 0.5};
    MapperParameters delta = {1, 0, 0, 0};

    this->adset = AdjustableSet(Sine, base, delta, ip);

    shapes.push_back(Shape(10, adset));
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