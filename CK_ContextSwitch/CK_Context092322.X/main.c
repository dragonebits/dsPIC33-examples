/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.1
        Device            :  dsPIC33CK256MP505
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.70
        MPLAB 	          :  MPLAB X v5.50
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/pin_manager.h"


#ifndef FCY
#define FCY     (_XTAL_FREQ/2)
#endif

#include <libpic30.h> 



/*
                         Main application
 */

extern void PidCalculation(void);
extern void PidCalc2();

volatile register int result asm("A");
volatile register int B asm("B");

int x_memory_buffer[256]
__attribute__((space(xmemory)));
int y_memory_buffer[256]
__attribute__((space(ymemory)));
int *xmemory;
int *ymemory;
int awb;
int xVal, yVal;



void TMR1_CallBack(void)
{
    // Add your custom callback code here
    PidCalc2();     //normally don't pass argument to assembly function as we have no idea how the arguments would be placed before call routine.
                        //normally, argument would be put in W0 to W7. sometimes, it wold be in another registers for optimization purpose.
    TP30_Toggle();
}

void __attribute__((naked)) set_bank_data(void) //not work for optimization #0 which would use W14 registers for frame content storage
//void set_bank_data(void)
{   
   asm("CTXTSWP #1");
    xmemory = x_memory_buffer;
    ymemory = y_memory_buffer;
    result = __builtin_clr_prefetch(&xmemory, &xVal, 2, &ymemory, &yVal, 2, &awb, B);
    result = __builtin_mac(result, xVal, yVal,&xmemory, &xVal, 2, &ymemory, &yVal, 2, 0, B);
    asm("CTXTSWP #0");
}

int main(void)
{
    uint16_t tempvalue_z;
 
   
    
    // initialize the device
    SYSTEM_Initialize();
    __builtin_disable_interrupts();
    CORCONbits.IF = 0x01; //dsPIC in integer mode.
    CORCONbits.US = 0x01; //unsigned mode
    CORCONbits.RND = 0x01; //conventional rounding mode
    PR1 = 0x10;
    __builtin_enable_interrupts();
   // asm("CTXTSWP #1");
    for (tempvalue_z =0; tempvalue_z <256; tempvalue_z++){
        x_memory_buffer[tempvalue_z] = tempvalue_z;
        y_memory_buffer[tempvalue_z] = tempvalue_z;
    }
        
    set_bank_data();
    //asm("CTXTSWP #0");
 //   asm("CTXTSWP #1");
    PidCalculation();
   // asm("CTXTSWP #0");
    while (1)
    {
        // Add your application code
        __delay_us(200);
        TP31_Toggle();
      //  asm("CTXTSWP #1");
       // set_bank_data();
       // asm("CTXTSWP #0");
       // PidCalculation();
        __builtin_disable_interrupts();
        Nop();
        Nop();
        PidCalc2();     //need to disable interrupt as the Timer interrupt also call PidCalc()
        Nop();
        Nop();
        __builtin_enable_interrupts();
        Nop();
        Nop();
    }
    return 1; 
}
/**
 End of File
*/

