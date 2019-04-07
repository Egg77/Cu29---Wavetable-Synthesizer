#include "Cu29_Library.h"

//Requires: Nothing.
//Promises: Sets up ADC
void ADC_Setup(void)
{

  //Pin RA0, Channel 0:
  TRISAbits.TRISA0 = 1; //Disable PIN RA0 output driver
  ANSA0 = 1; //Configure PIN RA0 as analog
  WPUA0 = 0; //Disable weak pull-ups
  //^^^Repeat as needed for each ADC input!
  //.
  //.
  //.
  ADCON1 = 0b11000000; //Right justify, set conversion clock to F_osc/64,
                       //negative reference to V_ss, positive reference to V_dd
  ADCON0bits.ADON = 1; //Turn on ADC peripheral

}

//Requires: Nothing.
//Promises: Reads ADC input from channel 0 (pin RA0)
short ADC_CV_Loop(void)
{
    short result;
    char high;
    char low;

    ADCON0bits.CHS = 0b00000; //Select Channel 0 (ie. PIN RA0)
    __delay_us(2); //Setup time
    ADCON0bits.GO = 1; //Set GO/DONE bit to 1
    while(ADCON0bits.GO == 1);//Wait for completion poll GO/DONE bit

    high = ADRESH << 8;
    low = ADRESL;
    result = high || low;

    return result; //Return ADRESH+ADRESL
}


//Requires: Nothing.
//Promises: Sets up the DAC for output on Port A.
void DAC_Setup(void)
{
    BSR = 0xB;
    DAC1CON0 = 0xA0;
    TRISA = 0xFE;


}

//Requires: Short type value to write to DAC1
//Promises: Distributes WriteValue across DAC1REFL and DAC1REFH and outputs to DAC1
void WriteDAQ(short WriteValue)
{
    char c = WriteValue & 0xFF;
    DAC1REFL = c;
    char d = WriteValue >> 8;
    DAC1REFH = d;
    DAC1LD = 1;
}
