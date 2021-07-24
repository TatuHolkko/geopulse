#include "shape.h"
#include "../dance/inputprovider.h"
#include <list>

class Scene
{
    float beat;
    std::list<Shape> shapes;

public:
    Scene(InputProvider& t);
    void draw();
};