/*.$file${.::bsp.c} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*
* Model: blinky_console.qm
* File:  ${.::bsp.c}
*
* This code has been generated by QM 5.1.4 <www.state-machine.com/qm/>.
* DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
*
* This program is open source software: you can redistribute it and/or
* modify it under the terms of the GNU General Public License as published
* by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
* or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
* for more details.
*/
/*.$endhead${.::bsp.c} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
/* Board Support Package implementation for desktop OS (Windows, Linux, MacOS) */
#include "qpc.h"    /* QP/C framework API */
#include "bsp.h"    /* Board Support Package interface */
#include "blinky.h"

#include "stm32l0xx.h"

Q_DEFINE_THIS_FILE

#define LED_LD2  (1U << 5)

enum { /* application-specific trace records */
    LED = QS_USER
};

void BSP_init(void) {
    /* NOTE: SystemInit() has been already called from the startup code
    *  but SystemCoreClock needs to be updated
    */
    SystemCoreClockUpdate();

    /* enable GPIOA clock port for the LED LD2 */
    RCC->IOPENR |= (1U << 0);

    /* configure LED (PA.5) pin as push-pull output, no pull-up, pull-down */
    GPIOA->MODER   &= ~((3U << 2*5));
    GPIOA->MODER   |=  ((1U << 2*5));
    GPIOA->OTYPER  &= ~((1U <<   5));
    GPIOA->OSPEEDR &= ~((3U << 2*5));
    GPIOA->OSPEEDR |=  ((1U << 2*5));
    GPIOA->PUPDR   &= ~((3U << 2*5));

    if (QS_INIT((void *)0) == 0U) {
        Q_ERROR();
    }

    QS_FUN_DICTIONARY(&QHsm_top);
    QS_USR_DICTIONARY(LED);

    /* setup the QS filters... */
    QS_GLB_FILTER(QS_SM_RECORDS);
    QS_GLB_FILTER(QS_UA_RECORDS);
}

void BSP_ledOn(void) {
    GPIOA->BSRR |= (LED_LD2);        /* turn LED2 on  */

    QS_BEGIN_ID(LED, AO_Blinky->prio) /* app-specific record */
        QS_STR("ON");                 /* Status */
    QS_END()
}

void BSP_ledOff(void) {
    GPIOA->BSRR |= (LED_LD2 << 16);  /* turn LED2 off */

    QS_BEGIN_ID(LED, AO_Blinky->prio) /* app-specific record */
        QS_STR("OFF");                 /* Status */
    QS_END()
}