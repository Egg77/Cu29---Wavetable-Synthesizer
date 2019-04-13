#if 1 

#include "Cu29_Library.h"

void ADC_to_key (short ADC_CV)
{    
   
    // 1. If the ADC value is below 39, return without doing anything.
    if (ADC_CV < 39) return;
        
    // 2. Convert the ADC reading into an index. Index = (ADC-203)/17
    //    We use a while loop instead of dividing, because division is SLOW.
    char index = 0;
    ADC_CV = ADC_CV - 39;
    
    while(ADC_CV > 3)
    {
        ADC_CV = ADC_CV - 3;
        index++;
    }
    
    // 3. Check how many samples to skip.
    if (index > 34) samples = 4;
    else if(index > 23) samples = 2;
    else samples = 1;
        
    // 4. Calculate the appropriate timer scale value.
    char timerScale = 0xB0;
    if (index > 34) timerScale = 0xA0;
    
    // 5. Look up the appropriate period using an array.
    const char periodArray[] = {
        239, 225, 213, 201, 190, 179, 169, 159, 
        150, 142, 134, 127, 119, 113, 106, 100, 
         95,  89,  84,  80,  75,  71,  67,  63, 
        119, 113, 106, 100,  95,  89,  84,  80, 
         75,  71,  67, 253, 239, 225, 213, 201, 
        190, 179, 169, 159, 150, 142, 134, 127, 
        119
    };
    
    char timerPeriod = periodArray[index];
    
    // 6. Apply the selected values to the timer.
    T2PR = timerPeriod;
    T2CON = timerScale;
    PIR1bits.TMR2IF = 0;
    
    
}

#else 

#include "Cu29_Library.h"

