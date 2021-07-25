#include "shape.h"
#include <GL/glut.h>

#define PI 3.14159f

Shape::Shape(int n, float r, InputProvider& ip)
{

    MapperParameters base {0, 1, 0.1, 0.5}; 
    MapperParameters delta{0, 0, 0, 0};

    adjustables = AdjustableSet(Sine, base, delta, ip);
    for (int i = 0; i < n; i++)
    {
        Vertex v = Vertex(
            Adjustable(PI * 2 / n * i), 
            Adjustable(0), 
            adjustables.generate(), 
            Adjustable(0)
            );

        vertices.push_back(v);
    }
}

void Shape::draw()
{
    glBegin(GL_LINES);

    //init iterator to the second vertex
    std::list<Vertex>::iterator previous = prev(vertices.end());
    std::list<Vertex>::iterator current = vertices.begin();

    while (current != vertices.end())
    {
        //start
        std::pair<float, float> pos = previous->getPos();
        glVertex3f(pos.first, pos.second, 0);

        //end
        pos = current->getPos();
        glVertex3f(pos.first, pos.second, 0);

        previous = current;
        current = next(current);
    }

    previous = vertices.begin();

    glEnd();
}