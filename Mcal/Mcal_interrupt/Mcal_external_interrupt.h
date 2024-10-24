/* 
 * File:   Mcal_external_interrupt.h
 * Author: s
 *
 * Created on 24 ??????, 2024, 02:34 ?
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define	MCAL_EXTERNAL_INTERRUPT_H

/* -------------------- Include Start -------------------- */
#include "Mcal_interrupt_cfg.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
#if EXTERNAL_INTERRUPT_INTx_ENABLE_FUTURE == INTERRUPT_ENABLE_FUTURE

        /* @groupMacros : INT0 interrupt */
/* @brief : Macros Enable External interrupt 0 */
#define MCAL_EX_INT0_InterruptEnable(void)                      (INTCONbits_t.INT0IE = 1)

/* @brief : Macros Disable External interrupt 0 */
#define MCAL_EX_INT0_InterruptDisable(void)                     (INTCONbits_t.INT0IE = 0)

/* @brief : Macros Clear Flag External interrupt 0 */
#define MCAL_EX_INT0_clearInterruptFlage(void)                  (INTCONbits_t.INT0IF = 0)

/* @brief : Macros Set Rising Age External interrupt 0 */
#define MCAL_EX_INT0_rissingSet(void)                           (INTCON2bits_t.INTEDG0 = 1)

/* @brief : Macros Set Falling Age External interrupt 0 */
#define MCAL_EX_INT0_fallingSet(void)                           (INTCON2bits_t.INTEDG0 = 0)


        /* @groupMacros : INT0 interrupt */
/* @brief : Macros Enable External interrupt 1 */
#define MCAL_EX_INT1_InterruptEnable(void)                      (INTCON3bits_t.INT1IE = 1)

/* @brief : Macros Disable External interrupt 1 */
#define MCAL_EX_INT1_InterruptDisable(void)                     (INTCON3bits_t.INT1IE = 0)

/* @brief : Macros Clear Flag External interrupt 1 */
#define MCAL_EX_INT1_clearInterruptFlage(void)                  (INTCON3bits_t.INT1IF = 0)

/* @brief : Macros Set Rising Age External interrupt 1 */
#define MCAL_EX_INT1_rissingSet(void)                           (INTCON2bits_t.INTEDG1 = 1)

/* @brief : Macros Set Falling Age External interrupt 1 */
#define MCAL_EX_INT1_fallingSet(void)                           (INTCON2bits_t.INTEDG1 = 0)


        /* @groupMacros : INT2 interrupt */
/* @brief : Macros Enable External interrupt 2 */
#define MCAL_EX_INT2_InterruptEnable(void)                      (INTCON3bits_t.INT2IE = 1)

/* @brief : Macros Disable External interrupt 2 */
#define MCAL_EX_INT2_InterruptDisable(void)                     (INTCON3bits_t.INT2IE = 0)

/* @brief : Macros Clear Flag External interrupt 2 */
#define MCAL_EX_INT2_clearInterruptFlage(void)                  (INTCON3bits_t.INT2IF = 0)

/* @brief : Macros Set Rising Age External interrupt 2 */
#define MCAL_EX_INT2_rissingSet(void)                           (INTCON2bits_t.INTEDG2 = 1)

/* @brief : Macros Set Falling Age External interrupt 2 */
#define MCAL_EX_INT2_fallingSet(void)                           (INTCON2bits_t.INTEDG2 = 0)

#if INTERRUPT_PRIORETY_LEVELS_ENABLE == INTERRUPT_ENABLE_FUTURE

/* @brief : Macros Set high priority External interrupt 1 */
#define MCAL_EX_INT1_HighPrioritySet(void)                      (INTCON3bits_t.INT1IP = 1)

/* @brief : Macros Set low priority External interrupt 1 */
#define MCAL_EX_INT1_LowPrioritySet(void)                       (INTCON3bits_t.INT1IP = 0)

/* @brief : Macros Set high priority External interrupt 2 */
#define MCAL_EX_INT2_HighPrioritySet(void)                      (INTCON3bits_t.INT2IP = 1)
/* @brief : Macros Set low priority External interrupt 2 */
#define MCAL_EX_INT2_LowPrioritySet(void)                       (INTCON3bits_t.INT2IP = 0)
#endif

#endif

#if EXTERNAL_INTERRUPT_OnChange_ENABLE_FUTURE == INTERRUPT_ENABLE_FUTURE

/* @brief : Macros Enable External interrupt Port B */
#define MCAL_RBx_InterruptEnable(void)                          (INTCONbits_t.RBIE = 1)

/* @brief : Macros Disable External interrupt Port B */
#define MCAL_RBx_InterruptDisable(void)                         (INTCONbits_t.RBIE = 0)

/* @brief : Macros Clear Flag External interrupt Port B */
#define MCAL_RBx_clearInterruptFlage(void)                      (INTCONbits_t.RBIF = 0)

#if INTERRUPT_PRIORETY_LEVELS_ENABLE == INTERRUPT_ENABLE_FUTURE

/* @brief : Macros Set high priority External interrupt Port B */
#define MCAL_EX_RBx_HighPrioritySet(void)                      (INTCON2bits_t.RBIP = 1)
/* @brief : Macros Set low priority External interrupt Port B */
#define MCAL_EX_RBx_LowPrioritySet(void)                       (INTCON2bits_t.RBIP  = 0)

#endif

#endif 
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
typedef struct {
    
}Interrupt_INTx_t;

typedef struct {
    
}Interrupt_RBx_t;
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
Std_Return MCAL_INTERRUPT_INTx_init(const Interrupt_INTx_t *copyINTx);
Std_Return MCAL_INTERRUPT_INTx_DeInit(const Interrupt_INTx_t *copyINTx);

Std_Return MCAL_INTERRUPT_RBx_init(const Interrupt_INTx_t *copyINTx);
Std_Return MCAL_INTERRUPT_RBx_DeInit(const Interrupt_INTx_t *copyINTx);

/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
/* -------------------- API End -------------------- */

#endif	/* MCAL_EXTERNAL_INTERRUPT_H */

