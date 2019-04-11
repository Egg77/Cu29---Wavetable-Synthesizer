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
    TRISCbits.TRISC6 = 0;
    
    //Delay Testing Loop
    
//       while(1)
//    {
//        RC6 = 1;
////            CV_out = ADC_CV_Loop();
//////            
//////           if(PIR1bits.ADIF == 1)
//////            {
////                ADC_to_key(CV_out); 
//////            }
//        RC6 = 0;
//    }
    
    
    //Main loop
    while (1)
    {   
       on_off = RA1; //Check if key is pressed.
       
       if(on_off == 1)
       {
          CV_out = ADC_CV_Loop();
           if(PIR1bits.ADIF == 1)
            {
                ADC_to_key(CV_out); 
            }
          osc = SineArray();
          WriteDAQ(osc);
          while(!PIR1bits.TMR2IF);
          PIR1bits.TMR2IF = 0;
       }    
    }
    return;
}
