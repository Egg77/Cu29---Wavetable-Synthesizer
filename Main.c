#include "Cu29_Library.h"
#include <xc.h>

void WriteDAQ(short WriteValue);

void main(void)
{
     if(1)
    {
        BSR = 0xB;
        DAC1CON0 = 0xA0;
        TRISA = 0xFE;
    }

     ANSELC = 0x00;
     TRISB = 0x00;
     TRISCbits.TRISC7 = 0;
     TRISCbits.TRISC6 = 1;

    //Configure Timer2 to have a period of 100 microseconds.
    ConfigureTimer2(1000,0x0b);
    int prev = 0;
    char time = 1000;
    int test = 0;
    int button =0;
    int prevstate;
    //This loop runs based on Timer2 rather than __delay_ms or __delay_us
    while(1)
    {
        // if(PORTCbits.RC6 != prevstate && PORTCbits.RC6 != 1)
        // {   if(button==2)
        //         button = 0;
        //     else button++;
        // }

        // prevstate = PORTCbits.RC6;
        // test = PORTCbits.RC6;

        // Call the SineArray function to make sure it runs quickly
        // enough not to stall the DAC output.
        if(prev!= test && test != 0)
        {
            time = FreqArray();
            ConfigureTimer2(time,0x0b);
        }

        prev = test;

        short x;
        x = SineArray();

        // if(button == 0)
        //     x = SineArray();
        // else if(button == 1)
        //     x = SquareArray();
        // else
        //     x = SawArray();
        //short x = SquareArray();

        WriteDAQ(x);

        // Wait until the 100us timer has expired by checking the interrupt flag.
        while(!PIR1bits.TMR2IF);

        // Clear the interrupt flag. The timer restarts automatically.
        PIR1bits.TMR2IF = 0;

    }

    return;
}

void WriteDAQ(short WriteValue)
{
    char c = WriteValue & 0xFF;
    DAC1REFL = c;
    char d = WriteValue >> 8;
    DAC1REFH = d;
    DAC1LD =1;
}
