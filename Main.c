#include "Cu29_Library.h"

void main(void)
{

  //Incomplete new main function. Ultimately want to use this.
  if(1)
  {
    //Initial Setup Functions
    DAC_Setup(); //Analog output -> to filter, pre-amp, etc.
    ADC_Setup(); //Configures inputs for CV, Gate, ADSR inputs
    short CV_out;
    int key_in;
    int osc;

    //Main loop
    while (1)
    {
       CV_out = ADC_CV_Loop();
       key_in = ADC_to_key(CV_out);
       osc = SineArray(key_in);
       WriteDAQ(osc);
    }
  }
    return;
}
