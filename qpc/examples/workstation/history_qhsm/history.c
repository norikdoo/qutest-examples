/*$file${.::history.c} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*
* Model: history.qm
* File:  ${.::history.c}
*
* This code has been generated by QM 5.2.1 <www.state-machine.com/qm>.
* DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
*
* SPDX-License-Identifier: GPL-3.0-or-later
*
* This generated code is open source software: you can redistribute it under
* the terms of the GNU General Public License as published by the Free
* Software Foundation.
*
* This code is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* NOTE:
* Alternatively, this generated code may be distributed under the terms
* of Quantum Leaps commercial licenses, which expressly supersede the GNU
* General Public License and are specifically designed for licensees
* interested in retaining the proprietary status of their code.
*
* Contact information:
* <www.state-machine.com/licensing>
* <info@state-machine.com>
*/
/*$endhead${.::history.c} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
#include "qpc.h"
#include "history.h"

#include "safe_std.h" /* portable "safe" <stdio.h>/<string.h> facilities */
#include <stdlib.h>

//Q_DEFINE_THIS_FILE

/*$declare${SMs::ToastOven} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/

/*${SMs::ToastOven} ........................................................*/
typedef struct {
/* protected: */
    QHsm super;

/* private state histories */
    QStateHandler hist_doorClosed;
    QStateHandler hist_heating;
} ToastOven;

/* protected: */
static QState ToastOven_initial(ToastOven * const me, void const * const par);
static QState ToastOven_doorClosed(ToastOven * const me, QEvt const * const e);
static QState ToastOven_heating(ToastOven * const me, QEvt const * const e);
static QState ToastOven_toasting(ToastOven * const me, QEvt const * const e);
static QState ToastOven_baking(ToastOven * const me, QEvt const * const e);
static QState ToastOven_off(ToastOven * const me, QEvt const * const e);
static QState ToastOven_doorOpen(ToastOven * const me, QEvt const * const e);
static QState ToastOven_final(ToastOven * const me, QEvt const * const e);
/*$enddecl${SMs::ToastOven} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/

static ToastOven l_oven; /* the only instance of the ToastOven class */

/* global-scope definitions -----------------------------------------*/
QHsm * const the_oven = &l_oven.super; /* the opaque pointer */

/*$skip${QP_VERSION} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/* Check for the minimum required QP version */
#if (QP_VERSION < 690U) || (QP_VERSION != ((QP_RELEASE^4294967295U) % 0x3E8U))
#error qpc version 6.9.0 or higher required
#endif
/*$endskip${QP_VERSION} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/

/*$define${SMs::ToastOven_ctor} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/

/*${SMs::ToastOven_ctor} ...................................................*/
void ToastOven_ctor(void) {
    ToastOven *me = &l_oven;
    QHsm_ctor(&me->super, Q_STATE_CAST(&ToastOven_initial));
}
/*$enddef${SMs::ToastOven_ctor} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
/*$define${SMs::ToastOven} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/

/*${SMs::ToastOven} ........................................................*/

/*${SMs::ToastOven::SM} ....................................................*/
static QState ToastOven_initial(ToastOven * const me, void const * const par) {
    /*${SMs::ToastOven::SM::initial} */
    (void)par; /* unused parameter */
    /* state history attributes */
    me->hist_doorClosed = Q_STATE_CAST(&ToastOven_off);
    me->hist_heating = Q_STATE_CAST(&ToastOven_baking);
    return Q_TRAN(&ToastOven_doorClosed);
}

