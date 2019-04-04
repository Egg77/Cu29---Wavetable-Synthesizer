#ifndef Cu29_LIBRARY_H
#define	Cu29_LIBRARY_H

// Device configuration
#pragma config FOSC = INTOSC    // Oscillator Selection Bits->INTOSC oscillator: I/O function on CLKIN pin
#pragma config WDTE = OFF    // Watchdog Timer Enable->WDT disabled
#pragma config PLLEN = ON    // Phase Lock Loop enable->4x PLL is always enabled

// Library Files
#include <stdbool.h>
#include <xc.h>
#include <math.h>


//Timer:
void ConfigureTimer2(char TimerPeriod_us, char Scalers);

//Oscillators:
short FreqArray(void);
short SineArray(void);
short SquareArray(void);
short SawArray(void);

//Key_49 Functions - Converts ADC input to keys, scales timer2 to key frequencies
void 49_key (int n);
int ADC_to_key (char v_in);

#endif
