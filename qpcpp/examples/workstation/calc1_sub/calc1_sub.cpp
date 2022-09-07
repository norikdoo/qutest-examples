//$file${.::calc1_sub.cpp} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
//
// Model: calc1_sub.qm
// File:  ${.::calc1_sub.cpp}
//
// This code has been generated by QM 5.2.0 <www.state-machine.com/qm>.
// DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
//
// This code is covered by the following QP license:
// License #    : QM-EVAL-QPCPP
// Issued to    : Users of QP/C++ Real-Time Embedded Framework (RTEF)
// Framework(s) : qpcpp
// Support ends : 2023-12-31
// License scope:
//
// SPDX-License-Identifier: GPL-3.0-or-later
//
// This generated code is free software: you can redistribute it under
// the terms of the GNU General Public License as published by the Free
// Software Foundation.
//
// This code is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// more details.
//
// NOTE:
// Alternatively, this generated code may be distributed under the terms
// of Quantum Leaps commercial licenses, which expressly supersede the GNU
// General Public License and are specifically designed for licensees
// interested in retaining the proprietary status of their code.
//
// Contact information:
// <www.state-machine.com/licensing>
// <info@state-machine.com>
//
//$endhead${.::calc1_sub.cpp} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#include "qpcpp.hpp"     // QP/C++ API
#include "bsp.hpp"       // board support package
#include "calc1_sub.hpp" // application

Q_DEFINE_THIS_FILE

#define KEY_NULL    '\0'
#define KEY_PLUS    '+'
#define KEY_MINUS   '-'
#define KEY_MULT    '*'
#define KEY_DIVIDE  '/'

//$declare${SMs::Calc} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

//${SMs::Calc} ...............................................................
class Calc : public QP::QMsm {
public:
    static Calc inst;

private:
    double m_op1;
    double m_op2;
    uint8_t m_oper1;
    uint8_t m_oper2;

public:
    Calc();

    // guard function to evaluate the current expression
    // taking into account the precedence of operands.
    // return: true if evaluation successfull
    // false when error encountered
    bool eval(
        double op,
        uint8_t oper);

protected:
    // exit points for submachine ${SMs::Calc::SM::operand}
    struct SM_operand {
        QP::QMState super;
        QP::QActionHandler const CE; // exit-point segment
    } const *sub_operand;

    QM_STATE_DECL( initial);
    QM_STATE_DECL( on);
    QM_ACTION_DECL(on_e);
    QM_ACTION_DECL(on_x);
    QM_ACTION_DECL(on_i);
    QM_STATE_DECL( ready);
    QM_ACTION_DECL(ready_e);
    QM_ACTION_DECL(ready_x);
    QM_ACTION_DECL(ready_i);
    QM_STATE_DECL( result);
    QM_ACTION_DECL(result_e);
    QM_ACTION_DECL(result_x);
    QM_STATE_DECL( begin);
    QM_ACTION_DECL(begin_e);
    QM_ACTION_DECL(begin_x);
    QM_SM_STATE_DECL(operand, operand1);
    QM_ACTION_DECL(operand1_e);
    QM_ACTION_DECL(operand1_CE);
    QM_STATE_DECL( opEntered);
    QM_ACTION_DECL(opEntered_e);
    QM_ACTION_DECL(opEntered_x);
    QM_SM_STATE_DECL(operand, operand2);
    QM_ACTION_DECL(operand2_e);
    QM_ACTION_DECL(operand2_CE);
    QM_STATE_DECL( error);
    QM_ACTION_DECL(error_e);
    QM_ACTION_DECL(error_x);
    QM_STATE_DECL( final);
    QM_ACTION_DECL(final_e);

    // submachine ${SMs::Calc::SM::operand}
    QM_STATE_DECL( operand);
    QM_ACTION_DECL(operand_e);
    QM_ACTION_DECL(operand_x);
    QM_ACTION_DECL(operand_i);
    QM_ACTION_DECL(operand_zero_ep);
    QM_ACTION_DECL(operand_intgr_ep);
    QM_ACTION_DECL(operand_frac_ep);
    QM_ACTION_DECL(operand_neg_ep);
    QM_STATE_DECL( operand_zero);
    QM_ACTION_DECL(operand_zero_e);
    QM_ACTION_DECL(operand_zero_x);
    QM_STATE_DECL( operand_intgr);
    QM_ACTION_DECL(operand_intgr_e);
    QM_ACTION_DECL(operand_intgr_x);
    QM_STATE_DECL( operand_frac);
    QM_ACTION_DECL(operand_frac_e);
    QM_ACTION_DECL(operand_frac_x);
    QM_STATE_DECL( operand_neg);
    QM_ACTION_DECL(operand_neg_e);
    QM_ACTION_DECL(operand_neg_x);
}; // class Calc
//$enddecl${SMs::Calc} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//$skip${QP_VERSION} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
// Check for the minimum required QP version
#if (QP_VERSION < 690U) || (QP_VERSION != ((QP_RELEASE^4294967295U) % 0x3E8U))
#error qpcpp version 6.9.0 or higher required
#endif
//$endskip${QP_VERSION} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//$define${SMs::the_calc} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

//${SMs::the_calc} ...........................................................
QP::QHsm * const the_calc = &Calc::inst;
//$enddef${SMs::the_calc} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//$define${SMs::Calc} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

