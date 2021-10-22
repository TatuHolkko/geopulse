#include "timer.h"

Timer::Timer(const float &bpm) : InputProvider(), beatsPerMinute(bpm)
{
    reset();
}

void Timer::reset()
{
    startTime = high_resolution_clock::now();
    tick();
}

void Timer::tick()
{
    high_resolution_clock::time_point currentTime = high_resolution_clock::now();
    duration<double, std::milli> passedDuration = currentTime - startTime;
    passedMilliseconds = passedDuration.count();
}

float Timer::getBeats() const
{
    return passedMilliseconds / 60000.0 * beatsPerMinute;
}

float Timer::provideInput()
{
    return getBeats();
}