#include "Cu29_Library.h"

void ADC_to_key (short ADC_CV)
{

    // 1. If the ADC value is below 216, return without doing anything.
    if (ADC_CV < 216) return;

    // 2. Convert the ADC reading into an index. Index = (ADC-216)/17
    //    We use a while loop instead of dividing, because division is SLOW.
    char index = 0;
    ADC_CV = ADC_CV - 216;

    while(ADC_CV > 18)
    {
        ADC_CV = ADC_CV - 18;
        index++;
    }

    // 3. Check how many samples to skip.
    if (index > 22) samples = 4;
    else if(index > 11) samples = 2;
    else samples = 1;

    // 4. Calculate the appropriate timer scale value.
    char timerScale = 0xB0;
    if (index > 22) timerScale = 0xA0;

    // 5. Look up the appropriate period using an array.
    const char periodArray[] = {
        119, 113, 106, 100,
         95,  89,  84,  80,  75,  71,  67,  63,
        119, 113, 106, 100,  95,  89,  84,  80,
         75,  71,  67, 253, 239, 225, 213, 201,
        190, 179, 169, 159, 150, 142, 134, 127,
        119
    };

    char timerPeriod = periodArray[index];

    ConfigureTimer2(timerPeriod, timerScale)


}
