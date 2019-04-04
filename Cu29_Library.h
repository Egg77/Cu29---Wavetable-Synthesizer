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

//Timer:
void ConfigureTimer2(char TimerPeriod_us, char Scalers);

//Setup ADC for reading and write to DAC functions
void ADC_Setup();
void DAC_Setup();
void WriteDAQ(short WriteValue);

//Oscillators:
short FreqArray(void);
short SineArray(void);
short SquareArray(void);
short SawArray(void);

//Key_49 Functions - Converts ADC input to keys, scales timer2 to key frequencies
int 49_key (short n);
int ADC_to_key (char v_in);

//ADSR Envelope Generator Functions - Controls on/off key signal and Envelope
void ADSR (short ADC_GATE);
void attack (short ADC_GATE, short ADC_attack);
void decay (short ADC_GATE, short ADC_decay);
void sustain (short ADC_GATE, short ADC_sustain);
void release (short ADC_GATE, short ADC_release);

#endif
