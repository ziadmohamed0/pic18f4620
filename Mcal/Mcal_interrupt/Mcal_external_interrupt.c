/*
 * File:   Mcal_external_interrupt.c
 * Author: s
 *
 * Created on 24 ??????, 2024, 02:36 ?
 */


#include "Mcal_external_interrupt.h"

static Std_Return INTERRUPT_INTx_Enable(const Interrupt_INTx_t *copyINTx);
static Std_Return INTERRUPT_INTx_Disable(const Interrupt_INTx_t *copyINTx);
static Std_Return INTERRUPT_INTx_PrioretyInit(const Interrupt_INTx_t *copyINTx);
static Std_Return INTERRUPT_INTx_EdgInit(const Interrupt_INTx_t *copyINTx);
static Std_Return INTERRUPT_INTx_PinInit(const Interrupt_INTx_t *copyINTx);
static Std_Return INTERRUPT_INTx_ClearFlag(const Interrupt_INTx_t *copyINTx);

static Std_Return INTERRUPT_RBx_Enable(const Interrupt_RBx_t *copyINTx);
static Std_Return INTERRUPT_RBx_Disable(const Interrupt_RBx_t *copyINTx);
static Std_Return INTERRUPT_RBx_PrioretyInit(const Interrupt_RBx_t *copyINTx);
static Std_Return INTERRUPT_RBx_PinInit(const Interrupt_RBx_t *copyINTx);

Std_Return MCAL_INTERRUPT_INTx_init(const Interrupt_INTx_t *copyINTx) {
    uint8_t retValue = R_ERROR;
    if(copyINTx == NULL) {
        retValue = R_ERROR;
    }
    else {
        /* Disable External Interrupt */
        INTERRUPT_INTx_Disable(copyINTx);
        
        /* Clear Flag External Interrupt */
        INTERRUPT_INTx_ClearFlag(copyINTx);
        
        /* Configure Priority External Interrupt */
        INTERRUPT_INTx_PrioretyInit(copyINTx);
        
        /* Configure EDG State External Interrupt */
        INTERRUPT_INTx_EdgInit(copyINTx);
        
        /* Configure Pin I/O External Interrupt */
        INTERRUPT_INTx_PinInit(&copyINTx);
        
        /* Configure Default iInterrupt CallBack */
        
        /* Enable External Interrupt */
        INTERRUPT_INTx_Enable(copyINTx);
        retValue = R_OK;
    } 
    return retValue;
}
Std_Return MCAL_INTERRUPT_INTx_DeInit(const Interrupt_INTx_t *copyINTx) {
    uint8_t retValue = R_ERROR;
    if(copyINTx == NULL) {
        retValue = R_ERROR;
    }
    else {
        INTERRUPT_INTx_Disable(copyINTx);
        retValue = R_OK;
    }
    return retValue;    
}

Std_Return MCAL_INTERRUPT_RBx_init(const Interrupt_INTx_t *copyINTx) {
    uint8_t retValue = R_ERROR;
    if(copyINTx == NULL) {
        retValue = R_ERROR;
    }
    else {
        
        retValue = R_OK;
    }
    return retValue;    
}
Std_Return MCAL_INTERRUPT_RBx_DeInit(const Interrupt_INTx_t *copyINTx) {
    uint8_t retValue = R_ERROR;
    if(copyINTx == NULL) {
        retValue = R_ERROR;
    }
    else {
        
        retValue = R_OK;
    }
    return retValue;    
}


static Std_Return INTERRUPT_INTx_Enable(const Interrupt_INTx_t *copyINTx) {
    uint8_t retValue = R_ERROR;
    if(copyINTx == NULL) {
        retValue = R_ERROR;
    }
    else {
        switch(copyINTx->Source) {
            case INTERRUPT_EXTERNAL_INT0:
                MCAL_EX_INT0_InterruptEnable();
                retValue = R_OK;
                break;
            case INTERRUPT_EXTERNAL_INT1:
                MCAL_EX_INT1_InterruptEnable();
                retValue = R_OK;
                break;  
            case INTERRUPT_EXTERNAL_INT2:
                MCAL_EX_INT2_InterruptEnable();
                retValue = R_OK;
                break;
            default : 
                retValue = R_OK; 
                break;
        }
    }
    return retValue;        
}
static Std_Return INTERRUPT_INTx_Disable(const Interrupt_INTx_t *copyINTx) {
    uint8_t retValue = R_ERROR;
    if(copyINTx == NULL) {
        retValue = R_ERROR;
    }
    else {
        switch(copyINTx->Source) {
            case INTERRUPT_EXTERNAL_INT0:
                MCAL_EX_INT0_InterruptDisable();
                retValue = R_OK; 
                break;
            case INTERRUPT_EXTERNAL_INT1:
                MCAL_EX_INT1_InterruptDisable();
                retValue = R_OK; 
                break;
            case INTERRUPT_EXTERNAL_INT2:
                MCAL_EX_INT2_InterruptDisable();
                retValue = R_OK; 
                break; 
            default : 
                retValue = R_OK; 
                break;
        } 
    }
    return retValue;        
}

