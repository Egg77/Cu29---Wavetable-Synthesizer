#include "Cu29_Library.h"

// Adapted from Lab2_Time.c, provided in ENCM 369 PIC Lab 2 at the University of Calgary
// REQUIRES: Nothing
// PROMISES: Set the system clock speed to 32MHz.
//           Configure Timer2 to trigger with the given period in microseconds.
//           Start Timer2. It will automatically restart when it finishes.
void SetupTimer2()
{
    //Set the system clock speed to 32MHz.
    OSCCON = 0xF0;

    //Wait for the oscillator to switch to its new speed.
    while(OSCSTATbits.HFIOFR == 0);

    //T2PR: TMR2 PERIOD REGISTER
    T2PR = 119;

    // T2CLKCON: TIMER2 CLOCK SELECTION REGISTER
    T2CLKCON = 0x02;

    // T2CON: TIMERx CONTROL REGISTER
    T2CON = 0xb0;

    // TMR2IF is an interrupt flag, and is set whenever Timer2 expires.
    // We are not using interrupts, but it can still be checked manually.
    // It is cleared here as we start the timer.
    //PIR1bits.TMR2IF = 0;

    return;
}

void ConfigureTimer2(char TimerPeriod_us, char Scalers)
{
    //T2PR: TMR2 PERIOD REGISTER
    T2PR = TimerPeriod_us;
    
    //T2CON: TIMERx CONTROL REGISTER
    T2CON = Scalers;
    
    return;
}