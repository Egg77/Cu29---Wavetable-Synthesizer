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
    int osc; //Stores current value of output oscillator

    //Function test loop
    #if 0
    TRISCbits.TRISC6 = 0;
    while(1)
    {
         RC6 = 1;
         //Put function to test here
         RC6 = 0;
    }
    #endif

    //Main loop
    #if 1
    while (1)
    {
       on_off = RA1; //Check if key is pressed.

       if(on_off == 1)
       {
         //Gate OFF portion of loop is used to pre-calculate slower parameters that
         //do not need to be adjusted during note playback. This includes waveform selection
         //and all ADSR parameters.

         CV_out = ADC_CV_Loop(); //27us, 4us without waiting for GO
         CV_temp = CV_out;

         //Look up timer value corresponding to key frequency, set the timer
         ADC_to_key(CV_out); //55us

         while(on_off == 1) //Play note as long as key is pressed
         {
           if(key_count1 < 255) key_count1++;
           else if (key_count1 == 255 && key_count2 < 255) key_count2++;
           if(key_count1 == 255 && key_count2 == 255)
           {
            short high; //Consider converting these to chars and only using high for this part
            short low;

            ADCON0bits.CHS = 0b00000; //Select Channel 0 (ie. PIN RA0)
            __delay_us(2); //Setup time
            ADCON0bits.GO = 1; //Set GO/DONE bit to 1

            while(ADCON0bits.GO == 1);

            high = ADRESH;
            high = high << 8;
            low = ADRESL;
            CV_out = high | low;
            key_count1 = 0;
            key_count2 = 0;
            if(CV_out != CV_temp) break;
           }

           osc = SineArray(); //4.6us
           WriteDAQ(osc); //3.3us


           while(!PIR1bits.TMR2IF);
           PIR1bits.TMR2IF = 0;
           on_off = RA1; //Check if key is still pressed.
         }
       }
    }
    #endif

    return;
}
