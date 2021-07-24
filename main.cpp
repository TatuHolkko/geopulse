#include "scene/scene.h"
#include "dance/timer.h"
#include <GL/glut.h>

Scene *scene;
Timer *timer;

void redraw()
{
	scene->draw();
}

void tick(int value)
{
	timer->tick();
	glutPostRedisplay();
	glutTimerFunc(16, &tick, 1);
}

int main(int argc, char *argv[])
{
	timer = new Timer(16, 120);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutCreateWindow("GeoPulse");

	scene = new Scene(*timer);

	glutDisplayFunc(redraw);
	glutTimerFunc(16, &tick, 1);
	glutMainLoop();

	delete scene;
	delete timer;

	return 0;
}