#include "qpc.h"
#include "adc.h"

#include "qassert.h" /* for embedded systems-friendly assertions */

Q_DEFINE_THIS_MODULE("ADC")

enum {
   ADC = QS_USER
};

#ifdef Q_SPY
static int raw_value[ADC_CHANNEL_COUNT];
#endif

static void ADC_QS_dictonaries()
{
    QS_USR_DICTIONARY(ADC);
    QS_FUN_DICTIONARY(&ADC_init);
    QS_FUN_DICTIONARY(&ADC_read);
    QS_OBJ_DICTIONARY(&raw_value);
}

/*..........................................................................*/
int ADC_init()
{
    int ret = 0;
    int i;

    /* Trace dictionaries init */
    ADC_QS_dictonaries();

    /* ADC_init implementation here */
#ifdef Q_SPY
    for (i = 0; i < ADC_CHANNEL_COUNT; i++)
    {
        raw_value[i] = 0xFF;
    }
#endif

    /* Trace */
    QS_BEGIN(ADC, 0)
        QS_FUN(&ADC_init);
        QS_I32(0, ret);
    QS_END()

    return ret;
}

uint8_t ADC_read(unsigned int ch)
{
    unsigned int val = 0;

    Q_ASSERT(ch < ADC_CHANNEL_COUNT);

    /* ADC_read implementation here */
    switch (ch)
    {
#ifdef Q_SPY
    case 0:
        val = raw_value[0];
        break;
    case 1:
        val = raw_value[1];
        break;
    default:
        break;
#else
    /* Read from some register */
    default:
        break;
#endif
    }

    /* Trace */
    QS_BEGIN(ADC, 0)
        QS_FUN(&ADC_read);
        QS_U32(0, ch);
        QS_U8(0, val);
    QS_END()

    return val;
}