//${SMs::Calc} ...............................................................
Calc Calc::inst;

//${SMs::Calc::Calc} .........................................................
Calc::Calc()
  : QMsm(&initial)
{}

//${SMs::Calc::eval} .........................................................
bool Calc::eval(
    double op,
    uint8_t oper)
{
    double result;
    if ((oper == KEY_NULL) || (oper == KEY_PLUS) || (oper == KEY_MINUS)) {
        switch (m_oper2) {
            case KEY_MULT: {
                m_op2 *= op;
                break;
            }
            case KEY_DIVIDE: {
                if ((-1e-30 < op) && (op < 1e-30)) {
                    BSP_display_error(" Error 0 "); // divide by zero
                    return false;
                }
                m_op2 /= op;
                break;
             }
             default: { /* no op2 yet */
                m_op2 = op;
                m_oper2 = oper;
                break;
             }
        }
        switch (m_oper1) {
            case KEY_PLUS: {
                m_op1 += m_op2;
                break;
            }
            case KEY_MINUS: {
                m_op1 -= m_op2;
                break;
            }
            case KEY_MULT: {
                m_op1 *= m_op2;
                break;
            }
            case KEY_DIVIDE: {
                if ((-1e-30 < m_op2) && (m_op2 < 1e-30)) {
                    BSP_display_error(" Error 0 "); // divide by zero
                    return false;
                }
                m_op1 /= m_op2;
                break;
            }
            default: {
                Q_ERROR();
                break;
            }
        }
        m_oper1 = oper;
        m_oper2 = KEY_NULL;
        result = m_op1;
    }
    else { // (oper == KEY_MULT) || (oper == KEY_DIV)
        switch (m_oper2) {
            case KEY_MULT: {
                m_op2 *= op;
                break;
            }
            case KEY_DIVIDE: {
                if ((-1e-30 < op) && (op < 1e-30)) {
                    BSP_display_error(" Error 0 "); // divide by zero
                    return false;
                }
                m_op2 /= op;
                break;
            }
            default: { // oper2 not provided yet
                m_op2 = op;
                break;
            }
        }
        m_oper2 = oper;
        result = m_op2;
    }

    if ((result < -99999999.0) || (99999999.0 < result)) {
        BSP_display_error(" Error 1 "); // out of range
        return false;
    }
    if ((-0.0000001 < result) && (result < 0.0000001)) {
        result = 0.0;
    }
    BSP_display(result);

    return true;
}

//${SMs::Calc::SM} ...........................................................
QM_STATE_DEF(Calc, initial) {
    //${SMs::Calc::SM::initial}
    BSP_clear();
    (void)e; // unused parameter

    QS_FUN_DICTIONARY(&Calc::on);
    QS_FUN_DICTIONARY(&Calc::ready);
    QS_FUN_DICTIONARY(&Calc::result);
    QS_FUN_DICTIONARY(&Calc::begin);
    QS_FUN_DICTIONARY(&Calc::operand1);
    QS_FUN_DICTIONARY(&Calc::opEntered);
    QS_FUN_DICTIONARY(&Calc::operand2);
    QS_FUN_DICTIONARY(&Calc::error);
    QS_FUN_DICTIONARY(&Calc::final);
    QS_FUN_DICTIONARY(&Calc::operand_zero);
    QS_FUN_DICTIONARY(&Calc::operand_intgr);
    QS_FUN_DICTIONARY(&Calc::operand_frac);
    QS_FUN_DICTIONARY(&Calc::operand_neg);
    QS_FUN_DICTIONARY(&Calc::operand);

    static struct {
        QP::QMState const *target;
        QP::QActionHandler act[3];
    } const tatbl_ = { // tran-action table
        &on_s, // target state
        {
            &on_e, // entry
            &on_i, // initial tran.
            Q_ACTION_NULL // zero terminator
        }
    };
    return qm_tran_init(&tatbl_);
}

//${SMs::Calc::SM::on} .......................................................
QP::QMState const Calc::on_s = {
    QM_STATE_NULL, // superstate (top)
    &Calc::on,
    &Calc::on_e,
    &Calc::on_x,
    &Calc::on_i
};
//${SMs::Calc::SM::on}
QM_ACTION_DEF(Calc, on_e) {
    BSP_message("on-ENTRY;");
    return qm_entry(&on_s);
}
//${SMs::Calc::SM::on}
QM_ACTION_DEF(Calc, on_x) {
    BSP_message("on-EXIT;");
    return qm_exit(&on_s);
}
//${SMs::Calc::SM::on::initial}
QM_ACTION_DEF(Calc, on_i) {
    //${SMs::Calc::SM::on::initial}
    BSP_message("on-INIT;");

    static struct {
        QP::QMState const *target;
        QP::QActionHandler act[3];
    } const tatbl_ = { // tran-action table
        &ready_s, // target state
        {
            &ready_e, // entry
            &ready_i, // initial tran.
            Q_ACTION_NULL // zero terminator
        }
    };
    return qm_tran_init(&tatbl_);
}
//${SMs::Calc::SM::on}
QM_STATE_DEF(Calc, on) {
    QP::QState status_;
    switch (e->sig) {
        //${SMs::Calc::SM::on::C}
        case C_SIG: {
            BSP_clear();

            static struct {
                QP::QMState const *target;
                QP::QActionHandler act[4];
            } const tatbl_ = { // tran-action table
                &on_s, // target state
                {
                    &on_x, // exit
                    &on_e, // entry
                    &on_i, // initial tran.
                    Q_ACTION_NULL // zero terminator
                }
            };
            status_ = qm_tran(&tatbl_);
            break;
        }
        //${SMs::Calc::SM::on::OFF}
        case OFF_SIG: {

            static struct {
                QP::QMState const *target;
                QP::QActionHandler act[3];
            } const tatbl_ = { // tran-action table
                &final_s, // target state
                {
                    &on_x, // exit
                    &final_e, // entry
                    Q_ACTION_NULL // zero terminator
                }
            };
            status_ = qm_tran(&tatbl_);
            break;
        }
        default: {
            status_ = Q_RET_SUPER;
            break;
        }
    }
    return status_;
}

