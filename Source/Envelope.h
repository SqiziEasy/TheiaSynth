/*
  ==============================================================================

    Envelope.h
    Created: 20 Apr 2024 12:04:22am
    Author:  danila

  ==============================================================================
*/

#pragma once

const float SILENCE = 0.0001f;

class Envelope
{
public:
    float level;
    float attackMultiplier;
    float decayMultiplier;
    float sustainLevel;
    float releaseMultiplier;


    float nextValue()
    {
        level = multiplier * (level - target) + target;

        if (level + target > 3.0f)
        {
            multiplier = decayMultiplier;
            target = sustainLevel;
        }

        return level;
    }

    void reset()
    {
        level = 0.0f;
        target = 0.0f;
        multiplier = 0.0f;
    }

    void release()
    {
        target = 0.0f;
        multiplier = releaseMultiplier;
    }

    inline bool isActive() const
    {
        return level > SILENCE;
    }

    inline bool isInAttack() const
    {
        return target >= 2.0f;
    }

    // without this new notes would never play
    void attack()
    {
        level += SILENCE + SILENCE;
        target = 2.0f;
        multiplier = attackMultiplier;
    }

private:
    float target;
    float multiplier;

};