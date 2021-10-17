#include "scene/scene.h"
#include "dynamic/timer.h"
#include "utility/utility.h"
#include "filehandler/filehandler.h"

#include <iostream>
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
	std::string path = std::string("perf.txt");

	conf::Performance perf;
	try
	{
		read(perf, path);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}

	timer = new Timer(TICK_DURATION, BPM);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutCreateWindow("GeoPulse");

	scene = new Scene(perf.phrases.front().clusters, *timer);

	glutDisplayFunc(redraw);
	glutTimerFunc(TICK_DURATION, &tick, 0);
	glutMainLoop();

	delete scene;
	delete timer;

	return 0;
}