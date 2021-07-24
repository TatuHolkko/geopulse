/**
 * @brief A class for keeping record of time
 * 
 */

#ifndef TIMER_H
#define TIMER_H

#include "inputprovider.h"

// number at which the beats wrap back to zero
#define BEATS_MAX 64

class Timer : public InputProvider {
private:
    
    unsigned long ticks;
    unsigned long ticksMax;
    
    unsigned int beats;

    float beatsPerTick;
    

public:
    /**
     * @brief Create the Timer object
     * 
     * @param tickDuration_ms number of milliseconds per tick
     * @param bpm Beats per minute
     */
    Timer(unsigned int tickDuration_ms, float bpm);

    /**
     * @brief Increment the tick counter and other counters
     *        accordingly.
     * 
     */
    void tick();

    /**
     * @brief Get the number of beats passed
     * 
     * @return float 
     */
    float getBeats();

    float provideInput();
};

#endif