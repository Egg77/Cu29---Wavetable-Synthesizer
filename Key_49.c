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
          ConfigureTimer2(169,0xb0);//TimerPeriod_us, T2CLKCON
          samples = 2; //Samples
          break;

      case 35: //G3, 196.00 Hz
          ConfigureTimer2(159,0xb0);//TimerPeriod_us, T2CLKCON
          samples = 2; //Samples
          break;

      case 36: //G#3, 207.65 Hz
          ConfigureTimer2(150,0xb0);//TimerPeriod_us, T2CLKCON
          samples = 2; //Samples
          break;

      case 37: //A3, 220.00 Hz
          ConfigureTimer2(142,0xb0);//TimerPeriod_us, T2CLKCON
          samples = 2; //Samples
          break;

      case 38: //A#3, 233.08 Hz
          ConfigureTimer2(134,0xb0);//TimerPeriod_us, T2CLKCON
          samples = 2; //Samples
          break;

      case 39: //B3, 246.94 Hz
          ConfigureTimer2(127,0xb0);//TimerPeriod_us, T2CLKCON
          samples = 2; //Samples
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
          ConfigureTimer2(159,0xa1);//TimerPeriod_us, T2CLKCON
          samples = 8; //Samples
          break;

      case 60: //G#5, 830.61 Hz
          ConfigureTimer2(150,0xa1);//TimerPeriod_us, T2CLKCON
          samples = 8; //Samples
          break;

      case 61: //A5, 880.00 Hz
          ConfigureTimer2(142,0xa1);//TimerPeriod_us, T2CLKCON
          samples = 8; //Samples
          break;

      case 62: //A#5, 932.33 Hz
          ConfigureTimer2(134,0xa1);//TimerPeriod_us, T2CLKCON
          samples = 8; //Samples
          break;

      case 63: //B5, 987.77 Hz
          ConfigureTimer2(127,0xa1);//TimerPeriod_us, T2CLKCON
          samples = 8; //Samples
          break;

      case 64: //C6, 1046.50 Hz
          ConfigureTimer2(119,0xa1);//TimerPeriod_us, T2CLKCON
          samples = 8; //Samples
          break;
      }
}

