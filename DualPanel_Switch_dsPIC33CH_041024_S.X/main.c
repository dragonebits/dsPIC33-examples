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
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.4
        Device            :  dsPIC33CH512MP506
    The generated drivers are tested against the following:
        Compiler          :  XC16 v2.10
        MPLAB 	          :  MPLAB X v6.05
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

#include "mcc_generated_files/system.h"
#define FCY 90000000UL              // Define instruction clock rate for delay routine //should be here!
#include <libpic30.h>               //For delay function definition

#define MACRO_PARTITIONSWAP() __asm__ volatile(" bclr INTCON2, #15 \n"  \
                                               " nop    \n"             \
                                               " nop    \n"             \
                                               " clr W0 \n"             \
                                               " mov #0x0055, W1 \n"    \
                                               " mov W1, NVMKEY  \n"    \
                                               " mov #0x00AA, W1 \n"    \
                                               " mov W1, NVMKEY  \n"    \
                                               " bootswp  \n"           \
                                               " call W0"  : : : "w0", "w1", "memory", "cc")  

/*
                         Main application
 */
void chk_key_input();

int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    while (1)
    {
        // Add your application code
        __builtin_btg(&LATD,2);

         __delay_us(1);

        chk_key_input();
    }
    return 1; 
}

void chk_key_input(){
    if (_RB13==0){ //key input for swap partition
        __delay_ms(500); //wait until key debounce finsihed 
        while (_RB13==0); //waiting for release
        __delay_ms(500); //wait until key debounce finsihed 
        MACRO_PARTITIONSWAP();
        Nop();
        Nop();
    }
}    
/**
 End of File
*/

