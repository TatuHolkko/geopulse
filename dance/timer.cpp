#include "timer.h"

Timer::Timer(unsigned int tickDuration_ms, float bpm) : InputProvider()
{
    ticks = 0;
    beats = 0;
    beatsPerTick = bpm / (60 * 1000 / tickDuration_ms);
    ticksMax = BEATS_MAX / beatsPerTick;
}

void Timer::tick(){
    ticks++;
    if (ticks >= ticksMax){
        ticks = 0;
    }
}

float Timer::getBeats(){
    return (float)ticks * (float)beatsPerTick;
}

float Timer::provideInput(){
    return getBeats();
}