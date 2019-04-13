#include "Cu29_Library.h"

void main(void)
{
    //Initial Setup Functions
    SetupTimer2();
    DAC_Setup(); //Analog output -> to filter, pre-amp, etc.
    ADC_Setup(); //Configures inputs for CV, Gate, ADSR inputs
    short CV_out; //Stores current value of CV in 16-bits
    short on_off; //Stores if any key is on or off (1 or 0)
    int osc; //Stores current value of output oscillator
    TRISCbits.TRISC6 = 0; //Enable RC6 for testing purposes.
    
    
    ADCON0bits.CHS = 0b00000; //Select Channel 0 (ie. PIN RA0) - put back into ADC_CV_Loop
    //Main loop
    while (1)
    {   
       on_off = RA1; //Check if key is pressed.
              
       if(on_off == 1)
       {
         //Read ADC to determine key pressed
         //Read ADC: 27us, 4us without waiting for GO
         ADCON0bits.GO = 1; //Set GO/DONE bit to 1
    
         while(ADCON0bits.GO == 1); 
                
         CV_out = ADRESH;
         CV_out = (CV_out << 8) | ADRESL;
            
         //Look up timer value corresponding to key frequency, set the timer
         ADC_to_key(CV_out); //35 us, 86us
             
         while(on_off == 1) //Play note as long as key is pressed
         {
           osc = SineArray(); //4.6us
           WriteDAQ(osc); //3.3us
           while(!PIR1bits.TMR2IF);
           PIR1bits.TMR2IF = 0;
           on_off = RA1; //Check if key is still pressed.
         }
       }    
    }
    return;
}
