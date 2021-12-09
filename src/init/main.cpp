#include "performance.h"
#include "timer.h"
#include "utility.h"
#include "filehandler.h"
#include "inputparser.h"
#include "export.h"

#include <iostream>
#include <fstream>
#include <GL/glut.h>
#include <algorithm>
#include <vector>
#include <string>

Performance *performance;
Timer *timer;

// tick duration in ms
#define TICK_DURATION 16

std::string getPath(InputParser input);
void redraw();
void tick(int value);

int width = 1920;
int height = 1080;

bool exportActive = false;
Export* exp = nullptr;

int main(int argc, char *argv[])
{
	InputParser input(argc, argv);

	conf::Performance perf;
	
	if(!read(perf, getPath(input)))
	{
		return 1;
	}

	timer = new Timer(perf.bpm);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1920, 1080);
	glutCreateWindow("GeoPulse");
	glLineWidth(2);

	performance = new Performance(perf, *timer);

	if (input.cmdOptionExists("-e"))
	{
		exp = new Export(1000.0/TICK_DURATION, perf.bpm, performance->getDuration(), width, height);
		exportActive = true;
	}

	glutDisplayFunc(redraw);

	glutTimerFunc(TICK_DURATION, &tick, 0);
	glutMainLoop();

	delete performance;
	delete timer;
	delete exp;

	return 0;
}

void redraw()
{
	performance->draw();
	if (exportActive)
	{
		exp->displayUpdated();
	}
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