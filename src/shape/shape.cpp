#include "shape.h"
#include "../dynamic/deviator.h"
#include "../dynamic/sequence.h"
#include <GL/glut.h>

Shape::Shape(int n,
             const conf::DeviatorSequence &angleConf,
             const conf::DeviatorSequence &radiusConf,
             const conf::DeviatorSequence &redConf,
             const conf::DeviatorSequence &greenConf,
             const conf::DeviatorSequence &blueConf,
             Timer &t)
{
    conf::DeviatorSequence angleTemp = angleConf;
    // angle 0 must create a regular polygon
    angleTemp.paramSequence.delta.offset += 2 * PI / n;


    Sequence<conf::FunctionParameters> angles_seq(angleTemp.paramSequence.base, angleTemp.paramSequence.delta);
    Sequence<conf::FunctionParameters> radius_seq(radiusConf.paramSequence.base, radiusConf.paramSequence.delta);
    Sequence<conf::FunctionParameters> red_seq(redConf.paramSequence.base, redConf.paramSequence.delta);
    Sequence<conf::FunctionParameters> green_seq(greenConf.paramSequence.base, greenConf.paramSequence.delta);
    Sequence<conf::FunctionParameters> blue_seq(blueConf.paramSequence.base, blueConf.paramSequence.delta);

    for (int i = 0; i < n; i++)
    {
        deviators.push_back(Deviator<float>({angleTemp.type, angles_seq.next()}, t));
        Deviator<float> *angle_dev = &deviators.back();

        deviators.push_back(Deviator<float>({radiusConf.type, radius_seq.next()}, t));
        Deviator<float> *radius_dev = &deviators.back();

        deviators.push_back(Deviator<float>({redConf.type, red_seq.next()}, t));
        Deviator<float> *red_dev = &deviators.back();

        deviators.push_back(Deviator<float>({greenConf.type, green_seq.next()}, t));
        Deviator<float> *green_dev = &deviators.back();

        deviators.push_back(Deviator<float>({blueConf.type, blue_seq.next()}, t));
        Deviator<float> *blue_dev = &deviators.back();

        Vertex v = Vertex(
            *angle_dev,
            *radius_dev,
            *red_dev,
            *green_dev,
            *blue_dev);

        vertices.push_back(v);
    }
}

void Shape::draw() const
{
    glBegin(GL_LINES);

    //init iterator to the second vertex
    std::list<Vertex>::const_iterator previous = prev(vertices.end());
    std::list<Vertex>::const_iterator current = vertices.begin();

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