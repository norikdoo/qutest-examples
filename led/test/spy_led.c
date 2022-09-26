#include "qpc.h"
#include "Led.h"

enum {
    LED = QS_USER1 // QS app-specific record for the LED module - Used for filtering
};                 

/* Dictionary - associates the binary address of object in target's 
   memory with the human-readable name of the object
*/
void Led_DICTIONARY(void) { 
    QS_FUN_DICTIONARY(&Led_on);
    QS_FUN_DICTIONARY(&Led_off);
    QS_USR_DICTIONARY(LED);
}

void Led_init(void ){
}

void Led_off(void) {
    QS_BEGIN_ID(LED, 0U); // Begin an application-specific (user) QS record (1) with object-id (2) for the local filter.
        QS_FUN(&Led_off); // Outputs name of a function
    QS_END() // End a QS record with exiting critical section
    // QSPY output: LED Led_off
}

void Led_on(void) {
    QS_BEGIN_ID(LED, 0U);
        QS_FUN(&Led_on);
    QS_END() 
    // QSPY output: LED Led_on
}
