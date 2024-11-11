/* 
 * File:   Mcal_ADC_init.h
 * Author: s
 *
 * Created on November 11, 2024, 1:42 AM
 */

#ifndef MCAL_ADC_INIT_H
#define	MCAL_ADC_INIT_H

/* -------------------- Include Start -------------------- */
#include "../Mcal_interrupt/Mcal_internal_interrupt.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
#define ADC_AN0_ANALOG_FUNCTIONALITY                        0x0E
#define ADC_AN1_ANALOG_FUNCTIONALITY                        0x0D
#define ADC_AN2_ANALOG_FUNCTIONALITY                        0x0C
#define ADC_AN3_ANALOG_FUNCTIONALITY                        0x0B
#define ADC_AN4_ANALOG_FUNCTIONALITY                        0x0A
#define ADC_AN5_ANALOG_FUNCTIONALITY                        0x09
#define ADC_AN6_ANALOG_FUNCTIONALITY                        0x08
#define ADC_AN7_ANALOG_FUNCTIONALITY                        0x07
#define ADC_AN8_ANALOG_FUNCTIONALITY                        0x06
#define ADC_AN9_ANALOG_FUNCTIONALITY                        0x05
#define ADC_AN10_ANALOG_FUNCTIONALITY                       0x04
#define ADC_AN11_ANALOG_FUNCTIONALITY                       0x03
#define ADC_AN12_ANALOG_FUNCTIONALITY                       0x02
#define ADC_ALL_ANALOG_FUNCTIONALITY                        0x01
#define ADC_ALL_DIGITAL_FUNCTIONALITY                       0x0F
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
#define MCAL_ADC_CONVERSION_STATUS(void)                    (ADCON0bits.GO_nDONE)

#define MCAL_ADC_VOLATGE_ENABLE(void)                       do{ADCON1bits.VCFG1 = 1;\
                                                                ADCON1bits.VCFG0 = 1;\
                                                            }while(0)

#define MCAL_ADC_VOLATGE_DISABLE(void)                      do{ADCON1bits.VCFG1 = 0;\
                                                                ADCON1bits.VCFG0 = 0;\
                                                            }while(0)

/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
typedef enum {
    ADC_CHANAL_AN1 = 0,
    ADC_CHANAL_AN2,
    ADC_CHANAL_AN3,
    ADC_CHANAL_AN4,
    ADC_CHANAL_AN5,
    ADC_CHANAL_AN6,
    ADC_CHANAL_AN7,
    ADC_CHANAL_AN8,
    ADC_CHANAL_AN9,
    ADC_CHANAL_AN10,
    ADC_CHANAL_AN11,
    ADC_CHANAL_AN12,
    ADC_CHANAL_AN13,
}ADC_chanal_select_t;
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
/* -------------------- API End -------------------- */

#endif	/* MCAL_ADC_INIT_H */

