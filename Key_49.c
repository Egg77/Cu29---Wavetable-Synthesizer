#include "Cu29_Library.h"

// Requires: Short type input representing a key, ranging from 16 to 64
// Promises: Uses "Configure_Timer" to output a frequency corresponding
//           to the given note, returns a sample rate scaler (1, 2, 4) for
//           use with oscillator functions.
int 49_key (short n)
{
  switch (n)
  ​{
      case 16: //C2, 65.41 Hz
          Configure_Timer(239, 0xb0); //TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 17: //C#2, 69.3 Hz
          Configure_Timer(225, 0xb0); //TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 18: //D2, 73.42 Hz
          Configure_Timer(213, 0xb0); //TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 19: //D#2, 77.78 Hz
          Configure_Timer(201, 0xb0); //TimerPeriod_us, T2CLKCON
            return 1; //Samples
          break;

      case 20: //E2, 82.41 Hz
          Configure_Timer(190, 0xb0); //TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 21: //F2, 87.31 Hz
          Configure_Timer(179,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 22 : //F#2, 92.50 Hz
          Configure_Timer(169,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 23: //G2, 98.00 Hz
          Configure_Timer(159,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 24: //G#2, 103.83 Hz
          Configure_Timer(150,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 25: //A2, 110.00 Hz
          Configure_Timer(142,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 26: //A#2, 116.54 Hz
          Configure_Timer(134,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 27: //B2, 123.47 Hz
          Configure_Timer(127,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 28: //C3, 130.81 Hz
          Configure_Timer(119,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 29: //C#3, 138.59 Hz
          Configure_Timer(113,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 30: //D3, 146.83 Hz
          Configure_Timer(106,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 31: //D#3, 155.56 Hz
          Configure_Timer(100,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 32: //E3, 164.81 Hz
          Configure_Timer(95,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 33: //F3, 174.61 Hz
          Configure_Timer(89,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 34: //F#3, 185.00 Hz
          Configure_Timer(84,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 35: //G3, 196.00 Hz
          Configure_Timer(80,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 36: //G#3, 207.65 Hz
          Configure_Timer(75,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 37: //A3, 220.00 Hz
          Configure_Timer(71,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 38: //A#3, 233.08 Hz
          Configure_Timer(67,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 39: //B3, 246.94 Hz
          Configure_Timer(63,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 40: //C4, 261.63 Hz
          Configure_Timer(119,0xb0);//TimerPeriod_us, T2CLKCON
          return 2; //Samples
          break;

      case 41: //C#4, 277.18 Hz
          Configure_Timer(113,0xb0);//TimerPeriod_us, T2CLKCON
          return 2; //Samples
          break;

      case 42: //D4, 293.66 Hz
          Configure_Timer(106,0xb0);//TimerPeriod_us, T2CLKCON
          return 2; //Samples
          break;

      case 43: //D#4, 311.13 Hz
          Configure_Timer(100,0xb0);//TimerPeriod_us, T2CLKCON
          return 2; //Samples
          break;

      case 44: //E4, 329.63 Hz
          Configure_Timer(95,0xb0);//TimerPeriod_us, T2CLKCON
          return 2; //Samples
          break;

      case 45: //F4, 349.23 Hz
          Configure_Timer(89,0xb0);//TimerPeriod_us, T2CLKCON
          return 2; //Samples
          break;

      case 46: //F#4, 369.99 Hz
          Configure_Timer(84,0xb0);//TimerPeriod_us, T2CLKCON
          return 2; //Samples
          break;

      case 47: //G4, 392.00 Hz
          Configure_Timer(80,0xb0);//TimerPeriod_us, T2CLKCON
          return 2; //Samples
          break;

      case 48: //G#4, 415.30 Hz
          Configure_Timer(75,0xb0);//TimerPeriod_us, T2CLKCON
          return 2; //Samples
          break;

      case 49: //A4, 440.00 Hz
          Configure_Timer(71,0xb0);//TimerPeriod_us, T2CLKCON
          return 2; //Samples
          break;

      case 50: //A#4, 466.16 Hz
          Configure_Timer(67,0xb0);//TimerPeriod_us, T2CLKCON
          return 2; //Samples
          break;

      case 51: //B4, 493.88 Hz
          Configure_Timer(253,0xa0);//TimerPeriod_us, T2CLKCON
          return 4; //Samples
          break;

      case 52: //C5, 523.25 Hz
          Configure_Timer(239,0xa0);//TimerPeriod_us, T2CLKCON
          return 4; //Samples
          break;

      case 53: //C#5, 554,37 Hz
          Configure_Timer(225,0xa0);//TimerPeriod_us, T2CLKCON
          return 4; //Samples
          break;

      case 54: //D5, 587.33 Hz
          Configure_Timer(213,0xa0);//TimerPeriod_us, T2CLKCON
          return 4; //Samples
          break;

      case 55: //D#5, 622.25 Hz
          Configure_Timer(201,0xa0);//TimerPeriod_us, T2CLKCON
          return 4; //Samples
          break;

      case 56: //E5, 659.25 Hz
          Configure_Timer(190,0xa0);//TimerPeriod_us, T2CLKCON
          return 4; //Samples
          break;

      case 57: //F5, 698.46 Hz
          Configure_Timer(179,0xa0);//TimerPeriod_us, T2CLKCON
          return 4; //Samples
          break;

      case 58: //F#5, 739.99 Hz
          Configure_Timer(169,0xa0);//TimerPeriod_us, T2CLKCON
          return 4; //Samples
          break;

      case 59: //G5, 783.99 Hz
          Configure_Timer(159,0xa0);//TimerPeriod_us, T2CLKCON
          return 4; //Samples
          break;

      case 60: //G#5, 830.61 Hz
          Configure_Timer(150,0xa0);//TimerPeriod_us, T2CLKCON
          return 4; //Samples
          break;

      case 61: //A5, 880.00 Hz
          Configure_Timer(142,0xa0);//TimerPeriod_us, T2CLKCON
          return 4; //Samples
          break;

      case 62: //A#5, 932.33 Hz
          Configure_Timer(134,0xa0);//TimerPeriod_us, T2CLKCON
          return 4; //Samples
          break;

      case 63: //B5, 987.77 Hz
          Configure_Timer(127,0xa0);//TimerPeriod_us, T2CLKCON
          return 4; //Samples
          break;

      case 64: //C6, 1046.50 Hz
          Configure_Timer(119,0xa0);//TimerPeriod_us, T2CLKCON
          return 4; //Samples
          break;

      default:
          break;
      }
}

// Requires: Input voltage (1-5V) from ADC, 8-bit char.
// Promises: Integer n, with 16 <=n <= 64.
int ADC_to_key (char v_in)
{
  v_in =

  int n;

  if (v_in < 2 && v_in > 1) //C2 to B2
  {


  }

  if (v_in < 3 && v_in > 2) //C3 to B3
  {


  }

  if (v_in < 4 && v_in > 3) //C4 to B4
  {


  }

  if (v_in < 5 && v_in > 4) //C5 to B5
  {


  }

  if (v_in == 5) //C6
  {


  }

  return n;
}