//${SMs::Calc::SM::on::ready} ................................................
QP::QMState const Calc::ready_s = {
    &Calc::on_s, // superstate
    &Calc::ready,
    &Calc::ready_e,
    &Calc::ready_x,
    &Calc::ready_i
};
//${SMs::Calc::SM::on::ready}
QM_ACTION_DEF(Calc, ready_e) {
    BSP_message("ready-ENTRY;");
    m_oper2 = KEY_NULL;
    return qm_entry(&ready_s);
}
//${SMs::Calc::SM::on::ready}
QM_ACTION_DEF(Calc, ready_x) {
    BSP_message("ready-EXIT;");
    return qm_exit(&ready_s);
}
//${SMs::Calc::SM::on::ready::initial}
QM_ACTION_DEF(Calc, ready_i) {
    //${SMs::Calc::SM::on::ready::initial}
    BSP_message("ready-INIT;");

    static struct {
        QP::QMState const *target;
        QP::QActionHandler act[2];
    } const tatbl_ = { // tran-action table
        &begin_s, // target state
        {
            &begin_e, // entry
            Q_ACTION_NULL // zero terminator
        }
    };
    return qm_tran_init(&tatbl_);
}
//${SMs::Calc::SM::on::ready}
QM_STATE_DEF(Calc, ready) {
    QP::QState status_;
    switch (e->sig) {
        //${SMs::Calc::SM::on::ready::DIGIT_0}
        case DIGIT_0_SIG: {
            BSP_clear();

            static struct {
                QP::QMState const *target;
                QP::QActionHandler act[4];
            } const tatbl_ = { // tran-action table
                &operand_s, // target submachine
                {
                    &ready_x, // exit
                    &operand1_e, // entry
                    &operand_zero_ep, // EP
                    Q_ACTION_NULL // zero terminator
                }
            };
            status_ = qm_tran_ep(&tatbl_);
            break;
        }
        //${SMs::Calc::SM::on::ready::DIGIT_1_9}
        case DIGIT_1_9_SIG: {
            BSP_clear();
            BSP_insert(Q_EVT_CAST(CalcEvt)->key_code);

            static struct {
                QP::QMState const *target;
                QP::QActionHandler act[4];
            } const tatbl_ = { // tran-action table
                &operand_s, // target submachine
                {
                    &ready_x, // exit
                    &operand1_e, // entry
                    &operand_intgr_ep, // EP
                    Q_ACTION_NULL // zero terminator
                }
            };
            status_ = qm_tran_ep(&tatbl_);
            break;
        }
        //${SMs::Calc::SM::on::ready::POINT}
        case POINT_SIG: {
            BSP_clear();
            BSP_insert((int)'0');
            BSP_insert((int)'.');

            static struct {
                QP::QMState const *target;
                QP::QActionHandler act[4];
            } const tatbl_ = { // tran-action table
                &operand_s, // target submachine
                {
                    &ready_x, // exit
                    &operand1_e, // entry
                    &operand_frac_ep, // EP
                    Q_ACTION_NULL // zero terminator
                }
            };
            status_ = qm_tran_ep(&tatbl_);
            break;
        }
        //${SMs::Calc::SM::on::ready::OPER}
        case OPER_SIG: {
            m_op1  = BSP_get_value();
            m_oper1 = Q_EVT_CAST(CalcEvt)->key_code;

            static struct {
                QP::QMState const *target;
                QP::QActionHandler act[3];
            } const tatbl_ = { // tran-action table
                &opEntered_s, // target state
                {
                    &ready_x, // exit
                    &opEntered_e, // entry
                    Q_ACTION_NULL // zero terminator
                }
            };
            status_ = qm_tran(&tatbl_);
            break;
        }
        default: {
            status_ = Q_RET_SUPER;
            break;
        }
    }
    return status_;
}

