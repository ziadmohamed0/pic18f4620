/*
 * File:   Main.c
 * Author: s
 *
 * Created on 16 ??????, 2024, 02:33 ?
 */
#include "Main.h"

uint8_t Num = 20 ; 
uint8_t NumArr[4];

void main(void) {
    HALL_LCD_8bit_init(&LCD1_8Bit);
    HALL_LCD_convertU8toSTR(Num, NumArr);
    HALL_LCD_8bit_sendSTR(&LCD1_8Bit, NumArr);
    while(1) {

    }
}
