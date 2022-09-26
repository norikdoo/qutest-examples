#include "qpc.h"  /* QUTest interface */
#include "adc.h" /* CUT interface */

Q_DEFINE_THIS_FILE

/*--------------------------------------------------------------------------*/
// sometimes you may want to get at local data in a module.
// for example: If you plan to pass by reference, this could be useful
// however, it should often be avoided
extern int adc_value[ADC_CHANNEL_COUNT];

/*--------------------------------------------------------------------------*/
int main(int argc, char *argv[]) {

    QF_init();  /* initialize the framework */

    /* initialize the QS software tracing */
    Q_ALLEGE(QS_INIT(argc > 1 ? argv[1] : (void *)0));

    /* dictionaries... */
    /* called from ADC_init() */

    /* filter setup... */
    QS_GLB_FILTER(QS_ALL_RECORDS);

    return QF_run(); /* run the tests */
}

/*--------------------------------------------------------------------------*/
void QS_onTestSetup(void) {
}
/*..........................................................................*/
void QS_onTestTeardown(void) {
}

/*..........................................................................*/
void QS_onCommand(uint8_t cmdId,
                  uint32_t param1, uint32_t param2, uint32_t param3)
{
    switch (cmdId) {
        case 0: { /* call the CUT: ADC_init */
            ADC_init();
            break;
        }
        case 1: { /* call the CUT: ADC_read */
            ADC_read((uint8_t)param1);
            break;
        }
        default:
            break;
    }

    /* unused parametrers... */
    //(void)param1;
    (void)param2;
    (void)param3;
}
/*..........................................................................*/
/* host callback function to "massage" the event, if necessary */
void QS_onTestEvt(QEvt *e) {
    (void)e;
#ifdef Q_HOST  /* is this test compiled for a desktop Host computer? */
#else /* this test is compiled for an embedded Target system */
#endif
}
/*..........................................................................*/
/*! callback function to output the posted QP events (not used here) */
void QS_onTestPost(void const *sender, QActive *recipient,
                   QEvt const *e, bool status)
{
    (void)sender;
    (void)recipient;
    (void)e;
    (void)status;
}