//${SMs::Calc::SM::on::ready::result} ........................................
QP::QMState const Calc::result_s = {
    &Calc::ready_s, // superstate
    &Calc::result,
    &Calc::result_e,
    &Calc::result_x,
    Q_ACTION_NULL  // no initial tran.
};
//${SMs::Calc::SM::on::ready::result}
QM_ACTION_DEF(Calc, result_e) {
    BSP_message("result-ENTRY;");
    return qm_entry(&result_s);
}
//${SMs::Calc::SM::on::ready::result}
QM_ACTION_DEF(Calc, result_x) {
    BSP_message("result-EXIT;");
    return qm_exit(&result_s);
}
//${SMs::Calc::SM::on::ready::result}
QM_STATE_DEF(Calc, result) {
    QP::QState status_;
    switch (e->sig) {
        default: {
            status_ = Q_RET_SUPER;
            break;
        }
    }
    return status_;
}

//${SMs::Calc::SM::on::ready::begin} .........................................
QP::QMState const Calc::begin_s = {
    &Calc::ready_s, // superstate
    &Calc::begin,
    &Calc::begin_e,
    &Calc::begin_x,
    Q_ACTION_NULL  // no initial tran.
};
//${SMs::Calc::SM::on::ready::begin}
QM_ACTION_DEF(Calc, begin_e) {
    BSP_message("begin-ENTRY;");
    return qm_entry(&begin_s);
}
//${SMs::Calc::SM::on::ready::begin}
QM_ACTION_DEF(Calc, begin_x) {
    BSP_message("begin-EXIT;");
    return qm_exit(&begin_s);
}
//${SMs::Calc::SM::on::ready::begin}
QM_STATE_DEF(Calc, begin) {
    QP::QState status_;
    switch (e->sig) {
        //${SMs::Calc::SM::on::ready::begin::OPER}
        case OPER_SIG: {
            //${SMs::Calc::SM::on::ready::begin::OPER::[e->key=='-']}
            if (Q_EVT_CAST(CalcEvt)->key_code == KEY_MINUS) {

                static struct {
                    QP::QMState const *target;
                    QP::QActionHandler act[5];
                } const tatbl_ = { // tran-action table
                    &operand_s, // target submachine
                    {
                        &begin_x, // exit
                        &ready_x, // exit
                        &operand1_e, // entry
                        &operand_neg_ep, // EP
                        Q_ACTION_NULL // zero terminator
                    }
                };
                status_ = qm_tran_ep(&tatbl_);
            }
            //${SMs::Calc::SM::on::ready::begin::OPER::[else]}
            else {
                status_ = Q_RET_HANDLED;
            }
            break;
        }
        default: {
            status_ = Q_RET_SUPER;
            break;
        }
    }
    return status_;
}

//${SMs::Calc::SM::on::operand1} .............................................
Calc::SM_operand const Calc::operand1_s = {
    {
        &Calc::on_s, // superstate
        &Calc::operand1,
        &Calc::operand1_e,
        Q_ACTION_NULL, // no exit action
        Q_ACTION_NULL  // no initial tran.
    },
    &Calc::operand1_CE
};
//${SMs::Calc::SM::on::operand1}
QM_ACTION_DEF(Calc, operand1_e) {
    sub_operand = &Calc::operand1_s; // attach submachine
    return operand_e(this); // enter submachine
}
//${SMs::Calc::SM::on::operand1}
QM_ACTION_DEF(Calc, operand1_CE) {
    BSP_message("operand1:XP-CE;");

    static struct {
        QP::QMState const *target;
        QP::QActionHandler act[4];
    } const tatbl_ = { // tran-action table
        &ready_s, // target state
        {
            &operand_x, // submachine exit
            &ready_e, // entry
            &ready_i, // initial tran.
            Q_ACTION_NULL // zero terminator
        }
    };
    return qm_tran(&tatbl_);
}
//${SMs::Calc::SM::on::operand1}
QM_STATE_DEF(Calc, operand1) {
    QP::QState status_;
    switch (e->sig) {
        //${SMs::Calc::SM::on::operand1::OPER}
        case OPER_SIG: {
            m_op1  = BSP_get_value();
            m_oper1 = Q_EVT_CAST(CalcEvt)->key_code;

            static struct {
                QP::QMState const *target;
                QP::QActionHandler act[2];
            } const tatbl_ = { // tran-action table
                &opEntered_s, // target state
                {
                    &opEntered_e, // entry
                    Q_ACTION_NULL // zero terminator
                }
            };
            status_ = qm_tran(&tatbl_);
            break;
        }
        //${SMs::Calc::SM::on::operand1::EQUALS}
        case EQUALS_SIG: {

            static struct {
                QP::QMState const *target;
                QP::QActionHandler act[3];
            } const tatbl_ = { // tran-action table
                &result_s, // target state
                {
                    &ready_e, // entry
                    &result_e, // entry
                    Q_ACTION_NULL // zero terminator
                }
            };
            status_ = qm_tran(&tatbl_);
            break;
        }
        default: {
            status_ = Q_RET_SUPER;
            break;
        }
    }
    return status_;
}

