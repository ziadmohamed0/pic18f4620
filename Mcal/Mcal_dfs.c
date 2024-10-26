/*
 * File:   Mcal_dfs.c
 * Author: s
 *
 * Created on 26 ??????, 2024, 02:37 ?
 */


#include "Mcal_dfs.h"

    /* External Interrupt */
Interrupt_INTx_t EX_INT0 = {
    .EX_InterruptHandler    = INT0_isr,
    .Edge                   = INTERRUPT_EDGE_RISING,
    .Priorety               = INTERRUPT_PRIORETY_HIGH,
    .Source                 = INTERRUPT_EXTERNAL_INT0,
    .MCU_Pin.Port           = GPIO_Port_Index_B, 
    .MCU_Pin.Pin            = GPIO_Pin_Index_0,
    .MCU_Pin.Direction      = GPIO_Dircetion_Input,
    .MCU_Pin.Status         = GPIO_Status_Low,
};

Interrupt_INTx_t EX_INT1 = {
    .EX_InterruptHandler    = INT1_isr,
    .Edge                   = INTERRUPT_EDGE_RISING,
    .Priorety               = INTERRUPT_PRIORETY_HIGH,
    .Source                 = INTERRUPT_EXTERNAL_INT1,
    .MCU_Pin.Port           = GPIO_Port_Index_B, 
    .MCU_Pin.Pin            = GPIO_Pin_Index_1,
    .MCU_Pin.Direction      = GPIO_Dircetion_Input,
    .MCU_Pin.Status         = GPIO_Status_Low,
};

Interrupt_INTx_t EX_INT2 = {
    .EX_InterruptHandler    = INT2_isr,
    .Edge                   = INTERRUPT_EDGE_RISING,
    .Priorety               = INTERRUPT_PRIORETY_HIGH,
    .Source                 = INTERRUPT_EXTERNAL_INT2,
    .MCU_Pin.Port           = GPIO_Port_Index_B, 
    .MCU_Pin.Pin            = GPIO_Pin_Index_2,
    .MCU_Pin.Direction      = GPIO_Dircetion_Input,
    .MCU_Pin.Status         = GPIO_Status_Low,
};
