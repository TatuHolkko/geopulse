#include "scene/scene.h"
#include "dance/timer.h"
#include <GL/glut.h>

Scene *scene;
Timer *timer;

// tick duration in ms
#define TICK_DURATION 16

#define BPM 175

void redraw()
{
	scene->draw();
}

void tick(int value)
{
	timer->tick();
	glutPostRedisplay();
	glutTimerFunc(TICK_DURATION, &tick, 0);
}

int main(int argc, char *argv[])
{
	timer = new Timer(TICK_DURATION, BPM);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutCreateWindow("GeoPulse");

	scene = new Scene(*timer);

	glutDisplayFunc(redraw);
	glutTimerFunc(TICK_DURATION, &tick, 0);
	glutMainLoop();

	delete scene;
	delete timer;

	return 0;
}