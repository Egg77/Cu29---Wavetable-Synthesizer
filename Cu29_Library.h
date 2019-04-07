#ifndef Cu29_LIBRARY_H
#define	Cu29_LIBRARY_H

// Device configuration
#pragma config FOSC = INTOSC // Oscillator Selection Bits->INTOSC oscillator: I/O function on CLKIN pin
#pragma config WDTE = OFF    // Watchdog Timer Enable->WDT disabled
#pragma config PLLEN = ON    // Phase Lock Loop enable->4x PLL is always enabled

// Library Files
#include <stdbool.h>
#include <xc.h>
#include <math.h>

//Define Clock Frequency of 32MHz
#define _XTAL_FREQ 32000000

//Timer:
void ConfigureTimer2(char TimerPeriod_us, char Scalers);

//Setup ADC for reading and write to DAC functions
void ADC_Setup(void);
short ADC_CV_Loop(void);
void DAC_Setup(void);
void WriteDAQ(short WriteValue);

//Oscillators:
short FreqArray(void);
short SineArray(int samples);
short SquareArray(int samples);
short SawArray(int samples);

//Key_49 Functions - Converts ADC input to keys, scales timer2 to key frequencies
int key_49 (short n);
int ADC_to_key (short ADC_CV);

//ADSR Envelope Generator Functions - Controls on/off key signal and Envelope
void ADSR (short ADC_GATE);
void attack (short ADC_GATE, short ADC_attack);
void decay (short ADC_GATE, short ADC_decay);
void sustain (short ADC_GATE, short ADC_sustain);
void release (short ADC_GATE, short ADC_release);

#endif
