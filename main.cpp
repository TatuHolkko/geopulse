#include "scene/scene.h"
#include <GL/glut.h>

Scene* scene;

void redraw(){
	scene->draw();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600,600);
	glutCreateWindow("GeoPulse");

	scene = new Scene();

	glutDisplayFunc(redraw);
	glutMainLoop();

	delete scene;

	return 0;
}