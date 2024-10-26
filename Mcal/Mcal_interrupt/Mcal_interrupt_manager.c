/*
 * File:   Mcal_interrupt_manager.c
 * Author: s
 *
 * Created on 24 ??????, 2024, 02:36 ?
 */


#include "Mcal_interrupt_manager.h"


#if INTERRUPT_PRIORETY_LEVELS_ENABLE == INTERRUPT_ENABLE_FUTURE

void __interrupt() MCAL_InterruptManagerHigh(void) {

}

void __interrupt(low_priority) MCAL_InterruptManagerLow(void) {

}

#elif INTERRUPT_PRIORETY_LEVELS_ENABLE == INTERRUPT_DISABLE_FUTURE

void __interrupt() MCAL_InterruptManager(void) {
    if((MCAL_INTERRUPT_ENABLE == INTCONbits.INT0IE) && (MCAL_INTERRUPT_OCCUR == INTCONbits.INT0IF)) {
        INT0_ISR();
    }
    if((MCAL_INTERRUPT_ENABLE == INTCON3bits.INT1IE) && (MCAL_INTERRUPT_OCCUR == INTCON3bits.INT1IF)) {
        INT1_ISR();
    }
    if((MCAL_INTERRUPT_ENABLE == INTCON3bits.INT2IE) && (MCAL_INTERRUPT_OCCUR == INTCON3bits.INT2IF)) {
        INT2_ISR();
    }    
}

#endif