// Requires: Short type input representing a key, ranging from 16 to 64
// Promises: Uses "Configure_Timer" to output a frequency corresponding
//           to the given note, returns a sample rate scaler (1, 2, 4) for
//           use with oscillator functions.
void key_49 (short n)
{
  switch (n)
  {
      case 16: //C2, 65.41 Hz
          ConfigureTimer2(239, 0xb0); //TimerPeriod_us, T2CLKCON
          samples = 1; //Samples
          break;

      case 17: //C#2, 69.3 Hz
          ConfigureTimer2(225, 0xb0); //TimerPeriod_us, T2CLKCON
          samples = 1; //Samples
          break;

      case 18: //D2, 73.42 Hz
          ConfigureTimer2(213, 0xb0); //TimerPeriod_us, T2CLKCON
          samples = 1; //Samples
          break;

      case 19: //D#2, 77.78 Hz
          ConfigureTimer2(201, 0xb0); //TimerPeriod_us, T2CLKCON
          samples = 1; //Samples
          break;

      case 20: //E2, 82.41 Hz
          ConfigureTimer2(190, 0xb0); //TimerPeriod_us, T2CLKCON
          samples = 1; //Samples
          break;

      case 21: //F2, 87.31 Hz
          ConfigureTimer2(179,0xb0);//TimerPeriod_us, T2CLKCON
          samples = 1; //Samples
          break;

      case 22 : //F#2, 92.50 Hz
          ConfigureTimer2(169,0xb0);//TimerPeriod_us, T2CLKCON
          samples = 1; //Samples
          break;

      case 23: //G2, 98.00 Hz
          ConfigureTimer2(159,0xb0);//TimerPeriod_us, T2CLKCON
          samples = 1; //Samples
          break;

      case 24: //G#2, 103.83 Hz
          ConfigureTimer2(150,0xb0);//TimerPeriod_us, T2CLKCON
          samples = 1; //Samples
          break;

      case 25: //A2, 110.00 Hz
          ConfigureTimer2(142,0xb0);//TimerPeriod_us, T2CLKCON
          samples = 1; //Samples
          break;

      case 26: //A#2, 116.54 Hz
          ConfigureTimer2(134,0xb0);//TimerPeriod_us, T2CLKCON
          samples = 1; //Samples
          break;

      case 27: //B2, 123.47 Hz
          ConfigureTimer2(127,0xb0);//TimerPeriod_us, T2CLKCON
          samples = 1; //Samples
          break;

      case 28: //C3, 130.81 Hz
          ConfigureTimer2(119,0xb0);//TimerPeriod_us, T2CLKCON
          samples = 1; //Samples
          break;

      case 29: //C#3, 138.59 Hz
          ConfigureTimer2(113,0xb0);//TimerPeriod_us, T2CLKCON
          samples = 1; //Samples
          break;

      case 30: //D3, 146.83 Hz
          ConfigureTimer2(106,0xb0);//TimerPeriod_us, T2CLKCON
          samples = 1; //Samples
          break;

      case 31: //D#3, 155.56 Hz
          ConfigureTimer2(100,0xb0);//TimerPeriod_us, T2CLKCON
          samples = 1; //Samples
          break;

      case 32: //E3, 164.81 Hz
          ConfigureTimer2(95,0xb0);//TimerPeriod_us, T2CLKCON
          samples = 1; //Samples
          break;

      case 33: //F3, 174.61 Hz
          ConfigureTimer2(89,0xb0);//TimerPeriod_us, T2CLKCON
          samples = 1; //Samples
          break;

      case 34: //F#3, 185.00 Hz
          ConfigureTimer2(84,0xb0);//TimerPeriod_us, T2CLKCON
          samples = 1; //Samples
          break;

      case 35: //G3, 196.00 Hz
          ConfigureTimer2(80,0xb0);//TimerPeriod_us, T2CLKCON
          samples = 1; //Samples
          break;

      case 36: //G#3, 207.65 Hz
          ConfigureTimer2(75,0xb0);//TimerPeriod_us, T2CLKCON
          samples = 1; //Samples
          break;

      case 37: //A3, 220.00 Hz
          ConfigureTimer2(71,0xb0);//TimerPeriod_us, T2CLKCON
          samples = 1; //Samples
          break;

      case 38: //A#3, 233.08 Hz
          ConfigureTimer2(67,0xb0);//TimerPeriod_us, T2CLKCON
          samples = 1; //Samples
          break;

      case 39: //B3, 246.94 Hz
          ConfigureTimer2(63,0xb0);//TimerPeriod_us, T2CLKCON
          samples = 1; //Samples
          break;

      case 40: //C4, 261.63 Hz
          ConfigureTimer2(119,0xb0);//TimerPeriod_us, T2CLKCON
          samples = 2; //Samples
          break;

      case 41: //C#4, 277.18 Hz
          ConfigureTimer2(113,0xb0);//TimerPeriod_us, T2CLKCON
          samples = 2; //Samples
          break;

      case 42: //D4, 293.66 Hz
          ConfigureTimer2(106,0xb0);//TimerPeriod_us, T2CLKCON
          samples = 2; //Samples
          break;

      case 43: //D#4, 311.13 Hz
          ConfigureTimer2(100,0xb0);//TimerPeriod_us, T2CLKCON
          samples = 2; //Samples
          break;

      case 44: //E4, 329.63 Hz
          ConfigureTimer2(95,0xb0);//TimerPeriod_us, T2CLKCON
          samples = 2; //Samples
          break;

      case 45: //F4, 349.23 Hz
          ConfigureTimer2(89,0xb0);//TimerPeriod_us, T2CLKCON
          samples = 2; //Samples
          break;

      case 46: //F#4, 369.99 Hz
          ConfigureTimer2(84,0xb0);//TimerPeriod_us, T2CLKCON
          samples = 2; //Samples
          break;

      case 47: //G4, 392.00 Hz
          ConfigureTimer2(80,0xb0);//TimerPeriod_us, T2CLKCON
          samples = 2; //Samples
          break;

      case 48: //G#4, 415.30 Hz
          ConfigureTimer2(75,0xb0);//TimerPeriod_us, T2CLKCON
          samples = 2; //Samples
          break;

      case 49: //A4, 440.00 Hz
          ConfigureTimer2(71,0xb0);//TimerPeriod_us, T2CLKCON
          samples = 2; //Samples
          break;

      case 50: //A#4, 466.16 Hz
          ConfigureTimer2(67,0xb0);//TimerPeriod_us, T2CLKCON
          samples = 2; //Samples
          break;

      case 51: //B4, 493.88 Hz
          ConfigureTimer2(253,0xa0);//TimerPeriod_us, T2CLKCON
          samples = 4; //Samples
          break;

      case 52: //C5, 523.25 Hz
          ConfigureTimer2(239,0xa0);//TimerPeriod_us, T2CLKCON
          samples = 4; //Samples
          break;

      case 53: //C#5, 554,37 Hz
          ConfigureTimer2(225,0xa0);//TimerPeriod_us, T2CLKCON
          samples = 4; //Samples
          break;

      case 54: //D5, 587.33 Hz
          ConfigureTimer2(213,0xa0);//TimerPeriod_us, T2CLKCON
          samples = 4; //Samples
          break;

      case 55: //D#5, 622.25 Hz
          ConfigureTimer2(201,0xa0);//TimerPeriod_us, T2CLKCON
          samples = 4; //Samples
          break;

      case 56: //E5, 659.25 Hz
          ConfigureTimer2(190,0xa0);//TimerPeriod_us, T2CLKCON
          samples = 4; //Samples
          break;

      case 57: //F5, 698.46 Hz
          ConfigureTimer2(179,0xa0);//TimerPeriod_us, T2CLKCON
          samples = 4; //Samples
          break;

      case 58: //F#5, 739.99 Hz
          ConfigureTimer2(169,0xa0);//TimerPeriod_us, T2CLKCON
          samples = 4; //Samples
          break;

      case 59: //G5, 783.99 Hz
          ConfigureTimer2(159,0xa0);//TimerPeriod_us, T2CLKCON
          samples = 4; //Samples
          break;

      case 60: //G#5, 830.61 Hz
          ConfigureTimer2(150,0xa0);//TimerPeriod_us, T2CLKCON
          samples = 4; //Samples
          break;

      case 61: //A5, 880.00 Hz
          ConfigureTimer2(142,0xa0);//TimerPeriod_us, T2CLKCON
          samples = 4; //Samples
          break;

      case 62: //A#5, 932.33 Hz
          ConfigureTimer2(134,0xa0);//TimerPeriod_us, T2CLKCON
          samples = 4; //Samples
          break;

      case 63: //B5, 987.77 Hz
          ConfigureTimer2(127,0xa0);//TimerPeriod_us, T2CLKCON
          samples = 4; //Samples
          break;

      case 64: //C6, 1046.50 Hz
          ConfigureTimer2(119,0xa0);//TimerPeriod_us, T2CLKCON
          samples = 4; //Samples
          break;
      }
}

