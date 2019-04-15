#include "Cu29_Library.h"

//Requires: Nothing.
//Promises: Sets up the DAC for output on Port A.
void DAC_Setup(void)
{
    BSR = 0xB;
    DAC1CON0 = 0xA0;
    TRISAbits.TRISA2 = 0;
    TRISAbits.TRISA1 = 1;
    ANSA1 = 0;
}

//Requires: Nothing.
//Promises: Sets up ADC
void ADC_Setup(void)
{
  //Pin RA0, Channel 0 - CV Input:
  TRISAbits.TRISA0 = 1; //Disable PIN RA0 output driver
  ANSA0 = 1; //Configure PIN RA0 as analog
  WPUA0 = 0; //Disable weak pull-ups,


  //Pin Rxx, Channel x - x Input:
  //TRISxbits.TRISx1 = ??; //Disable PIN RA1 output driver
  //ANSx1 = 1; //Configure PIN RA1 as analog
  //WPUx1 = 0; //Disable weak pull-ups

  //^^^Repeat as needed for each ADC input^^^

  ADCON1 = 0b11100000; //Right justify, set conversion clock to F_osc/64,
  ADCON0bits.ADON = 1; //Turn on ADC peripheral
}

//Requires: Nothing.
//Promises: Reads ADC input from channel 0 (pin RA0) from external CV, returns 16-bit value.
short ADC_CV_Loop(void)
{
    short result;
    short high;
    short low;

    ADCON0bits.CHS = 0b00000; //Select Channel 0 (ie. PIN RA0)
    __delay_us(2); //Setup time
    ADCON0bits.GO = 1; //Set GO/DONE bit to 1
    
    while(ADCON0bits.GO == 1); 
    
    high = ADRESH;
    high = high << 8;
    low = ADRESL;
    result = high | low;

    return result;
}

//Requires: Nothing.
//Promises: Reads ADC input from channel 1 (pin RAx) from external GATE,returns
//          1 or 0, for on or off respectively.

unsigned short ADC_GATE_Loop(void)
{
  ADCON0bits.CHS = 0b00001; //Select Channel 1 (ie. PIN RA1)
  __delay_us(0.125); //Setup time
  ADCON0bits.GO = 1; //Set GO/DONE bit to 1
  while(ADCON0bits.GO == 1); //Wait for completion poll GO/DONE bit

  if(ADRESH != 0) return 1;
  if(ADRESH == 0) return 0;
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
