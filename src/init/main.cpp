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
#include <string>
#include <FreeImage.h>

Performance *performance;
Timer *timer;

// tick duration in ms
#define TICK_DURATION 16

std::string getPath(InputParser input);
void redraw();
void tick(int value);

int width = 1920;
int height = 1080;

long n = 0;

uint8_t* pixels = new uint8_t[3 * width * height];

void saveScreen()
{	
	const char* filename = (std::string("images/") + std::to_string(n) + std::string(".jpeg")).c_str();
	glReadPixels(0, 0, width, height, GL_BGR, GL_UNSIGNED_BYTE, pixels);
    
	FIBITMAP* image = FreeImage_ConvertFromRawBits(pixels, width, height, 3 * width, 24, 0x0000FF, 0xFF0000, 0x00FF00, false);
	FreeImage_Save(FIF_JPEG, image, filename, 0);
	n++;
}

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
	if(n <= 3177)
	{
		saveScreen();
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