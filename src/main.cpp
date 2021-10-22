#include "scene/scene.h"
#include "dynamic/timer.h"
#include "utility/utility.h"
#include "filehandler/filehandler.h"

#include <iostream>
#include <fstream>
#include <GL/glut.h>
#include <algorithm>
#include <vector>

Scene *scene;
Timer *timer;

// tick duration in ms
#define TICK_DURATION 16

class InputParser{
    public:
        InputParser (int &argc, char **argv){
            for (int i=1; i < argc; ++i)
                this->tokens.push_back(std::string(argv[i]));
        }
        /// @author iain
        const std::string& getCmdOption(const std::string &option) const{
            std::vector<std::string>::const_iterator itr;
            itr =  std::find(this->tokens.begin(), this->tokens.end(), option);
            if (itr != this->tokens.end() && ++itr != this->tokens.end()){
                return *itr;
            }
            static const std::string empty_string("");
            return empty_string;
        }
        /// @author iain
        bool cmdOptionExists(const std::string &option) const{
            return std::find(this->tokens.begin(), this->tokens.end(), option)
                   != this->tokens.end();
        }
    private:
        std::vector <std::string> tokens;
};

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

	timer = new Timer(TICK_DURATION, perf.bpm);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("GeoPulse");

	scene = new Scene(perf.phrases.front().clusters, *timer);

	glutDisplayFunc(redraw);
	glutTimerFunc(TICK_DURATION, &tick, 0);
	glutMainLoop();

	delete scene;
	delete timer;

	return 0;
}


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