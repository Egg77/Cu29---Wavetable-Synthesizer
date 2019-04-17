#include "Cu29_Library.h"

void main(void)
{
    //Initial Setup Functions
    SetupTimer2();
    DAC_Setup(); //Analog output -> to filter, pre-amp, etc.
    ADC_Setup(); //Configures inputs for CV, Gate, ADSR inputs
    short CV_out; //Stores current value of CV in 16-bits
    short CV_temp;
    unsigned char key_count1 = 0;
    unsigned char key_count2 = 0;
    short on_off; //Stores if any key is on or off (1 or 0)
    char button = 0; //Selects between oscillators - 0 = square, 1 = sawtooth
    char prevstate;
    char test = 0;
    short osc; //Stores current value of output oscillator


    //Main loop
    while (1)
    {
       if(PORTAbits.RA3 != prevstate && PORTAbits.RA3 != 1)
       {   if(button==2) button = 0;
           else button++;
       }
       prevstate = PORTAbits.RA3;
       test = PORTAbits.RA3;

       on_off = RA1; //Check if key is pressed.
       if(on_off == 1)
       {
         //One cycle is used to pre-calculate slower parameters that do not
         //need to be adjusted during note playback.

         CV_out = ADC_CV_Loop(); //27us, 4us without waiting for GO
         CV_temp = CV_out;
         ADC_to_key(CV_out); //55us

         //Playback Loop:
         while(on_off == 1) //Play note as long as key is pressed
         {
           if(button == 0) osc = SquareArray(); //4.6us
           if(button == 1) osc = SawArray(); //4.6us
           WriteDAQ(osc); //3.3us

           //Check if CV has changed every 512 cycles for re-trigger support
           if(key_count1 < 255) key_count1++;
           else if (key_count1 == 255 && key_count2 < 255) key_count2++;
           if(key_count1 == 255 && key_count2 == 255)
           {
              CV_out = ADC_CV_Loop();
              key_count1 = 0;
              key_count2 = 0;
              if(CV_out != CV_temp) break;
           }
           //Wait for Timer2 to end:
           while(!PIR1bits.TMR2IF);
           PIR1bits.TMR2IF = 0;
           on_off = RA1;
         }
       }
    }
    return;
}
