#include "qpc.h"
#include "CUT.h"

Q_DEFINE_THIS_FILE /* used in reporting assertions in this module. */

void Led_DICTIONARY(void);

int main(int argc, char *argv[]) {

    QF_init();  /* initialize the framework */

    /* initialize the QS software tracing */
    Q_ALLEGE(QS_INIT(argc > 1 ? argv[1] : (void *)0)); // Q_ALLEGE assertion fires if the QS initialization fails 

    /* produce QS dictionaries for all functions you wish to 
       test as well as objects you might need to inspect */
    Led_DICTIONARY();
    QS_FUN_DICTIONARY(&setLed);

    /* filter setup... */
    QS_GLB_FILTER(QS_ALL_RECORDS);

    return QF_run(); /* run the tests */
}

void QS_onTestSetup(void) {
}

void QS_onTestTeardown(void) {
}

/* called on command(). This allows you to remotely execute commands inside the Target. 
   Here is where you execute the CUT and report results back to QSPY                 */

void QS_onCommand(uint8_t cmdId,
                  uint32_t param1, uint32_t param2, uint32_t param3)
{
    switch (cmdId) {
        case 0: { 
            setLed((uint8_t)param1);
            QS_BEGIN_ID(QS_USER + cmdId, 0U) // user-specific record
                QS_FUN(&setLed); 
                QS_U8 (0, (uint8_t)param1);
            QS_END() // QSPY output: USER+000 setLed 0 or USER+000 setLed 1
            break;
        }
        default:
            break;
    }

    (void)param2;
    (void)param3;
}

void QS_onTestEvt(QEvt *e) {
    (void)e;
#ifdef Q_HOST  
#else 
#endif
}

void QS_onTestPost(void const *sender, QActive *recipient,
                   QEvt const *e, bool status)
{
    (void)sender;
    (void)recipient;
    (void)e;
    (void)status;
}
