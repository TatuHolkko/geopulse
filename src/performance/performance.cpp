#include "performance.h"

#include <cmath>

Performance::Performance(const conf::Performance conf, Timer &t) : phrases({}), timer(&t), duration(0)
{
    for (const conf::Phrase &phraseConf : conf.phrases)
    {
        Phrase *p = new Phrase();
        p->duration = phraseConf.duration;
        p->scene = new Scene(phraseConf.clusters, t);
        phrases.push_back(p);

        duration += p->duration;
    }
}

Performance::~Performance()
{
    for (const Phrase *p : phrases)
    {
        delete p->scene;
        delete p;
    }
}

void Performance::draw() const
{
    float currentBeat = std::fmod(timer->getBeats(), duration);
    float pastDurations = 0;
    for (const Phrase *phrase : phrases)
    {
        pastDurations += phrase->duration;
        if (currentBeat < pastDurations)
        {
            phrase->scene->draw();
            break;
        }
    }
}

float Performance::getDuration()
{
    return duration;
}