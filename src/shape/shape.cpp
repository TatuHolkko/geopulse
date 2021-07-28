#include "shape.h"
#include "../utility/utility.h"
#include <GL/glut.h>


Shape::Shape(int n,
             DynamicSet<float> &angles,
             DynamicSet<float> &radii,
             DynamicSet<float> &red,
             DynamicSet<float> &green,
             DynamicSet<float> &blue,
             Timer &t)
{

    for (int i = 0; i < n; i++)
    {
        Vertex v = Vertex(
            angles.generate(t),
            radii.generate(t),
            red.generate(t),
            green.generate(t),
            blue.generate(t));

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
        RGB color1 = previous->getColor();
        RGB color2 = current->getColor();
        RGB colorResult = color1 * 0.5f + color2 * 0.5f;

        glColor3f(colorResult.R, colorResult.G, colorResult.B);

        //start
        Point pos1 = previous->getPos();
        //end
        Point pos2 = current->getPos();

        glVertex3f(pos1.x, pos1.y, 0);
        glVertex3f(pos2.x, pos2.y, 0);

        previous = current;
        current = next(current);
    }

    previous = vertices.begin();

    glEnd();
}