// Requires: Input voltage (1-5V) from ADC, 8-bit char.
// Promises: Integer n, with 16 <=n <= 64.
void ADC_to_key (short ADC_CV)
{
  int n;

  if(ADC_CV < 39) return;

  if (ADC_CV >= 39 && ADC_CV < 75) //C2 to B2
  {
    if(ADC_CV >= 39 && ADC_CV < 42) //C2
    {
      n = 16;
      key_49(n);
    }
    else if(ADC_CV >= 42 && ADC_CV < 45) //C#2
    {
      n = 17;
      key_49(n);
    }
    else if(ADC_CV >= 45 && ADC_CV < 48) //D2
    {
      n = 18;
      key_49(n);
    }
    if(ADC_CV >= 48 && ADC_CV < 51) //D#2
    {
      n = 19;
      key_49(n);
    }
    else if(ADC_CV >= 51 && ADC_CV < 554) //E2
    {
      n = 20;
      key_49(n);
    }
    else if(ADC_CV >= 54 && ADC_CV < 57) //F2
    {
      n = 21;
      key_49(n);
    }
    else if(ADC_CV >= 57 && ADC_CV < 60) //F#2
    {
      n = 22;
      key_49(n);
    }
    else if(ADC_CV >= 60 && ADC_CV < 63) //G2
    {
      n = 23;
      key_49(n);
    }
    else if(ADC_CV >= 63 && ADC_CV < 66) //G#2
    {
      n = 24;
      key_49(n);
    }
    else if(ADC_CV >= 66 && ADC_CV < 69) //A2
    {
      n = 25;
      key_49(n);
    }
    else if(ADC_CV >= 69 && ADC_CV < 72) //A#2
    {
      n = 26;
      key_49(n);
    }
    else if(ADC_CV >= 72 && ADC_CV < 75) //B2
    {
      n = 27;
      key_49(n);
    }
  }


  else if (ADC_CV >= 75 && ADC_CV < 111) //C3 to B3
  {
    if(ADC_CV >= 75 && ADC_CV < 78) //C3
    {
      n = 28;
      key_49(n);
    }
    else if(ADC_CV >= 78 && ADC_CV < 81) //C#3
    {
      n = 29;
      key_49(n);
    }
    else if(ADC_CV >= 81 && ADC_CV < 84) //D3
    {
      n = 30;
      key_49(n);
    }
    else if(ADC_CV >= 84 && ADC_CV < 87) //D#3
    {
      n = 31;
      key_49(n);
    }
    else if(ADC_CV >= 87 && ADC_CV < 90) //E3
    {
      n = 32;
      key_49(n);
    }
    else if(ADC_CV >= 90 && ADC_CV < 93) //F3
    {
      n = 33;
      key_49(n);
    }
    else if(ADC_CV >= 93 && ADC_CV < 96) //F#3
    {
      n = 34;
      key_49(n);
    }
    else if(ADC_CV >= 96 && ADC_CV < 99) //G3
    {
      n = 35;
      key_49(n);
    }
    else if(ADC_CV >= 99 && ADC_CV < 102) //G#3
    {
      n = 36;
      key_49(n);
    }
    else if(ADC_CV >= 102 && ADC_CV < 105) //A3
    {
      n = 37;
      key_49(n);
    }
    else if(ADC_CV >= 105 && ADC_CV < 108) //A#3
    {
      n = 38;
      key_49(n);
    }
    else if(ADC_CV >= 108 && ADC_CV < 111) //B3
    {
      n = 39;
      key_49(n);
    }
  }

  else if (ADC_CV >= 111 && ADC_CV < 147) //C4 to B4
  {
    if(ADC_CV >= 111 && ADC_CV < 114) //C4
    {
      n = 40;
      key_49(n);
    }
    else if(ADC_CV >= 114 && ADC_CV < 117) //C#4
    {
      n = 41;
      key_49(n);
    }
    else if(ADC_CV >= 117 && ADC_CV < 120) //D4
    {
      n = 42;
      key_49(n);
    }
    else if(ADC_CV >= 120 && ADC_CV < 123) //D#4
    {
      n = 43;
      key_49(n);
    }
    else if(ADC_CV >= 123 && ADC_CV < 126) //E4
    {
      n = 44;
      key_49(n);
    }
    else if(ADC_CV >= 126 && ADC_CV < 129) //F4
    {
      n = 45;
      key_49(n);
    }
    else if(ADC_CV >= 129 && ADC_CV < 132) //F#4
    {
      n = 46;
      key_49(n);
    }
    else if(ADC_CV >= 132 && ADC_CV < 135) //G4
    {
      n = 47;
      key_49(n);
    }
    else if(ADC_CV >= 135 && ADC_CV < 138) //G#4
    {
      n = 48;
      key_49(n);
    }
    else if(ADC_CV >= 138 && ADC_CV < 141) //A4
    {
      n = 49;
      key_49(n);
    }
    else if(ADC_CV >= 141 && ADC_CV < 144) //A#4
    {
      n = 50;
      key_49(n);
    }
    else if(ADC_CV >= 144 && ADC_CV < 147) //B4
    {
      n = 51;
      key_49(n);
    }
  }

  else if (ADC_CV >= 147 && ADC_CV < 183) //C5 to B5
  {
    if(ADC_CV >= 147 && ADC_CV < 150) //C5
    {
      n = 52;
      key_49(n);
    }
    else if(ADC_CV >= 150 && ADC_CV < 153) //C#5
    {
      n = 53;
      key_49(n);
    }
    else if(ADC_CV >= 153 && ADC_CV < 156) //D5
    {
      n = 54;
      key_49(n);
    }
    else if(ADC_CV >= 156 && ADC_CV < 159) //D#5
    {
      n = 55;
      key_49(n);
    }
    else if(ADC_CV >= 159 && ADC_CV < 162) //E5
    {
      n = 56;
      key_49(n);
    }
    else if(ADC_CV >= 162 && ADC_CV < 165) //F5
    {
      n = 57;
      key_49(n);
    }
    else if(ADC_CV >= 165 && ADC_CV < 168) //F#5
    {
      n = 58;
      key_49(n);
    }
    else if(ADC_CV >= 168 && ADC_CV < 171) //G5
    {
      n = 59;
      key_49(n);
    }
    else if(ADC_CV >= 171 && ADC_CV < 174) //G#5
    {
      n = 60;
      key_49(n);
    }
    else if(ADC_CV >= 174 && ADC_CV < 177) //A5
    {
      n = 61;
      key_49(n);
    }
    else if(ADC_CV >= 177 && ADC_CV < 180) //A#5
    {
      n = 62;
      key_49(n);
    }
    else if(ADC_CV >= 180 && ADC_CV < 183) //B5
    {
      n = 63;
      key_49(n);
    }
  }

  else if(ADC_CV >= 183) //C6
  {
    n = 64;
    key_49(n);
    return;
  }
}
#endif