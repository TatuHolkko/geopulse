/**
 * @brief A class for keeping record of time
 * 
 */

#ifndef TIMER_H
#define TIMER_H

#include "inputprovider.h"

#include <chrono>

using namespace std::chrono;

// number at which the beats wrap back to zero
#define BEATS_MAX 360

class Timer : public InputProvider
{
private:
    
    high_resolution_clock::time_point startTime;

    double passedMilliseconds;

    float beatsPerMinute;

public:
    /**
     * @brief Create the Timer object
     * 
     * @param bpm Beats per minute
     */
    Timer(const float &bpm);

    /**
     * @brief Reset beats and align beats with current time
     * 
     */
    void reset();

    /**
     * @brief Update internal passed time
     * 
     */
    void tick();

    /**
     * @brief Get the number of beats passed
     * 
     * @return float 
     */
    float getBeats() const;

    float provideInput();
};

#endif