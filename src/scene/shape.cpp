#include "shape.h"
#include <GL/glut.h>

#define PI 3.14159f

Shape::Shape(
    int n, 
    DynamicSet<float>& superOrbitAngles,
    DynamicSet<float>& subOrbitAngles,
    DynamicSet<float>& superOrbitRadii,
    DynamicSet<float>& subOrbitRadii)
{

    for (int i = 0; i < n; i++)
    {
        Vertex v = Vertex(
            // (PI * 2 / n * i)
            superOrbitAngles.generate(), 
            subOrbitAngles.generate(), 
            superOrbitRadii.generate(), 
            subOrbitRadii.generate()
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