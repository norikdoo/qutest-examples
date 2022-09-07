//$file${.::low_power.hpp} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
//
// Model: low-power.qm
// File:  ${.::low_power.hpp}
//
// This code has been generated by QM 5.2.0 <www.state-machine.com/qm>.
// DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
//
// SPDX-License-Identifier: GPL-3.0-or-later
//
// This generated code is open source software: you can redistribute it under
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
//$endhead${.::low_power.hpp} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#ifndef LOW_POWER_HPP
#define LOW_POWER_HPP

enum BlinkySignals {
    BTN_PRESSED_SIG = QP::Q_USER_SIG, // button SW1 was pressed
    MAX_PUB_SIG,          // the last published signal

    TIMEOUT0_SIG,         // timeout for Blinky0
    TIMEOUT1_SIG,         // timeout for Blinky1
    MAX_SIG               // the last signal
};

//$declare${AOs::AO_Blinky0} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

//${AOs::AO_Blinky0} .........................................................
extern QP::QActive * const AO_Blinky0;
//$enddecl${AOs::AO_Blinky0} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

#ifdef QXK_HPP // QXK kernel?

extern QP::QXThread XT_Blinky1;
extern QP::QXSemaphore XSEM_sw1;

#else // QV or QK kernels

//$declare${AOs::AO_Blinky1} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

//${AOs::AO_Blinky1} .........................................................
extern QP::QActive * const AO_Blinky1;
//$enddecl${AOs::AO_Blinky1} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

#endif

#endif // LOW_POWER_HPP
