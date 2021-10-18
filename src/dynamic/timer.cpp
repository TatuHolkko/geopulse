#include "timer.h"

Timer::Timer(const unsigned int &tickDuration_ms, const float &bpm) : InputProvider()
{
    ticks = 0;
    beats = 0;
    beatsPerTick = bpm / (60 * 1000 / tickDuration_ms);
    ticksMax = BEATS_MAX / beatsPerTick;
}

void Timer::tick()
{
    ticks++;
    if (ticks >= ticksMax)
    {
        ticks = 0;
    }
}

float Timer::getBeats() const
{
    return (float)ticks * (float)beatsPerTick;
}

float Timer::provideInput()
{
    return getBeats();
}