//${SMs::Calc::SM::on::opEntered} ............................................
QP::QMState const Calc::opEntered_s = {
    &Calc::on_s, // superstate
    &Calc::opEntered,
    &Calc::opEntered_e,
    &Calc::opEntered_x,
    Q_ACTION_NULL  // no initial tran.
};
//${SMs::Calc::SM::on::opEntered}
QM_ACTION_DEF(Calc, opEntered_e) {
    BSP_message("opEntered-ENTRY;");
    return qm_entry(&opEntered_s);
}
//${SMs::Calc::SM::on::opEntered}
QM_ACTION_DEF(Calc, opEntered_x) {
    BSP_message("opEntered-EXIT;");
    return qm_exit(&opEntered_s);
}
//${SMs::Calc::SM::on::opEntered}
QM_STATE_DEF(Calc, opEntered) {
    QP::QState status_;
    switch (e->sig) {
        //${SMs::Calc::SM::on::opEntered::DIGIT_0}
        case DIGIT_0_SIG: {
            BSP_clear();

            static struct {
                QP::QMState const *target;
                QP::QActionHandler act[4];
            } const tatbl_ = { // tran-action table
                &operand_s, // target submachine
                {
                    &opEntered_x, // exit
                    &operand2_e, // entry
                    &operand_zero_ep, // EP
                    Q_ACTION_NULL // zero terminator
                }
            };
            status_ = qm_tran_ep(&tatbl_);
            break;
        }
        //${SMs::Calc::SM::on::opEntered::DIGIT_1_9}
        case DIGIT_1_9_SIG: {
            BSP_clear();
            BSP_insert(Q_EVT_CAST(CalcEvt)->key_code);

            static struct {
                QP::QMState const *target;
                QP::QActionHandler act[4];
            } const tatbl_ = { // tran-action table
                &operand_s, // target submachine
                {
                    &opEntered_x, // exit
                    &operand2_e, // entry
                    &operand_intgr_ep, // EP
                    Q_ACTION_NULL // zero terminator
                }
            };
            status_ = qm_tran_ep(&tatbl_);
            break;
        }
        //${SMs::Calc::SM::on::opEntered::POINT}
        case POINT_SIG: {
            BSP_clear();
            BSP_insert((int)'0');
            BSP_insert((int)'.');

            static struct {
                QP::QMState const *target;
                QP::QActionHandler act[4];
            } const tatbl_ = { // tran-action table
                &operand_s, // target submachine
                {
                    &opEntered_x, // exit
                    &operand2_e, // entry
                    &operand_frac_ep, // EP
                    Q_ACTION_NULL // zero terminator
                }
            };
            status_ = qm_tran_ep(&tatbl_);
            break;
        }
        //${SMs::Calc::SM::on::opEntered::OPER}
        case OPER_SIG: {
            //${SMs::Calc::SM::on::opEntered::OPER::[e->key=='-']}
            if (Q_EVT_CAST(CalcEvt)->key_code == KEY_MINUS) {

                static struct {
                    QP::QMState const *target;
                    QP::QActionHandler act[4];
                } const tatbl_ = { // tran-action table
                    &operand_s, // target submachine
                    {
                        &opEntered_x, // exit
                        &operand2_e, // entry
                        &operand_neg_ep, // EP
                        Q_ACTION_NULL // zero terminator
                    }
                };
                status_ = qm_tran_ep(&tatbl_);
            }
            //${SMs::Calc::SM::on::opEntered::OPER::[else]}
            else {
                status_ = Q_RET_HANDLED;
            }
            break;
        }
        default: {
            status_ = Q_RET_SUPER;
            break;
        }
    }
    return status_;
}

//${SMs::Calc::SM::on::operand2} .............................................
Calc::SM_operand const Calc::operand2_s = {
    {
        &Calc::on_s, // superstate
        &Calc::operand2,
        &Calc::operand2_e,
        Q_ACTION_NULL, // no exit action
        Q_ACTION_NULL  // no initial tran.
    },
    &Calc::operand2_CE
};
//${SMs::Calc::SM::on::operand2}
QM_ACTION_DEF(Calc, operand2_e) {
    sub_operand = &Calc::operand2_s; // attach submachine
    return operand_e(this); // enter submachine
}
//${SMs::Calc::SM::on::operand2}
QM_ACTION_DEF(Calc, operand2_CE) {
    BSP_message("operand2:XP-CE;");

    static struct {
        QP::QMState const *target;
        QP::QActionHandler act[3];
    } const tatbl_ = { // tran-action table
        &opEntered_s, // target state
        {
            &operand_x, // submachine exit
            &opEntered_e, // entry
            Q_ACTION_NULL // zero terminator
        }
    };
    return qm_tran(&tatbl_);
}
//${SMs::Calc::SM::on::operand2}
QM_STATE_DEF(Calc, operand2) {
    QP::QState status_;
    switch (e->sig) {
        //${SMs::Calc::SM::on::operand2::OPER}
        case OPER_SIG: {
            //${SMs::Calc::SM::on::operand2::OPER::[eval()]}
            if (eval(BSP_get_value(), Q_EVT_CAST(CalcEvt)->key_code)) {

                static struct {
                    QP::QMState const *target;
                    QP::QActionHandler act[2];
                } const tatbl_ = { // tran-action table
                    &opEntered_s, // target state
                    {
                        &opEntered_e, // entry
                        Q_ACTION_NULL // zero terminator
                    }
                };
                status_ = qm_tran(&tatbl_);
            }
            //${SMs::Calc::SM::on::operand2::OPER::[else]}
            else {

                static struct {
                    QP::QMState const *target;
                    QP::QActionHandler act[2];
                } const tatbl_ = { // tran-action table
                    &error_s, // target state
                    {
                        &error_e, // entry
                        Q_ACTION_NULL // zero terminator
                    }
                };
                status_ = qm_tran(&tatbl_);
            }
            break;
        }
        //${SMs::Calc::SM::on::operand2::EQUALS}
        case EQUALS_SIG: {
            //${SMs::Calc::SM::on::operand2::EQUALS::[eval()]}
            if (eval(BSP_get_value(), KEY_NULL)) {

                static struct {
                    QP::QMState const *target;
                    QP::QActionHandler act[3];
                } const tatbl_ = { // tran-action table
                    &result_s, // target state
                    {
                        &ready_e, // entry
                        &result_e, // entry
                        Q_ACTION_NULL // zero terminator
                    }
                };
                status_ = qm_tran(&tatbl_);
            }
            //${SMs::Calc::SM::on::operand2::EQUALS::[else]}
            else {

                static struct {
                    QP::QMState const *target;
                    QP::QActionHandler act[2];
                } const tatbl_ = { // tran-action table
                    &error_s, // target state
                    {
                        &error_e, // entry
                        Q_ACTION_NULL // zero terminator
                    }
                };
                status_ = qm_tran(&tatbl_);
            }
            break;
        }
        default: {
            status_ = Q_RET_SUPER;
            break;
        }
    }
    return status_;
}

