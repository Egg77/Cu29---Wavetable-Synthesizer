#include "Cu29_Library.h"

void main(void)
{
    //Initial Setup Functions
    DAC_Setup(); //Analog output -> to filter, pre-amp, etc.
    ADC_Setup(); //Configures inputs for CV, Gate, ADSR inputs
    short CV_out; //Stores current value of CV in 16-bits
    short on_off; //Stores if any key is on or off (1 or 0)
    int osc; //Stores current value of output oscillator

    //Main loop
    while (1)
    {
       //Need PWM @ 1.215 kHz for Booster Circuit
       CV_out = ADC_CV_Loop();
       ADC_to_key(CV_out);
       on_off = ADC_GATE_Loop();
       
       //This is temporary - will likely change once ADSR is implemented:
       if(on_off == 1) //Only output when a key is pressed
       {
         osc = SineArray();
         WriteDAQ(osc);
       }
    }
    return;
}
