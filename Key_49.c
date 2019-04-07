#include "Cu29_Library.h"

// Requires: Short type input representing a key, ranging from 16 to 64
// Promises: Uses "Configure_Timer" to output a frequency corresponding
//           to the given note, returns a sample rate scaler (1, 2, 4) for
//           use with oscillator functions.
int key_49 (short n)
{
  switch (n)
  {
      case 16: //C2, 65.41 Hz
          ConfigureTimer2(239, 0xb0); //TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 17: //C#2, 69.3 Hz
          ConfigureTimer2(225, 0xb0); //TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 18: //D2, 73.42 Hz
          ConfigureTimer2(213, 0xb0); //TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 19: //D#2, 77.78 Hz
          ConfigureTimer2(201, 0xb0); //TimerPeriod_us, T2CLKCON
            return 1; //Samples
          break;

      case 20: //E2, 82.41 Hz
          ConfigureTimer2(190, 0xb0); //TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 21: //F2, 87.31 Hz
          ConfigureTimer2(179,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 22 : //F#2, 92.50 Hz
          ConfigureTimer2(169,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 23: //G2, 98.00 Hz
          ConfigureTimer2(159,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 24: //G#2, 103.83 Hz
          ConfigureTimer2(150,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 25: //A2, 110.00 Hz
          ConfigureTimer2(142,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 26: //A#2, 116.54 Hz
          ConfigureTimer2(134,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 27: //B2, 123.47 Hz
          ConfigureTimer2(127,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 28: //C3, 130.81 Hz
          ConfigureTimer2(119,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 29: //C#3, 138.59 Hz
          ConfigureTimer2(113,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 30: //D3, 146.83 Hz
          ConfigureTimer2(106,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 31: //D#3, 155.56 Hz
          ConfigureTimer2(100,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 32: //E3, 164.81 Hz
          ConfigureTimer2(95,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 33: //F3, 174.61 Hz
          ConfigureTimer2(89,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 34: //F#3, 185.00 Hz
          ConfigureTimer2(84,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 35: //G3, 196.00 Hz
          ConfigureTimer2(80,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 36: //G#3, 207.65 Hz
          ConfigureTimer2(75,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 37: //A3, 220.00 Hz
          ConfigureTimer2(71,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 38: //A#3, 233.08 Hz
          ConfigureTimer2(67,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 39: //B3, 246.94 Hz
          ConfigureTimer2(63,0xb0);//TimerPeriod_us, T2CLKCON
          return 1; //Samples
          break;

      case 40: //C4, 261.63 Hz
          ConfigureTimer2(119,0xb0);//TimerPeriod_us, T2CLKCON
          return 2; //Samples
          break;

      case 41: //C#4, 277.18 Hz
          ConfigureTimer2(113,0xb0);//TimerPeriod_us, T2CLKCON
          return 2; //Samples
          break;

      case 42: //D4, 293.66 Hz
          ConfigureTimer2(106,0xb0);//TimerPeriod_us, T2CLKCON
          return 2; //Samples
          break;

      case 43: //D#4, 311.13 Hz
          ConfigureTimer2(100,0xb0);//TimerPeriod_us, T2CLKCON
          return 2; //Samples
          break;

      case 44: //E4, 329.63 Hz
          ConfigureTimer2(95,0xb0);//TimerPeriod_us, T2CLKCON
          return 2; //Samples
          break;

      case 45: //F4, 349.23 Hz
          ConfigureTimer2(89,0xb0);//TimerPeriod_us, T2CLKCON
          return 2; //Samples
          break;

      case 46: //F#4, 369.99 Hz
          ConfigureTimer2(84,0xb0);//TimerPeriod_us, T2CLKCON
          return 2; //Samples
          break;

      case 47: //G4, 392.00 Hz
          ConfigureTimer2(80,0xb0);//TimerPeriod_us, T2CLKCON
          return 2; //Samples
          break;

      case 48: //G#4, 415.30 Hz
          ConfigureTimer2(75,0xb0);//TimerPeriod_us, T2CLKCON
          return 2; //Samples
          break;

      case 49: //A4, 440.00 Hz
          ConfigureTimer2(71,0xb0);//TimerPeriod_us, T2CLKCON
          return 2; //Samples
          break;

      case 50: //A#4, 466.16 Hz
          ConfigureTimer2(67,0xb0);//TimerPeriod_us, T2CLKCON
          return 2; //Samples
          break;

      case 51: //B4, 493.88 Hz
          ConfigureTimer2(253,0xa0);//TimerPeriod_us, T2CLKCON
          return 4; //Samples
          break;

      case 52: //C5, 523.25 Hz
          ConfigureTimer2(239,0xa0);//TimerPeriod_us, T2CLKCON
          return 4; //Samples
          break;

      case 53: //C#5, 554,37 Hz
          ConfigureTimer2(225,0xa0);//TimerPeriod_us, T2CLKCON
          return 4; //Samples
          break;

      case 54: //D5, 587.33 Hz
          ConfigureTimer2(213,0xa0);//TimerPeriod_us, T2CLKCON
          return 4; //Samples
          break;

      case 55: //D#5, 622.25 Hz
          ConfigureTimer2(201,0xa0);//TimerPeriod_us, T2CLKCON
          return 4; //Samples
          break;

      case 56: //E5, 659.25 Hz
          ConfigureTimer2(190,0xa0);//TimerPeriod_us, T2CLKCON
          return 4; //Samples
          break;

      case 57: //F5, 698.46 Hz
          ConfigureTimer2(179,0xa0);//TimerPeriod_us, T2CLKCON
          return 4; //Samples
          break;

      case 58: //F#5, 739.99 Hz
          ConfigureTimer2(169,0xa0);//TimerPeriod_us, T2CLKCON
          return 4; //Samples
          break;

      case 59: //G5, 783.99 Hz
          ConfigureTimer2(159,0xa0);//TimerPeriod_us, T2CLKCON
          return 4; //Samples
          break;

      case 60: //G#5, 830.61 Hz
          ConfigureTimer2(150,0xa0);//TimerPeriod_us, T2CLKCON
          return 4; //Samples
          break;

      case 61: //A5, 880.00 Hz
          ConfigureTimer2(142,0xa0);//TimerPeriod_us, T2CLKCON
          return 4; //Samples
          break;

      case 62: //A#5, 932.33 Hz
          ConfigureTimer2(134,0xa0);//TimerPeriod_us, T2CLKCON
          return 4; //Samples
          break;

      case 63: //B5, 987.77 Hz
          ConfigureTimer2(127,0xa0);//TimerPeriod_us, T2CLKCON
          return 4; //Samples
          break;

      case 64: //C6, 1046.50 Hz
          ConfigureTimer2(119,0xa0);//TimerPeriod_us, T2CLKCON
          return 4; //Samples
          break;

      default:
          return 1;
          break;
      }
}

// Requires: Input voltage (1-5V) from ADC, 8-bit char.
// Promises: Integer n, with 16 <=n <= 64.
int ADC_to_key (short ADC_CV)
{
  int n;

  if (ADC_CV >= 204 && ADC_CV < 409) //C2 to B2
  {
    if(ADC_CV >= 204 && ADC_CV < 221) //C2
    {
      n = 16;
      return key_49(n);
    }
    if(ADC_CV >= 221 && ADC_CV < 238) //C#2
    {
      n = 17;
      return key_49(n);
    }
    if(ADC_CV >= 238 && ADC_CV < 255) //D2
    {
      n = 18;
      return key_49(n);
    }
    if(ADC_CV >= 255 && ADC_CV < 272) //D#2
    {
      n = 19;
      return key_49(n);
    }
    if(ADC_CV >= 272 && ADC_CV < 289) //E2
    {
      n = 20;
      return key_49(n);
    }
    if(ADC_CV >= 289 && ADC_CV < 306) //F2
    {
      n = 21;
      return key_49(n);
    }
    if(ADC_CV >= 306 && ADC_CV < 323) //F#2
    {
      n = 22;
      return key_49(n);
    }
    if(ADC_CV >= 323 && ADC_CV < 340) //G2
    {
      n = 23;
      return key_49(n);
    }
    if(ADC_CV >= 340 && ADC_CV < 357) //G#2
    {
      n = 24;
      return key_49(n);
    }
    if(ADC_CV >= 357 && ADC_CV < 374) //A2
    {
      n = 25;
      return key_49(n);
    }
    if(ADC_CV >= 374 && ADC_CV < 391) //A#2
    {
      n = 26;
      return key_49(n);
    }
    if(ADC_CV >= 391 && ADC_CV < 409) //B2
    {
      n = 27;
      return key_49(n);
    }
  }


  else if (ADC_CV >= 409 && ADC_CV < 595) //C3 to B3
  {
    if(ADC_CV >= 409 && ADC_CV < 425) //C3
    {
      n = 28;
      return key_49(n);
    }
    if(ADC_CV >= 425 && ADC_CV < 442) //C#3
    {
      n = 29;
      return key_49(n);
    }
    if(ADC_CV >= 442 && ADC_CV < 459) //D3
    {
      n = 30;
      return key_49(n);
    }
    if(ADC_CV >= 459 && ADC_CV < 477) //D#3
    {
      n = 31;
      return key_49(n);
    }
    if(ADC_CV >= 477 && ADC_CV < 494) //E3
    {
      n = 32;
      return key_49(n);
    }
    if(ADC_CV >= 494 && ADC_CV < 510) //F3
    {
      n = 33;
      return key_49(n);
    }
    if(ADC_CV >= 510 && ADC_CV < 527) //F#3
    {
      n = 34;
      return key_49(n);
    }
    if(ADC_CV >= 527 && ADC_CV < 545) //G3
    {
      n = 35;
      return key_49(n);
    }
    if(ADC_CV >= 545 && ADC_CV < 562) //G#3
    {
      n = 36;
      return key_49(n);
    }
    if(ADC_CV >= 562 && ADC_CV < 579) //A3
    {
      n = 37;
      return key_49(n);
    }
    if(ADC_CV >= 579 && ADC_CV < 595) //A#3
    {
      n = 38;
      return key_49(n);
    }
    if(ADC_CV >= 595 && ADC_CV < 613) //B3
    {
      n = 39;
      return key_49(n);
    }
  }

  else if (ADC_CV >= 613 && ADC_CV < 800) //C4 to B4
  {
    if(ADC_CV >= 613 && ADC_CV < 630) //C4
    {
      n = 40;
      return key_49(n);
    }
    if(ADC_CV >= 630 && ADC_CV < 647) //C#4
    {
      n = 41;
      return key_49(n);
    }
    if(ADC_CV >= 647 && ADC_CV < 664) //D4
    {
      n = 42;
      return key_49(n);
    }
    if(ADC_CV >= 664 && ADC_CV < 681) //D#4
    {
      n = 43;
      return key_49(n);
    }
    if(ADC_CV >= 681 && ADC_CV < 698) //E4
    {
      n = 44;
      return key_49(n);
    }
    if(ADC_CV >= 698 && ADC_CV < 715) //F4
    {
      n = 45;
      return key_49(n);
    }
    if(ADC_CV >= 715 && ADC_CV < 732) //F#4
    {
      n = 46;
      return key_49(n);
    }
    if(ADC_CV >= 732 && ADC_CV < 749) //G4
    {
      n = 47;
      return key_49(n);
    }
    if(ADC_CV >= 749 && ADC_CV < 766) //G#4
    {
      n = 48;
      return key_49(n);
    }
    if(ADC_CV >= 766 && ADC_CV < 783) //A4
    {
      n = 49;
      return key_49(n);
    }
    if(ADC_CV >= 783 && ADC_CV < 800) //A#4
    {
      n = 50;
      return key_49(n);
    }
    if(ADC_CV >= 800 && ADC_CV < 817) //B4
    {
      n = 51;
      return key_49(n);
    }
  }

  else if (ADC_CV >= 817 && ADC_CV < 1004) //C5 to B5
  {
    if(ADC_CV >= 817 && ADC_CV < 834) //C5
    {
      n = 52;
      return key_49(n);
    }
    if(ADC_CV >= 834 && ADC_CV < 851) //C#5
    {
      n = 53;
      return key_49(n);
    }
    if(ADC_CV >= 851 && ADC_CV < 868) //D5
    {
      n = 54;
      return key_49(n);
    }
    if(ADC_CV >= 868 && ADC_CV < 885) //D#5
    {
      n = 55;
      return key_49(n);
    }
    if(ADC_CV >= 885 && ADC_CV < 902) //E5
    {
      n = 56;
      return key_49(n);
    }
    if(ADC_CV >= 902 && ADC_CV < 919) //F5
    {
      n = 57;
      return key_49(n);
    }
    if(ADC_CV >= 919 && ADC_CV < 936) //F#5
    {
      n = 58;
      return key_49(n);
    }
    if(ADC_CV >= 936 && ADC_CV < 953) //G5
    {
      n = 59;
      return key_49(n);
    }
    if(ADC_CV >= 953 && ADC_CV < 970) //G#5
    {
      n = 60;
      return key_49(n);
    }
    if(ADC_CV >= 970 && ADC_CV < 987) //A5
    {
      n = 61;
      return key_49(n);
    }
    if(ADC_CV >= 987 && ADC_CV < 1004) //A#5
    {
      n = 62;
      return key_49(n);
    }
    if(ADC_CV >= 1004 && ADC_CV < 1020) //B5
    {
      n = 63;
      return key_49(n);
    }
  }

  else if(ADC_CV >= 1020) //C6
  {
    n = 64;
    return key_49(n);
  }
}