//${SMs::Calc::SM::on::error} ................................................
QP::QMState const Calc::error_s = {
    &Calc::on_s, // superstate
    &Calc::error,
    &Calc::error_e,
    &Calc::error_x,
    Q_ACTION_NULL  // no initial tran.
};
//${SMs::Calc::SM::on::error}
QM_ACTION_DEF(Calc, error_e) {
    BSP_message("error-ENTRY;");
    return qm_entry(&error_s);
}
//${SMs::Calc::SM::on::error}
QM_ACTION_DEF(Calc, error_x) {
    BSP_message("error-EXIT;");
    return qm_exit(&error_s);
}
//${SMs::Calc::SM::on::error}
QM_STATE_DEF(Calc, error) {
    QP::QState status_;
    switch (e->sig) {
        default: {
            status_ = Q_RET_SUPER;
            break;
        }
    }
    return status_;
}

//${SMs::Calc::SM::final} ....................................................
QP::QMState const Calc::final_s = {
    QM_STATE_NULL, // superstate (top)
    &Calc::final,
    &Calc::final_e,
    Q_ACTION_NULL, // no exit action
    Q_ACTION_NULL  // no initial tran.
};
//${SMs::Calc::SM::final}
QM_ACTION_DEF(Calc, final_e) {
    BSP_message("final-ENTRY;");
    BSP_exit();
    return qm_entry(&final_s);
}
//${SMs::Calc::SM::final}
QM_STATE_DEF(Calc, final) {
    QP::QState status_;
    switch (e->sig) {
        default: {
            status_ = Q_RET_SUPER;
            break;
        }
    }
    return status_;
}

//${SMs::Calc::SM::operand} ..................................................
//${SMs::Calc::SM::operand}
QP::QMState const Calc::operand_s = {
    QM_STATE_NULL, // superstate unused
    &Calc::operand,
    &Calc::operand_e,
    &Calc::operand_x,
    &Calc::operand_i
};
//${SMs::Calc::SM::operand}
QM_ACTION_DEF(Calc, operand_e) {
    BSP_message("operand-ENTRY;");
    return qm_entry(&operand_s);
}
//${SMs::Calc::SM::operand}
QM_ACTION_DEF(Calc, operand_x) {
    BSP_message("operand-EXIT;");
    return qm_sm_exit(&sub_operand->super);
}
//${SMs::Calc::SM::operand::initial}
QM_ACTION_DEF(Calc, operand_i) {
    //${SMs::Calc::SM::operand::initial}
    BSP_message("operand-INIT;");

    static struct {
        QP::QMState const *target;
        QP::QActionHandler act[2];
    } const tatbl_ = { // tran-action table
        &operand_zero_s, // target state
        {
            &operand_zero_e, // entry
            Q_ACTION_NULL // zero terminator
        }
    };
    return qm_tran_init(&tatbl_);
}
//${SMs::Calc::SM::operand}
QM_STATE_DEF(Calc, operand) {
    QP::QState status_;
    switch (e->sig) {
        //${SMs::Calc::SM::operand::CE}
        case CE_SIG: {
            BSP_message("operand::CE;");
            BSP_clear();
            static QP::QMTranActTable const tatbl_ = { // tran-action table
                &operand_s, // target submachine
                {
                    Q_ACTION_NULL // zero terminator
                }
            };
            status_ = qm_tran_xp(sub_operand->CE, &tatbl_);
            break;
        }
        default: {
            status_ = qm_super_sub(&sub_operand->super);
            break;
        }
    }
    return status_;
}
//${SMs::Calc::SM::operand::EP-zero}
QM_ACTION_DEF(Calc, operand_zero_ep) {
    BSP_message("operand::EP-zero;");

    static struct {
        QP::QMState const *target;
        QP::QActionHandler act[2];
    } const tatbl_ = { // tran-action table
        &operand_zero_s, // target state
        {
            &operand_zero_e, // entry
            Q_ACTION_NULL // zero terminator
        }
    };
    return qm_tran_ep(&tatbl_);
}
//${SMs::Calc::SM::operand::EP-intgr}
QM_ACTION_DEF(Calc, operand_intgr_ep) {
    BSP_message("operand::EP-intgr;");

    static struct {
        QP::QMState const *target;
        QP::QActionHandler act[2];
    } const tatbl_ = { // tran-action table
        &operand_intgr_s, // target state
        {
            &operand_intgr_e, // entry
            Q_ACTION_NULL // zero terminator
        }
    };
    return qm_tran_ep(&tatbl_);
}
//${SMs::Calc::SM::operand::EP-frac}
QM_ACTION_DEF(Calc, operand_frac_ep) {
    BSP_message("operand::EP-frac;");

    static struct {
        QP::QMState const *target;
        QP::QActionHandler act[2];
    } const tatbl_ = { // tran-action table
        &operand_frac_s, // target state
        {
            &operand_frac_e, // entry
            Q_ACTION_NULL // zero terminator
        }
    };
    return qm_tran_ep(&tatbl_);
}
//${SMs::Calc::SM::operand::EP-neg}
QM_ACTION_DEF(Calc, operand_neg_ep) {
    BSP_message("operand::EP-neg;");

    static struct {
        QP::QMState const *target;
        QP::QActionHandler act[2];
    } const tatbl_ = { // tran-action table
        &operand_neg_s, // target state
        {
            &operand_neg_e, // entry
            Q_ACTION_NULL // zero terminator
        }
    };
    return qm_tran_ep(&tatbl_);
}

