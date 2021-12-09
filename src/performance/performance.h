#ifndef PERFORMANCE_H
#define PERFORMANCE_H

#include "scene.h"

struct Phrase {
    float duration;
    Scene* scene;
};

class Performance
{
    std::list<Phrase*> phrases;
    Timer* timer;
    float duration;

public:
    /**
     * @brief Construct a new Performance object
     * 
     * @param conf configuration
     * @param t timer
     */
    Performance(conf::Performance conf, Timer &t);

    ~Performance();

    /**
     * @brief Draw the current scene
     * 
     */
    void draw() const;

    /**
     * @brief Get the duration in beats
     * 
     * @return float
     */
    float getDuration();
};

#endif