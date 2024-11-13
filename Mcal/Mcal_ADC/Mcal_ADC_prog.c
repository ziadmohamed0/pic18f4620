/*
 * File:   Mcal_ADC_prog.c
 * Author: s
 *
 * Created on November 11, 2024, 1:42 AM
 */


#include "Mcal_ADC_init.h"


static inline void ADC_input_chanal_configuration(const ADC_t * copyADC);
static inline void ADC_SelectResultFormat(const ADC_t * copyADC);
static inline void ADC_VolatgeReferance(const ADC_t * copyADC);

Std_Return MCAL_ADC_init(const ADC_t *copyADC) {
    uint8_t retValue = R_ERROR;
    if(copyADC == NULL) {
        
    }
    else {
        /* Disable the ADC */
        MCAL_ADC_CONVERSION_Disable();

        /* Configure The Acquisition time */
        ADCON2bits.ACQT = copyADC->AcquisitionClock;
        
        /* Configure The Conversion Clock */
        ADCON2bits.ADCS = copyADC->ConversionClock;
        
        /* Configure The Default Channel */
        ADCON0bits.CHS = copyADC->AdcChanall;
        ADC_input_chanal_configuration(copyADC);
        
        /* Configure The interrupt */
        
        /* Configure The result Format */
        ADC_SelectResultFormat(copyADC);
        
        /* Configure The voltage Reference */
        ADC_VolatgeReferance(copyADC);
        /* Enable ADC */

        retValue = R_OK;
    }
    return retValue;
}

Std_Return MCAL_ADC_Deinit(const ADC_t *copyADC) {
    uint8_t retValue = R_ERROR;
    if(copyADC == NULL) {
        
    }
    else {
        
        retValue = R_OK;
    }
    return retValue;    
}

Std_Return MCAL_ADC_SelectChanal(const ADC_t *copyADC, ADC_chanal_select_t copyChanal) {
    uint8_t retValue = R_ERROR;
    if(copyADC == NULL) {
        
    }
    else {
        
        retValue = R_OK;
    }
    return retValue;    
}

Std_Return MCAL_ADC_StartConversion(const ADC_t *copyADC) {
    uint8_t retValue = R_ERROR;
    if(copyADC == NULL) {
        
    }
    else {
        
        retValue = R_OK;
    }
    return retValue;    
}

Std_Return MCAL_ADC_isConversionDone(const ADC_t *copyADC, uint8_t *copyConversionStatus) {
    uint8_t retValue = R_ERROR;
    if((copyADC == NULL) && (copyConversionStatus ==NULL)) {
        
    }
    else {
        
        retValue = R_OK;
    }
    return retValue;    
}

Std_Return MCAL_ADC_getConversionResult(const ADC_t *copyADC, ADC_Resulte_t *copyConversionResult) {
    uint8_t retValue = R_ERROR;
    if((copyADC == NULL) && (copyConversionResult ==NULL)) {
        
    }
    else {
        
        retValue = R_OK;
    }
    return retValue;      
}

Std_Return MCAL_ADC_getConversion(const ADC_t *copyADC, ADC_chanal_select_t copyChanal, ADC_Resulte_t* copyConversionResult) {
    uint8_t retValue = R_ERROR;
    if((copyADC == NULL) && (copyConversionResult ==NULL)) {
        
    }
    else {
        
        retValue = R_OK;
    }
    return retValue;     
}

static inline void ADC_input_chanal_configuration(const ADC_t * copyADC) {    
    switch(copyADC->AdcChanall) {
        case ADC_CHANAL_AN1  : SET_BIT(TRISA, _TRISA_RA0_POSN); break;
        case ADC_CHANAL_AN2  : SET_BIT(TRISA, _TRISA_RA1_POSN); break;
        case ADC_CHANAL_AN3  : SET_BIT(TRISA, _TRISA_RA2_POSN); break;
        case ADC_CHANAL_AN4  : SET_BIT(TRISA, _TRISA_RA3_POSN); break;
        case ADC_CHANAL_AN5  : SET_BIT(TRISA, _TRISA_RA4_POSN); break;
        case ADC_CHANAL_AN6  : SET_BIT(TRISE, _TRISE_RE0_POSN); break;
        case ADC_CHANAL_AN7  : SET_BIT(TRISE, _TRISE_RE1_POSN); break;
        case ADC_CHANAL_AN8  : SET_BIT(TRISE, _TRISE_RE2_POSN); break;
        case ADC_CHANAL_AN9  : SET_BIT(TRISB, _TRISB_RB2_POSN); break;
        case ADC_CHANAL_AN10 : SET_BIT(TRISB, _TRISB_RB3_POSN); break;
        case ADC_CHANAL_AN11 : SET_BIT(TRISB, _TRISB_RB1_POSN); break;
        case ADC_CHANAL_AN12 : SET_BIT(TRISB, _TRISB_RB4_POSN); break;
        case ADC_CHANAL_AN13 : SET_BIT(TRISB, _TRISB_RB0_POSN); break;
    } 
}

static inline void ADC_SelectResultFormat(const ADC_t * copyADC) {
    switch(copyADC->ResultFormat) {
        case ADC_RESULT_FORMAT_RIGHT : MCAL_ADC_RESULT_RIGHT_FORMAT(); break;
        case ADC_RESULT_FORMAT_LEFT : MCAL_ADC_RESULT_LEFT_FORMAT(); break;
    }
}    

static inline void ADC_VolatgeReferance(const ADC_t * copyADC) { 
    switch(copyADC->VolatageRefrance) {
        case ADC_VOLTAGE_REF_ENABLE  : MCAL_ADC_VOLATGE_ENABLE(); break;
        case ADC_VOLTAGE_REF_DISABLE : MCAL_ADC_VOLATGE_DISABLE(); break;
    }
}