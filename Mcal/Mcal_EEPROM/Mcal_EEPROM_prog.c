/*
 * File:   Mcal_EEPROM_prog.c
 * Author: s
 *
 * Created on November 6, 2024, 3:01 AM
 */


#include "Mcal_EEPROM_init.h"

Std_Return MCAL_EEPROM_DataWriteByte(uint16_t copybAdd, uint8_t copybData) {
    uint8_t retValue = R_OK;
    /* Read the interrupt Status "Enabled or Disabled" */
    uint8_t Globale_interrupt_Status = INTCONbits.GIE;
    /* Update the address register */
    EEADRH = ((uint8_t)((copybAdd >> 8) & 0x03));
    EEADR = ((uint8_t)(copybAdd & 0xFF));
    /* Update the Data register */
    EEDATA = copybData;
    /* Select access data EEPROM memory */
    /* Allows write cycles to Flash program/data EEPROM */
    /* Disable all interrupt "General Interrupt" */
    /* Write the required sequence : 0x55 -> 0xAA */
    /* Inhibits a data EEPROM erase/Write cycle */
    /* Wait for write to complete */
    /* Inhibits write to Flash program/data EEPROM */
    /* restore the interrupt status "Enabled or Disabled" */
    return retValue;
}
Std_Return MCAL_EEPROM_DataReadByte(uint16_t copybAdd, uint8_t *copybData) {
    uint8_t retValue = R_ERROR;
    if(copybData == NULL) {
        
    }
    else {
        
        retValue = R_OK;
    }
    return retValue;    
}