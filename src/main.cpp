#include "scene/scene.h"
#include "dynamic/timer.h"
#include "utility/utility.h"
#include <GL/glut.h>

Scene *scene;
Timer *timer;

// tick duration in ms
#define TICK_DURATION 16

#define BPM 174

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

	MapperSuperParameters angle = {
		HalfSine,
		{0, 12, PI / 6, 0}, //base
		{1, 0, 0, 0},	//baseDelta
		{0, 0, 0, 0},	//deltaBase
		{0, 0, 0, 0}	//deltaBaseDelta
	};

	MapperSuperParameters radius = {
		Sine,
		{0, 1, 0, 0.2},	   //base
		{0, 0, 0, 0.2}, //baseDelta
		{0, 0, 0, 0},	   //deltaBase
		{0, 0, 0, 0}	   //deltaBaseDelta
	};

	MapperSuperParameters red = {
		Sine,
		{0, 16, 0.5, 0.5}, //base
		{0, 0, 0, 0}, //baseDelta
		{0, 0, 0, 0}, //deltaBase
		{0, 0, 0, 0}  //deltaBaseDelta
	};
	MapperSuperParameters green = {
		Sine,
		{0, 8, 0.5, 0.5}, //base
		{1, 0, 0, 0}, //baseDelta
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

	scene = new Scene(angle,
					  radius,
					  red,
					  green,
					  blue,
					  *timer);

	glutDisplayFunc(redraw);
	glutTimerFunc(TICK_DURATION, &tick, 0);
	glutMainLoop();

	delete scene;
	delete timer;

	return 0;
}