//${SMs::Calc::SM::operand::zero} ............................................
QP::QMState const Calc::operand_zero_s = {
    &Calc::operand_s, // superstate
    &Calc::operand_zero,
    &Calc::operand_zero_e,
    &Calc::operand_zero_x,
    Q_ACTION_NULL  // no initial tran.
};
//${SMs::Calc::SM::operand::zero}
QM_ACTION_DEF(Calc, operand_zero_e) {
    BSP_message("operand::zero-ENTRY;");
    return qm_entry(&operand_zero_s);
}
//${SMs::Calc::SM::operand::zero}
QM_ACTION_DEF(Calc, operand_zero_x) {
    BSP_message("operand::zero-EXIT;");
    return qm_exit(&operand_zero_s);
}
//${SMs::Calc::SM::operand::zero}
QM_STATE_DEF(Calc, operand_zero) {
    QP::QState status_;
    switch (e->sig) {
        //${SMs::Calc::SM::operand::zero::DIGIT_0}
        case DIGIT_0_SIG: {
            ;
            status_ = Q_RET_HANDLED;
            break;
        }
        //${SMs::Calc::SM::operand::zero::DIGIT_1_9}
        case DIGIT_1_9_SIG: {
            BSP_insert(Q_EVT_CAST(CalcEvt)->key_code);

            static struct {
                QP::QMState const *target;
                QP::QActionHandler act[3];
            } const tatbl_ = { // tran-action table
                &operand_intgr_s, // target state
                {
                    &operand_zero_x, // exit
                    &operand_intgr_e, // entry
                    Q_ACTION_NULL // zero terminator
                }
            };
            status_ = qm_tran(&tatbl_);
            break;
        }
        //${SMs::Calc::SM::operand::zero::POINT}
        case POINT_SIG: {
            BSP_insert((int)'0');
            BSP_insert((int)'.');

            static struct {
                QP::QMState const *target;
                QP::QActionHandler act[3];
            } const tatbl_ = { // tran-action table
                &operand_frac_s, // target state
                {
                    &operand_zero_x, // exit
                    &operand_frac_e, // entry
                    Q_ACTION_NULL // zero terminator
                }
            };
            status_ = qm_tran(&tatbl_);
            break;
        }
        default: {
            status_ = Q_RET_SUPER;
            break;
        }
    }
    return status_;
}

//${SMs::Calc::SM::operand::intgr} ...........................................
QP::QMState const Calc::operand_intgr_s = {
    &Calc::operand_s, // superstate
    &Calc::operand_intgr,
    &Calc::operand_intgr_e,
    &Calc::operand_intgr_x,
    Q_ACTION_NULL  // no initial tran.
};
//${SMs::Calc::SM::operand::intgr}
QM_ACTION_DEF(Calc, operand_intgr_e) {
    BSP_message("operand::intgr-ENTRY;");
    return qm_entry(&operand_intgr_s);
}
//${SMs::Calc::SM::operand::intgr}
QM_ACTION_DEF(Calc, operand_intgr_x) {
    BSP_message("operand::intgr-EXIT;");
    return qm_exit(&operand_intgr_s);
}
//${SMs::Calc::SM::operand::intgr}
QM_STATE_DEF(Calc, operand_intgr) {
    QP::QState status_;
    switch (e->sig) {
        //${SMs::Calc::SM::operand::intgr::POINT}
        case POINT_SIG: {
            BSP_insert((int)'.');

            static struct {
                QP::QMState const *target;
                QP::QActionHandler act[3];
            } const tatbl_ = { // tran-action table
                &operand_frac_s, // target state
                {
                    &operand_intgr_x, // exit
                    &operand_frac_e, // entry
                    Q_ACTION_NULL // zero terminator
                }
            };
            status_ = qm_tran(&tatbl_);
            break;
        }
        //${SMs::Calc::SM::operand::intgr::DIGIT_0, DIGIT_1_9}
        case DIGIT_0_SIG: // intentionally fall through
        case DIGIT_1_9_SIG: {
            BSP_insert(Q_EVT_CAST(CalcEvt)->key_code);
            status_ = Q_RET_HANDLED;
            break;
        }
        default: {
            status_ = Q_RET_SUPER;
            break;
        }
    }
    return status_;
}