/*${SMs::ToastOven::SM::doorClosed} ........................................*/
static QState ToastOven_doorClosed(ToastOven * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /*${SMs::ToastOven::SM::doorClosed} */
        case Q_ENTRY_SIG: {
            PRINTF_S("%s;", "door-Closed");
            status_ = Q_HANDLED();
            break;
        }
        /*${SMs::ToastOven::SM::doorClosed} */
        case Q_EXIT_SIG: {
            /* save shallow history */
            me->hist_doorClosed =
                QHsm_childState(Q_HSM_UPCAST(me),
                                Q_STATE_CAST(&ToastOven_doorClosed));
            status_ = Q_HANDLED();
            break;
        }
        /*${SMs::ToastOven::SM::doorClosed::initial} */
        case Q_INIT_SIG: {
            status_ = Q_TRAN(&ToastOven_off);
            break;
        }
        /*${SMs::ToastOven::SM::doorClosed::TERMINATE} */
        case TERMINATE_SIG: {
            status_ = Q_TRAN(&ToastOven_final);
            break;
        }
        /*${SMs::ToastOven::SM::doorClosed::OPEN} */
        case OPEN_SIG: {
            status_ = Q_TRAN(&ToastOven_doorOpen);
            break;
        }
        /*${SMs::ToastOven::SM::doorClosed::TOAST} */
        case TOAST_SIG: {
            status_ = Q_TRAN(&ToastOven_toasting);
            break;
        }
        /*${SMs::ToastOven::SM::doorClosed::BAKE} */
        case BAKE_SIG: {
            status_ = Q_TRAN(&ToastOven_baking);
            break;
        }
        /*${SMs::ToastOven::SM::doorClosed::OFF} */
        case OFF_SIG: {
            status_ = Q_TRAN(&ToastOven_off);
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status_;
}

/*${SMs::ToastOven::SM::doorClosed::heating} ...............................*/
static QState ToastOven_heating(ToastOven * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /*${SMs::ToastOven::SM::doorClosed::heating} */
        case Q_ENTRY_SIG: {
            PRINTF_S("%s;", "heater-On");
            status_ = Q_HANDLED();
            break;
        }
        /*${SMs::ToastOven::SM::doorClosed::heating} */
        case Q_EXIT_SIG: {
            PRINTF_S("%s;", "heater-Off");
            /* save deep history */
            me->hist_heating = QHsm_state(Q_HSM_UPCAST(me));
            status_ = Q_HANDLED();
            break;
        }
        /*${SMs::ToastOven::SM::doorClosed::heating::initial} */
        case Q_INIT_SIG: {
            status_ = Q_TRAN(&ToastOven_toasting);
            break;
        }
        default: {
            status_ = Q_SUPER(&ToastOven_doorClosed);
            break;
        }
    }
    return status_;
}

/*${SMs::ToastOven::SM::doorClosed::heating::toasting} .....................*/
static QState ToastOven_toasting(ToastOven * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /*${SMs::ToastOven::SM::doorClosed::heating::toasting} */
        case Q_ENTRY_SIG: {
            PRINTF_S("%s;", "toasting");
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&ToastOven_heating);
            break;
        }
    }
    return status_;
}

/*${SMs::ToastOven::SM::doorClosed::heating::baking} .......................*/
static QState ToastOven_baking(ToastOven * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /*${SMs::ToastOven::SM::doorClosed::heating::baking} */
        case Q_ENTRY_SIG: {
            PRINTF_S("%s;", "baking");
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&ToastOven_heating);
            break;
        }
    }
    return status_;
}

/*${SMs::ToastOven::SM::doorClosed::off} ...................................*/
static QState ToastOven_off(ToastOven * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /*${SMs::ToastOven::SM::doorClosed::off} */
        case Q_ENTRY_SIG: {
            PRINTF_S("%s;", "toaster-Off");
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&ToastOven_doorClosed);
            break;
        }
    }
    return status_;
}

/*${SMs::ToastOven::SM::doorOpen} ..........................................*/
static QState ToastOven_doorOpen(ToastOven * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /*${SMs::ToastOven::SM::doorOpen} */
        case Q_ENTRY_SIG: {
            PRINTF_S("%s;", "door-Open,lamp-On");
            status_ = Q_HANDLED();
            break;
        }
        /*${SMs::ToastOven::SM::doorOpen} */
        case Q_EXIT_SIG: {
            PRINTF_S("%s;", "lamp-Off");
            status_ = Q_HANDLED();
            break;
        }
        /*${SMs::ToastOven::SM::doorOpen::CLOSE} */
        case CLOSE_SIG: {
            status_ = Q_TRAN_HIST(me->hist_heating);
            break;
        }
        /*${SMs::ToastOven::SM::doorOpen::TERMINATE} */
        case TERMINATE_SIG: {
            status_ = Q_TRAN(&ToastOven_final);
            break;
        }
        /*${SMs::ToastOven::SM::doorOpen::OFF} */
        case OFF_SIG: {
            status_ = Q_TRAN_HIST(me->hist_doorClosed);
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status_;
}

/*${SMs::ToastOven::SM::final} .............................................*/
static QState ToastOven_final(ToastOven * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /*${SMs::ToastOven::SM::final} */
        case Q_ENTRY_SIG: {
            PRINTF_S("\n%s\n", "Bye! Bye!");
            QF_onCleanup();
            exit(0);
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status_;
}
/*$enddef${SMs::ToastOven} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
