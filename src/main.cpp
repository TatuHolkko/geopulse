#include "scene/scene.h"
#include "dance/timer.h"
#include <GL/glut.h>

Scene *scene;
Timer *timer;

// tick duration in ms
#define TICK_DURATION 16

#define BPM 175

#define PI 3.14159f

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

	MapperSuperParameters superAngle = {
		{0, 1, 0, 0},		 //base
		{0, 0, 0, 0},		 //baseDelta
		{0, 0, 0, PI / 3.0}, //deltaBase
		{0, 0, 0, 0}		 //deltaBaseDelta
	};

	MapperSuperParameters subAngle = {
		{0, 1, 0, 0}, //base
		{0, 0, 0, 0}, //baseDelta
		{0, 0, 0, 0}, //deltaBase
		{0, 0, 0, 0}  //deltaBaseDelta
	};

	MapperSuperParameters superRadius = {
		{0, 4, 0.1, 0.5}, //base
		{0, 0, 0, 0.2},	  //baseDelta
		{0, 0, 0, 0},	  //deltaBase
		{0, 0, 0, 0}	  //deltaBaseDelta
	};

	MapperSuperParameters subRadius = {
		{0, 1, 0, 0}, //base
		{0, 0, 0, 0}, //baseDelta
		{0, 0, 0, 0}, //deltaBase
		{0, 0, 0, 0}  //deltaBaseDelta
	};

	scene = new Scene(Sine,
					  superAngle,
					  subAngle,
					  superRadius,
					  subRadius,
					  *timer);

	glutDisplayFunc(redraw);
	glutTimerFunc(TICK_DURATION, &tick, 0);
	glutMainLoop();

	delete scene;
	delete timer;

	return 0;
}