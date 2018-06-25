// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // formula
    return ((atof(&fraction[0])) / (atof(&fraction[2]))) * 8;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // errors
    if (note[0] < 65 || note[0] > 71)
    {
        return 1;
    }
    if (note[strlen(note) - 1] < 48 || note[strlen(note) - 1] > 56)
    {
        return 1;
    }
    // go to given octave
    char octave = note[strlen(note) - 1] - 48;
    float frequency_calc;
    float base = 27.5;
    float octave_base = base * pow(2, octave);
    // check for note
    if (note[0] == 66)
    {
        frequency_calc = octave_base * (pow(2, 2 / 12.0));
    }
    else if (note[0] == 67)
    {
        frequency_calc = octave_base / (pow(2, 9 / 12.0));
    }
    else if (note[0] == 68)
    {
        frequency_calc = octave_base / (pow(2.0, 7 / 12.0));
    }
    else if (note[0] == 69)
    {
        frequency_calc = octave_base / (pow(2, 5 / 12.0));
    }
    else if (note[0] == 70)
    {
        frequency_calc = octave_base / (pow(2, 4 / 12.0));
    }
    else if (note[0] == 71)
    {
        frequency_calc = octave_base / (pow(2, 2 / 12.0));
    }
    else
    {
        frequency_calc = octave_base;
    }

    // check for accidental
    if (note[1] == 35)
    {
        frequency_calc = frequency_calc * (pow(2, 1 / 12.0));
    }
    else if (note[1] == 98)
    {
        frequency_calc = frequency_calc / (pow(2, 1 / 12.0));
    }
    return round(frequency_calc);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // input = string fraction
    bool is_rest;

    if (s[0] == '\0')
    {
        is_rest = true;
    }
    else
    {
        is_rest = false;
    }
    return is_rest;
}
