/*
  ==============================================================================

    NoiceGenerator.h
    Created: 9 Apr 2024 10:40:38pm
    Author:  danila

  ==============================================================================
*/

#pragma once

class NoiseGenerator
{
public:
    void reset()
    {
        noiseSeed = 22222;
    }

    float nextValue()
    {
        // Generate the next integer pseudo-random number
        noiseSeed = noiseSeed * 196314165 + 907633515;

        // Convert the integer to a float, to get a number between 2 and 4.
        unsigned int r = (noiseSeed & 0x7FFFFF) + 0x40000000;
        float noise = *(float*)&r;

        // Subtract 3 to get the float into the range [-1, 1].
        return noise - 3.0f;
    }

private:
    unsigned int noiseSeed;
};