//${SMs::Calc::SM::operand::frac} ............................................
QP::QMState const Calc::operand_frac_s = {
    &Calc::operand_s, // superstate
    &Calc::operand_frac,
    &Calc::operand_frac_e,
    &Calc::operand_frac_x,
    Q_ACTION_NULL  // no initial tran.
};
//${SMs::Calc::SM::operand::frac}
QM_ACTION_DEF(Calc, operand_frac_e) {
    BSP_message("operand::frac-ENTRY;");
    return qm_entry(&operand_frac_s);
}
//${SMs::Calc::SM::operand::frac}
QM_ACTION_DEF(Calc, operand_frac_x) {
    BSP_message("operand::frac-EXIT;");
    return qm_exit(&operand_frac_s);
}
//${SMs::Calc::SM::operand::frac}
QM_STATE_DEF(Calc, operand_frac) {
    QP::QState status_;
    switch (e->sig) {
        //${SMs::Calc::SM::operand::frac::POINT}
        case POINT_SIG: {
            ;
            status_ = Q_RET_HANDLED;
            break;
        }
        //${SMs::Calc::SM::operand::frac::DIGIT_0, DIGIT_1_9}
        case DIGIT_0_SIG: // intentionally fall through
        case DIGIT_1_9_SIG: {
            BSP_insert(Q_EVT_CAST(CalcEvt)->key_code);
            status_ = Q_RET_HANDLED;
            break;
        }
        default: {
            status_ = Q_RET_SUPER;
            break;
        }
    }
    return status_;
}

//${SMs::Calc::SM::operand::neg} .............................................
QP::QMState const Calc::operand_neg_s = {
    &Calc::operand_s, // superstate
    &Calc::operand_neg,
    &Calc::operand_neg_e,
    &Calc::operand_neg_x,
    Q_ACTION_NULL  // no initial tran.
};
//${SMs::Calc::SM::operand::neg}
QM_ACTION_DEF(Calc, operand_neg_e) {
    BSP_message("operand::neg-ENTRY;");
    BSP_negate();
    return qm_entry(&operand_neg_s);
}
//${SMs::Calc::SM::operand::neg}
QM_ACTION_DEF(Calc, operand_neg_x) {
    BSP_message("operand::neg-EXIT;");
    return qm_exit(&operand_neg_s);
}
//${SMs::Calc::SM::operand::neg}
QM_STATE_DEF(Calc, operand_neg) {
    QP::QState status_;
    switch (e->sig) {
        //${SMs::Calc::SM::operand::neg::DIGIT_0}
        case DIGIT_0_SIG: {
            BSP_insert(Q_EVT_CAST(CalcEvt)->key_code);

            static struct {
                QP::QMState const *target;
                QP::QActionHandler act[3];
            } const tatbl_ = { // tran-action table
                &operand_zero_s, // target state
                {
                    &operand_neg_x, // exit
                    &operand_zero_e, // entry
                    Q_ACTION_NULL // zero terminator
                }
            };
            status_ = qm_tran(&tatbl_);
            break;
        }
        //${SMs::Calc::SM::operand::neg::DIGIT_1_9}
        case DIGIT_1_9_SIG: {
            BSP_insert(Q_EVT_CAST(CalcEvt)->key_code);

            static struct {
                QP::QMState const *target;
                QP::QActionHandler act[3];
            } const tatbl_ = { // tran-action table
                &operand_intgr_s, // target state
                {
                    &operand_neg_x, // exit
                    &operand_intgr_e, // entry
                    Q_ACTION_NULL // zero terminator
                }
            };
            status_ = qm_tran(&tatbl_);
            break;
        }
        //${SMs::Calc::SM::operand::neg::POINT}
        case POINT_SIG: {
            BSP_insert(Q_EVT_CAST(CalcEvt)->key_code);

            static struct {
                QP::QMState const *target;
                QP::QActionHandler act[3];
            } const tatbl_ = { // tran-action table
                &operand_frac_s, // target state
                {
                    &operand_neg_x, // exit
                    &operand_frac_e, // entry
                    Q_ACTION_NULL // zero terminator
                }
            };
            status_ = qm_tran(&tatbl_);
            break;
        }
        //${SMs::Calc::SM::operand::neg::OPER}
        case OPER_SIG: {
            //${SMs::Calc::SM::operand::neg::OPER::[e->key=='-']}
            if (Q_EVT_CAST(CalcEvt)->key_code == KEY_MINUS) {
                ;
                status_ = Q_RET_HANDLED;
            }
            //${SMs::Calc::SM::operand::neg::OPER::[else]}
            else {
                status_ = Q_RET_HANDLED;
            }
            break;
        }
        default: {
            status_ = Q_RET_SUPER;
            break;
        }
    }
    return status_;
}
//$enddef${SMs::Calc} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^