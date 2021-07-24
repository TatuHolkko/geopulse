#include "shape.h"
#include <list>

class Scene
{
    float beat;
    std::list<Shape> shapes;

public:
    Scene();
    void draw();
};