#include <stdint.h>
#include "CUT.h"
#include "Led.h"

void setLed(uint8_t value)
{
    switch (value)
    {
    case 0:
        Led_off();
        break;
    case 1:
        Led_on();
        break;
    default:
        break;
    }
}
