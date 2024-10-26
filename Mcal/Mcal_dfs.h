/* 
 * File:   Mcal_dfs.h
 * Author: s
 *
 * Created on 26 ??????, 2024, 02:38 ?
 */

#ifndef MCAL_DFS_H
#define	MCAL_DFS_H

/* -------------------- Include Start -------------------- */
#include "Mcal_interrupt/Mcal_external_interrupt.h"
#include "Mcal_interrupt/Mcal_internal_interrupt.h"
#include "Mcal_interrupt/Mcal_interrupt_manager.h"
#include "Mcal_GPIO/Mcal_GPIO_init.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Global Variables Start -------------------- */
/* -------------------- Global Variables End  -------------------- */

/* -------------------- Standard Types Start -------------------- */
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
void INT0_isr(void);
void INT1_isr(void);
void INT2_isr(void);
/* -------------------- API End -------------------- */

/* -------------------- peripherals init Start -------------------- */
    /* External Interrupt */
Interrupt_INTx_t EX_INT0;
Interrupt_INTx_t EX_INT1;
Interrupt_INTx_t EX_INT2;
/* -------------------- peripherals init End -------------------- */

#endif	/* MCAL_DFS_H */

