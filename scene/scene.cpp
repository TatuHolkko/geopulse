#include "scene.h"

#include <GL/glut.h>

Scene::Scene(){

	//background
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f );

	//drawing color
	glColor3f(0.0f, 1.0f, 0.0f);
}

void Scene::draw() {

    GLfloat x,y;

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);

    x = 0.5f;
    y = 0.5f;
    glVertex3f(x, y, 0);
    x = 1.0f;
    y = 1.0f;
    glVertex3f(x, y, 0);

    glEnd();

    glutSwapBuffers();
}