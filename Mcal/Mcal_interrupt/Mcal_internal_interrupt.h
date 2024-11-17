/* 
 * File:   Mcal_internal_interrupt.h
 * Author: s
 *
 * Created on 24 ??????, 2024, 02:34 ?
 */

#ifndef MCAL_INTERNAL_INTERRUPT_H
#define	MCAL_INTERNAL_INTERRUPT_H

/* -------------------- Include Start -------------------- */
#include "Mcal_interrupt_cfg.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
#if ADC_INTERRUPT_FUTUR == ADC_INTERRUPT_FUTUR_ENABLE
/* @brief : Macros Enable ADC interrupt */
#define Mcal_ADC_InterruptEnable(void)              (PIE1bits.ADIE = 1)
/* @brief : Macros Disable ADC interrupt */
#define Mcal_ADC_InterruptDisable(void)             (PIE1bits.ADIE = 0)
/* @brief : Macros Clear Flag ADC interrupt */
#define Mcal_ADC_ClearFlage(void)                   (PIR1bits.ADIF = 0)
/* @brief : Macros Set high priority ADC interrupt */
#define Mcal_ADC_HighPrioritySet(void)         (IPR1bits.ADIP = 1)
/* @brief : Macros Set low priority ADC interrupt */
#define Mcal_ADC_LowPrioritySet(void)          (IPR1bits.ADIP = 0)
#endif
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
/* -------------------- API End -------------------- */

#endif	/* MCAL_INTERNAL_INTERRUPT_H */