#if INTERRUPT_PRIORETY_LEVELS_ENABLE == INTERRUPT_ENABLE_FUTURE
static Std_Return INTERRUPT_INTx_PrioretyInit(const Interrupt_INTx_t *copyINTx) {
     uint8_t retValue = R_ERROR;
    if(copyINTx == NULL) {
        retValue = R_ERROR;
    }
    else {
        switch(copyINTx->Source) {
            case INTERRUPT_EXTERNAL_INT1:
                switch(copyINTx->Priorety) {
                    case INTERRUPT_PRIORETY_LOW:  MCAL_EX_INT1_LowPrioritySet();  break;
                    case INTERRUPT_PRIORETY_HIGH: MCAL_EX_INT1_HighPrioritySet(); break;
                    default: retValue = R_ERROR; break;
                }              
                retValue = R_OK;
                break;  
            case INTERRUPT_EXTERNAL_INT2:
                switch(copyINTx->Priorety) {
                    case INTERRUPT_PRIORETY_LOW:  MCAL_EX_INT2_LowPrioritySet();  break;
                    case INTERRUPT_PRIORETY_HIGH: MCAL_EX_INT2_HighPrioritySet(); break;
                    default: retValue = R_ERROR; break;
                }                 
                retValue = R_OK;
                break;
            default : 
                retValue = R_OK; 
                break;
        }        
        retValue = R_OK;
    }
    return retValue;       
}
#endif
static Std_Return INTERRUPT_INTx_EdgInit(const Interrupt_INTx_t *copyINTx) {
    uint8_t retValue = R_ERROR;
    if(copyINTx == NULL) {
        retValue = R_ERROR;
    }
    else {
        switch(copyINTx->Source) {
            case INTERRUPT_EXTERNAL_INT0:
                switch(copyINTx->Edge) {
                    case INTERRUPT_EDGE_RISING:  MCAL_EX_INT0_rissingSet();  break;
                    case INTERRUPT_EDGE_FALLING: MCAL_EX_INT0_fallingSet(); break;
                    default: retValue = R_ERROR; break;
                }              
                retValue = R_OK;
                break;              
            
            case INTERRUPT_EXTERNAL_INT1:
                switch(copyINTx->Edge) {
                    case INTERRUPT_EDGE_RISING:  MCAL_EX_INT1_rissingSet();  break;
                    case INTERRUPT_EDGE_FALLING: MCAL_EX_INT1_fallingSet(); break;
                    default: retValue = R_ERROR; break;
                }              
                retValue = R_OK;
                break;  
            case INTERRUPT_EXTERNAL_INT2:
                switch(copyINTx->Edge) {
                    case INTERRUPT_EDGE_RISING:  MCAL_EX_INT2_rissingSet();  break;
                    case INTERRUPT_EDGE_FALLING: MCAL_EX_INT2_fallingSet(); break;
                    default: retValue = R_ERROR; break;
                }                 
                retValue = R_OK;
                break;
            default : 
                retValue = R_OK; 
                break;
        }           
        retValue = R_OK;
    }
    return retValue;        
}
static Std_Return INTERRUPT_INTx_PinInit(const Interrupt_INTx_t *copyINTx) {
    uint8_t retValue = R_ERROR;
    if(copyINTx == NULL) {
        retValue = R_ERROR;
    }
    else {
        Mcal_GPIO_initPinDirection(&(copyINTx->MCU_Pin));
        retValue = R_OK;
    }
    return retValue;         
}
static Std_Return INTERRUPT_INTx_ClearFlag(const Interrupt_INTx_t *copyINTx) {
    uint8_t retValue = R_ERROR;
    if(copyINTx == NULL) {
        retValue = R_ERROR;
    }
    else {
        switch(copyINTx->Source) {
            case INTERRUPT_EXTERNAL_INT0:
                MCAL_EX_INT0_clearInterruptFlage();
                retValue = R_OK;
                break;
            case INTERRUPT_EXTERNAL_INT1:
                MCAL_EX_INT1_clearInterruptFlage();
                retValue = R_OK;
                break;  
            case INTERRUPT_EXTERNAL_INT2:
                MCAL_EX_INT2_clearInterruptFlage();
                retValue = R_OK;
                break;
            default : 
                retValue = R_OK; 
                break;
        }
        retValue = R_OK;
    }
    return retValue;    
}