/*
 * File:   Main.c
 * Author: s
 *
 * Created on 16 ??????, 2024, 02:33 ?
 */
#include "Main.h"

uint16_t retLCD_Num[6];
uint16_t retValu1 = Zero_init;

int main(void) {
    
    MCAL_ADC_init(&adc1);
    MCAL_ADC_init(&adc2);
    MCAL_ADC_init(&adc3);
    MCAL_ADC_init(&adc4);
    HALL_LCD_4bit_init(&LCD1_4Bit);
    HALL_LCD_4bit_sendSTRPos(&LCD1_4Bit, RAW1, 1, "POT1: ");
    HALL_LCD_4bit_sendSTRPos(&LCD1_4Bit, RAW2, 1, "POT2: ");
    HALL_LCD_4bit_sendSTRPos(&LCD1_4Bit, RAW3, 1, "POT3: ");
    HALL_LCD_4bit_sendSTRPos(&LCD1_4Bit, RAW4, 1, "POT4: ");
    while(1) {
        
        MCAL_ADC_startConversion_Interrupt(&adc1, ADC_CHANAL_AN1);
        HALL_LCD_convertU16toSTR(retValu1,&retLCD_Num);
        HALL_LCD_4bit_sendSTRPos(&LCD1_4Bit, RAW1, 7, retLCD_Num);        
    }
    return 0;
}




/* External interrupt INTx ISR Functions Definetions */
void INT0_isr(void) {
    /* Code ISR INT0 */

}

void INT1_isr(void) {
    /* Code ISR INT1 */

}

void INT2_isr(void) {
    /* Code ISR INT2 */
    
}

/* External interrupt RBx ISR Functions Definetions */
void RB4_isr(void) {
    /* Code ISR RB4 */

}

void RB5_isr(void) {
    /* Code ISR RB5 */

}

void RB6_isr(void) {
    /* Code ISR RB6 */

}

void RB7_isr(void) {
    /* Code ISR RB7 */

}

/* Analog to Digital Converter ISR Functions Definetions */
void ADC_isr(void) {
    retValu1 = Zero_init;
    MCAL_ADC_getConversionResult(&adc1, &retValu1);
}