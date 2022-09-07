/*============================================================================
* QP/C Real-Time Embedded Framework (RTEF)
* Copyright (C) 2005 Quantum Leaps, LLC. All rights reserved.
*
* SPDX-License-Identifier: GPL-3.0-or-later OR LicenseRef-QL-commercial
*
* This software is dual-licensed under the terms of the open source GNU
* General Public License version 3 (or any later version), or alternatively,
* under the terms of one of the closed source Quantum Leaps commercial
* licenses.
*
* The terms of the open source GNU General Public License version 3
* can be found at: <www.gnu.org/licenses/gpl-3.0>
*
* The terms of the closed source Quantum Leaps commercial licenses
* can be found at: <www.state-machine.com/licensing>
*
* Redistributions in source code must retain this top-level comment block.
* Plagiarizing this software to sidestep the license obligations is illegal.
*
* Contact information:
* <www.state-machine.com>
* <info@state-machine.com>
============================================================================*/
/*!
* @date Last updated on: 2021-12-23
* @version Last updated for version: 7.0.0
*
* @file
* @brief Back-End connection point for the external Front-Ends
* @ingroup qpspy
*/
#ifndef be_h
#define be_h

#ifdef __cplusplus
extern "C" {
#endif

void BE_parse(unsigned char *buf, uint32_t nBytes);
void BE_parseRecFromFE    (QSpyRecord * const qrec);
int  BE_parseRecFromTarget(QSpyRecord * const qrec); /*see QSPY_CustParseFun*/

void BE_onStartup(void);
void BE_onCleanup(void);
void BE_sendLine(void);     /* send the QSPY parsed line to the Front-End */

#ifdef __cplusplus
}
#endif

#endif /* be_h */
