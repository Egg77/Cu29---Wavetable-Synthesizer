#include "Cu29_Library.h"

//Requires:
//Promises:
void ADC_Setup()
{


}


//Requires:
//Promises:
void DAC_Setup()
{


}

//Requires: Short type value to write to DAC1
//Promises: Distributes WriteValue across DAC1REFL and DAC1REFH and outputs to DAC1
void WriteDAQ(short WriteValue)
{
    char c = WriteValue & 0xFF;
    DAC1REFL = c;
    char d = WriteValue >> 8;
    DAC1REFH = d;
    DAC1LD = 1;
}
