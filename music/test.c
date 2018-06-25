#include <cs50.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(void)
{
    string note = get_string("enter note:  ");

    // errors
    if (note[0] < 65 || note[0] > 71)
    {
        printf("Please write a note like A-G\n");
        return 1;
    }
    if (note[strlen(note) - 1] < 48 || note[strlen(note) - 1] > 56)
    {
        printf("Please write an octave like 0-8\n");
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
        frequency_calc = octave_base * (pow(2, 2/12.0));
        printf("B\n");
    }
    else if (note[0] == 67)
    {
        frequency_calc = octave_base / (pow(2, 9/12.0));
        printf("C\n");
    }
    else if (note[0] == 68)
    {
        frequency_calc = octave_base / (pow(2.0, 7.0/12.0));
        printf("D\n");
    }
    else if (note[0] == 69)
    {
        frequency_calc = octave_base / (pow(2, 5/12.0));
        printf("E\n");
    }
    else if (note[0] == 70)
    {
        frequency_calc = octave_base / (pow(2, 4/12.0));
        printf("F\n");
    }
    else if (note[0] == 71)
    {
        frequency_calc = octave_base / (pow(2, 2/12.0));
        printf("G\n");
    }
    else
    {
        frequency_calc = octave_base;
    }

    // check for accidental
    if (note[1] == 35)
    {
        frequency_calc = frequency_calc * (pow(2, 1/12.0));
    }
    else if (note[1] == 98)
    {
        frequency_calc = frequency_calc / (pow(2, 1/12.0));
    }
    int frequency = round(frequency_calc);
    printf("%i\n", frequency);
}