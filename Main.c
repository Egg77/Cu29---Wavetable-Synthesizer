#include "Lab2_Library.h"
#include <xc.h>
short SineArray(void);
short SquareArray(void);
short SawArray(void);
short FreqArray(void);
void Lab2_WriteDAQ(short WriteValue);
void Sawtooth_Out(void);

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
    Lab2_ConfigureTimer2(1000);
    int prev = 0;
    char time = 1000;
    int test = 0;
    int button =0;
    int prevstate;
    //This loop runs based on Timer2 rather than __delay_ms or __delay_us
    while(1)
    {
        if(PORTCbits.RC6 != prevstate && PORTCbits.RC6 != 1)
        {   if(button==2)
                button = 0;
            else button++;
        }
        prevstate = PORTCbits.RC6;
        test = PORTCbits.RC6;
        
        if(prev!= test && test != 0)
        {
            time = FreqArray();
            Lab2_ConfigureTimer2(time);
        }
        prev = test;
        short x;
        // Call the SineArray function to make sure it runs quickly
        // enough not to stall the DAC output. Use this in Exercise C.
        if(button == 0)
            x = SineArray();
        else if(button == 1)
            x = SquareArray();
        else
            x = SawArray();
        //short x = SquareArray();
        
        Lab2_WriteDAQ(x);
        
        // Wait until the 100us timer has expired by checking the interrupt flag.
        while(!PIR1bits.TMR2IF);
        
        // Clear the interrupt flag. The timer restarts automatically.
        PIR1bits.TMR2IF = 0;
        
    }
        
    return;
}


short SineArray(void)
{
    static char ArrayIndex = 0;
   const short Array [] = 
    {   128,131,134,137,140,143,146,149,152,155,158,162,165,167,170,173,176,179,
    182,185,188,190,193,196,198,201,203,206,208,211,213,215,218,220,222,224,226,
    228,230,232,234,235,237,238,240,241,243,244,245,246,248,249,250,250,251,252,
    253,253,254,254,254,255,255,255,255,255,255,255,254,254,254,253,253,252,251,
    250,250,249,248,246,245,244,243,241,240,238,237,235,234,232,230,228,226,224,
    222,220,218,215,213,211,208,206,203,201,198,196,193,190,188,185,182,179,176,
    173,170,167,165,162,158,155,152,149,146,143,140,137,134,131,128,124,121,118,
    115,112,109,106,103,100,97,93,90,88,85,82,79,76,73,70,67,65,62,59,57,54,52,49,
    47,44,42,40,37,35,33,31,29,27,25,23,21,20,18,17,15,14,12,11,10,9,7,6,5,5,4,3,
    2,2,1,1,1,0,0,0,0,0,0,0,1,1,1,2,2,3,4,5,5,6,7,9,10,11,12,14,15,17,18,20,21,23,
    25,27,29,31,33,35,37,40,42,44,47,49,52,54,57,59,62,65,67,70,73,76,79,82,85,88,
    90,93,97,100,103,106,109,112,115,118,121,124  
   };
   
    // If the index exceeds the array, reset it.
    if (ArrayIndex >= 255) ArrayIndex = 0;
    
    // Return the next array value and increment the index.
    return Array[ArrayIndex+=4];
    
}

short SquareArray(void)
{
    static char ArrayIndex = 0;
   const short Array [] =
   {
    255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
    255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
    255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
    255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
    255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
    255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
    255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0   
   };
      
    // If the index exceeds the array, reset it.
    if (ArrayIndex >= 255) ArrayIndex = 0;
    
    // Return the next array value and increment the index.
    return Array[ArrayIndex+=4];
}


short SawArray(void)
{
    static char ArrayIndex = 0;
   const short Array [] =
   {
       0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,
       28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,
       53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,
       78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,
       102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,
       121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,
       140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,
       159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,
       178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,
       197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,
       216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,
       235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,
       254,255
   };
      
    // If the index exceeds the array, reset it.
    if (ArrayIndex >= 255) ArrayIndex = 0;
    
    // Return the next array value and increment the index.
    return Array[ArrayIndex+=4];
}

short FreqArray(void)
{
    // Static variables are only initialized the first time. They otherwise
    // keep their values each time a function is called.
    static char ArrayIndex = 0;
    const short Array[] = 
        { 45.45, 42.90, 40.50, 38.22, 36.07,
          34.05, 32.14, 30.33, 28.63,
          27.03, 25.51, 24.08,  22.73};
    // If the index exceeds the array, reset it.
    if (ArrayIndex == 13) ArrayIndex = 0;
    
    // Return the next array value and increment the index.
    return Array[ArrayIndex++];
    
}

void Lab2_WriteDAQ(short WriteValue)
{
    char c = WriteValue & 0xFF;
    DAC1REFL = c;
    char d = WriteValue >> 8;
    DAC1REFH = d;
    DAC1LD =1;
}