// Requires: Input voltage (0.5-2.5V) from ADC, 8-bit char.
// Promises: Integer n, with 16 <=n <= 64.
void ADC_to_key (short ADC_CV)
{
  int n;

  //if(ADC_CV < 108) return;

  if (ADC_CV >= 108 && ADC_CV < 216) //C2 to B2
  {
    if(ADC_CV >= 108 && ADC_CV < 115) //C2
    {
      n = 16;
      key_49(n);
    }
    else if(ADC_CV >= 117 && ADC_CV < 125) //C#2
    {
      n = 17;
      key_49(n);
    }
    else if(ADC_CV >= 126 && ADC_CV < 135) //D2
    {
      n = 18;
      key_49(n);
    }
    if(ADC_CV >= 136 && ADC_CV < 144) //D#2
    {
      n = 19;
      key_49(n);
    }
    else if(ADC_CV >= 145 && ADC_CV < 153) //E2
    {
      n = 20;
      key_49(n);
    }
    else if(ADC_CV >= 154 && ADC_CV < 162) //F2
    {
      n = 21;
      key_49(n);
    }
    else if(ADC_CV >= 163 && ADC_CV < 171) //F#2
    {
      n = 22;
      key_49(n);
    }
    else if(ADC_CV >= 172 && ADC_CV < 180) //G2
    {
      n = 23;
      key_49(n);
    }
    else if(ADC_CV >= 181 && ADC_CV < 189) //G#2
    {
      n = 24;
      key_49(n);
    }
    else if(ADC_CV >= 190 && ADC_CV < 198) //A2
    {
      n = 25;
      key_49(n);
    }
    else if(ADC_CV >= 199 && ADC_CV < 206) //A#2
    {
      n = 26;
      key_49(n);
    }
    else if(ADC_CV >= 207 && ADC_CV < 215) //B2
    {
      n = 27;
      key_49(n);
    }
  }


  else if (ADC_CV >= 216 && ADC_CV < 324) //C3 to B3
  {
    if(ADC_CV >= 216 && ADC_CV < 225) //C3
    {
      n = 28;
      key_49(n);
    }
    else if(ADC_CV >= 225 && ADC_CV < 235) //C#3
    {
      n = 29;
      key_49(n);
    }
    else if(ADC_CV >= 235 && ADC_CV < 243) //D3
    {
      n = 30;
      key_49(n);
    }
    else if(ADC_CV >= 243 && ADC_CV < 252) //D#3
    {
      n = 31;
      key_49(n);
    }
    else if(ADC_CV >= 252 && ADC_CV < 261) //E3
    {
      n = 32;
      key_49(n);
    }
    else if(ADC_CV >= 262 && ADC_CV < 268) //F3
    {
      n = 33;
      key_49(n);
    }
    else if(ADC_CV >= 271 && ADC_CV < 279) //F#3
    {
      n = 34;
      key_49(n);
    }
    else if(ADC_CV >= 279 && ADC_CV < 288) //G3
    {
      n = 35;
      key_49(n);
    }
    else if(ADC_CV >= 288 && ADC_CV < 297) //G#3
    {
      n = 36;
      key_49(n);
    }
    else if(ADC_CV >= 297 && ADC_CV < 306) //A3
    {
      n = 37;
      key_49(n);
    }
    else if(ADC_CV >= 306 && ADC_CV < 315) //A#3
    {
      n = 38;
      key_49(n);
    }
    else if(ADC_CV >= 315 && ADC_CV < 324) //B3
    {
      n = 39;
      key_49(n);
    }
  }

  else if (ADC_CV >= 324 && ADC_CV < 433) //C4 to B4
  {
    if(ADC_CV >= 324 && ADC_CV < 334) //C4
    {
      n = 40;
      key_49(n);
    }
    else if(ADC_CV >= 334 && ADC_CV < 342) //C#4
    {
      n = 41;
      key_49(n);
    }
    else if(ADC_CV >= 342 && ADC_CV < 351) //D4
    {
      n = 42;
      key_49(n);
    }
    else if(ADC_CV >= 351 && ADC_CV < 361) //D#4
    {
      n = 43;
      key_49(n);
    }
    else if(ADC_CV >= 361 && ADC_CV < 371) //E4
    {
      n = 44;
      key_49(n);
    }
    else if(ADC_CV >= 371 && ADC_CV < 380) //F4
    {
      n = 45;
      key_49(n);
    }
    else if(ADC_CV >= 380 && ADC_CV < 389) //F#4
    {
      n = 46;
      key_49(n);
    }
    else if(ADC_CV >= 389 && ADC_CV < 397) //G4
    {
      n = 47;
      key_49(n);
    }
    else if(ADC_CV >= 397 && ADC_CV < 407) //G#4
    {
      n = 48;
      key_49(n);
    }
    else if(ADC_CV >= 407 && ADC_CV < 416) //A4
    {
      n = 49;
      key_49(n);
    }
    else if(ADC_CV >= 416 && ADC_CV < 425) //A#4
    {
      n = 50;
      key_49(n);
    }
    else if(ADC_CV >= 425 && ADC_CV < 433) //B4
    {
      n = 51;
      key_49(n);
    }
  }

  else if (ADC_CV >= 433 && ADC_CV < 537) //C5 to B5
  {
    if(ADC_CV >= 433 && ADC_CV < 442) //C5
    {
      n = 52;
      key_49(n);
    }
    else if(ADC_CV >= 442 && ADC_CV < 452) //C#5
    {
      n = 53;
      key_49(n);
    }
    else if(ADC_CV >= 452 && ADC_CV < 460) //D5
    {
      n = 54;
      key_49(n);
    }
    else if(ADC_CV >= 460 && ADC_CV < 469) //D#5
    {
      n = 55;
      key_49(n);
    }
    else if(ADC_CV >= 469 && ADC_CV < 478) //E5
    {
      n = 56;
      key_49(n);
    }
    else if(ADC_CV >= 478 && ADC_CV < 487) //F5
    {
      n = 57;
      key_49(n);
    }
    else if(ADC_CV >= 487 && ADC_CV < 497) //F#5
    {
      n = 58;
      key_49(n);
    }
    else if(ADC_CV >= 497 && ADC_CV < 507) //G5
    {
      n = 59;
      key_49(n);
    }
    else if(ADC_CV >= 507 && ADC_CV < 516) //G#5
    {
      n = 60;
      key_49(n);
    }
    else if(ADC_CV >= 516 && ADC_CV < 525) //A5
    {
      n = 61;
      key_49(n);
    }
    else if(ADC_CV >= 525 && ADC_CV < 534) //A#5
    {
      n = 62;
      key_49(n);
    }
    else if(ADC_CV >= 534 && ADC_CV < 536) //B5
    {
      n = 63;
      key_49(n);
    }
  }

  else if(ADC_CV >= 539) //C6
  {
    n = 64;
    key_49(n);
    return;
  }
}