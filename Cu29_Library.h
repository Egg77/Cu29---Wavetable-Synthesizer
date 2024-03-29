#ifndef Cu29_LIBRARY_H
#define	Cu29_LIBRARY_H

extern unsigned char samples = 2; //Global sample interval for reading from oscillator tables.

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
void SetupTimer2(void);
void ConfigureTimer2(char TimerPeriod_us, char Scalers);

//Setup ADC for reading and write to DAC functions
void ADC_Setup(void);
short ADC_CV_Loop(void);
unsigned short ADC_GATE_Loop(void);
void DAC_Setup(void);
void WriteDAQ(short WriteValue);

//Oscillators:
short FreqArray(void);
short SineArray(void);
short SquareArray(void);
short SawArray(void);

//Key_49 Functions - Converts ADC input to keys, scales Timer2 to key frequencies
void key_49 (short n);
void ADC_to_key (short ADC_CV);

//Configure PIC PWM Output for use with Buck Booster Circuit:
void PWM_setup (void);

#endif
