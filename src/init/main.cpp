#include "performance.h"
#include "timer.h"
#include "utility.h"
#include "filehandler.h"
#include "inputparser.h"

#include <iostream>
#include <fstream>
#include <GL/glut.h>
#include <algorithm>
#include <vector>

Performance *performance;
Timer *timer;

// tick duration in ms
#define TICK_DURATION 16

std::string getPath(InputParser input);
void redraw();
void tick(int value);

int main(int argc, char *argv[])
{
	InputParser input(argc, argv);
	conf::Performance perf;
	
	try
	{
		read(perf, getPath(input));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}

	timer = new Timer(perf.bpm);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("GeoPulse");

	performance = new Performance(perf, *timer);

	glutDisplayFunc(redraw);
	glutTimerFunc(TICK_DURATION, &tick, 0);
	glutMainLoop();

	delete performance;
	delete timer;

	return 0;
}


void redraw()
{
	performance->draw();
}

void tick(int value)
{
	timer->tick();
	glutPostRedisplay();
	glutTimerFunc(TICK_DURATION, &tick, 0);
}

std::string getPath(InputParser input)
{
	std::string path = "";
	if(input.cmdOptionExists("-f"))
	{
		path = input.getCmdOption("-f");
		std::ifstream file(path);
		if(!file.is_open())
		{
			std::cout << "Invalid file: " << path << std::endl;
			std::cout << "Defaulting to perf.txt" << std::endl;
			path = "perf.txt";
		}
		else
		{
			file.close();
		}
	}
	else
	{
		path = "perf.txt";
	}
	std::cout << "Performance file: " << path << std::endl;
	return path;
}