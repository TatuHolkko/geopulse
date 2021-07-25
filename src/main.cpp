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
	glutInitWindowSize(800, 800);
	glutCreateWindow("GeoPulse");

	MapperParameters base = {0, 6, 0.2, 0.2};
	MapperParameters subdelta = {1, 0, 0, 0};
	MapperParameters subdeltadelta = {0, 0, 0, 0};
	MapperParameters superdelta = {0, 2, -0.04, 0.2};

	scene = new Scene(Sine,
					  base,
					  subdelta,
					  subdeltadelta,
					  superdelta,
					  *timer);

	glutDisplayFunc(redraw);
	glutTimerFunc(TICK_DURATION, &tick, 0);
	glutMainLoop();

	delete scene;
	delete timer;

	return 0;
}