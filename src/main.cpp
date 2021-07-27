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
		Sine,
		{0, 24, PI, 0}, //base
		{0, 2, 0, 0},	//baseDelta
		{0, 0, 0, 0},	//deltaBase
		{0, 0, 0, 0}	//deltaBaseDelta
	};

	MapperSuperParameters subAngle = {
		Sine,
		{0, 1, 0, 0}, //base
		{0, 0, 0, 0}, //baseDelta
		{0, 0, 0, 0}, //deltaBase
		{0, 0, 0, 0}  //deltaBaseDelta
	};

	MapperSuperParameters superRadius = {
		Sine,
		{0, 1, 0, 0.5},	   //base
		{0, 0, 0.01, 0.1}, //baseDelta
		{0, 0, 0, 0},	   //deltaBase
		{0, 0, 0, 0}	   //deltaBaseDelta
	};

	MapperSuperParameters subRadius = {
		Sine,
		{0, 1, 0, 0}, //base
		{0, 0, 0, 0}, //baseDelta
		{0, 0, 0, 0}, //deltaBase
		{0, 0, 0, 0}  //deltaBaseDelta
	};

	MapperSuperParameters red = {
		Sine,
		{0, 1, 0, 1}, //base
		{0, 0, 0, 0}, //baseDelta
		{0, 0, 0, 0}, //deltaBase
		{0, 0, 0, 0}  //deltaBaseDelta
	};
	MapperSuperParameters green = {
		Sine,
		{0, 1, 0, 0}, //base
		{0, 0, 0, 0}, //baseDelta
		{0, 0, 0, 0}, //deltaBase
		{0, 0, 0, 0}  //deltaBaseDelta
	};
	MapperSuperParameters blue = {
		Sine,
		{0, 1, 0, 0}, //base
		{0, 0, 0, 0}, //baseDelta
		{0, 0, 0, 0}, //deltaBase
		{0, 0, 0, 0}  //deltaBaseDelta
	};
	MapperSuperParameters alpha = {
		Sine,
		{0, 1, 0, 1}, //base
		{0, 0, 0, 0}, //baseDelta
		{0, 0, 0, 0}, //deltaBase
		{0, 0, 0, 0}  //deltaBaseDelta
	};

	scene = new Scene(superAngle,
					  subAngle,
					  superRadius,
					  subRadius,
					  Radius,
					  red,
					  green,
					  blue,
					  alpha,
					  *timer);

	glutDisplayFunc(redraw);
	glutTimerFunc(TICK_DURATION, &tick, 0);
	glutMainLoop();

	delete scene;
	delete timer;

	return 0;
}