#include "shape.h"
#include <GL/glut.h>

#define PI 3.14159f

Shape::Shape(int n,
             DynamicSet<float> &angles,
             DynamicSet<float> &radii,
             ProviderType providerType,
             DynamicSet<float> &red,
             DynamicSet<float> &green,
             DynamicSet<float> &blue,
             DynamicSet<float> &alpha,
             Timer &t)
{

    for (int i = 0; i < n; i++)
    {
        Vertex v = Vertex(
            angles.generate(t),
            radii.generate(t),
            providerType,
            red.generate(t),
            green.generate(t),
            blue.generate(t),
            alpha.generate(t));

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
        RGBA color1 = previous->getColor();
        RGBA color2 = current->getColor();
        RGBA colorResult = color1 * 0.5f + color2 * 0.5f;

        glColor3f(colorResult.R, colorResult.G, colorResult.B);

        //start
        std::pair<float, float> pos1 = previous->getPos();
        //end
        std::pair<float, float> pos2 = current->getPos();

        glVertex3f(pos1.first, pos1.second, 0);
        glVertex3f(pos2.first, pos2.second, 0);

        previous = current;
        current = next(current);
    }

    previous = vertices.begin();

    glEnd();
}