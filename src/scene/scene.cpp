#include "scene.h"
#include <GL/glut.h>

Scene::Scene(InputProvider& t)
{
    //background
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    //drawing color
    glColor3f(0.0f, 1.0f, 0.0f);

    shapes.push_back(Shape(6, 0.5, t));
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