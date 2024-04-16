/*
  ==============================================================================

    Voice.h
    Created: 9 Apr 2024 9:40:07pm
    Author:  danila

  ==============================================================================
*/

#pragma once

#include "Oscillator.h"

struct Voice
{
    int note;
    Oscillator osc;
    float saw;

    void reset()
    {
        note = 0;
        osc.reset();
        saw = 0.0f;
    }

    float render()
    {
        float sample = osc.nextSample();
        saw = saw * 0.997f + sample;
        return saw;
    }

};