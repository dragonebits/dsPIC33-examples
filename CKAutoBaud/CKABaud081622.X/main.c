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
        Device            :  dsPIC33CK256MP506
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
#include "mcc_generated_files/tmr1.h"
#include "mcc_generated_files/uart1.h"
#include "mcc_generated_files/uart2.h"
#ifndef FCY
#define FCY     (_XTAL_FREQ/2)
#endif

#include <libpic30.h> 

void send_break(uint16_t);
/*
                         Main application
 */
int main(void)
{


    // initialize the device
    SYSTEM_Initialize();
    U2MODEbits.RXBIMD = 1;  //break character would set after 11 low before TX rising up
 //   U2MODEbits.RXBIMD = 0;  //break character would set after 11 low after TX rising up
    while (1)
    {
        // Add your application code
        TP45_SetHigh();
    //    __delay_us(500); //for testing
        TP45_SetLow();
    //    U1MODEbits.UTXBRK = 1;  //send AUTO break
        while (!U1STAbits.TRMT); //wait for buffer is empty
        send_break(112);            //send manual break
        UART1_Write(0x55);       //Send break and 0x0
    //     __delay_us(500); //for testing
        while (U2MODEbits.ABAUD==1){
            _LATC12 = U2MODEbits.ABAUD;
        };
        _LATC12 = U2MODEbits.ABAUD;
     //   U2MODEbits.UARTEN = 0;
     //   U2MODEbits.UARTEN = 1;
        
        while (U1MODEbits.UTXBRK);  //waiting for break complete (not use TRMT because of errata)
        UART1_Write(0x50);   
        UART1_Write(0x61);   
        UART1_Write(0x75);   
        UART1_Write(0x6C);   
        while (!U1STAbits.TRMT); //wait for buffer is empty
        U1MODEbits.UARTEN = 0;// switch off before clock change
        if (U1BRG != 0x1B1) U1BRG = 0x1B1;
        else U1BRG = 0xD8;
        U1MODEbits.UARTEN = 1;
  //       __delay_ms(1); //for testing
         UART1_Write(0x66);  
    }
    return 1; 
}

void UART2_Receive_CallBack(void)
{
    uint16_t temp;
    Nop();
    Nop();
    TP47_SetHigh();
    TP47_SetLow();
    if ((U1STAbits.OERR == 1))
    {
        U1STAbits.OERR = 0;
    }
    
    temp = U1RXREG;
    Nop();
    Nop();
}

void send_break(uint16_t usec){
    U1MODEbits.BRKOVR = 1;
  //  U1MODEHbits.UTXINV = 1;
    __delay_us(usec);
  //  U1MODEHbits.UTXINV = 0;
    U1MODEbits.BRKOVR = 0;
    __delay_us(10);
}
/**
 End of File
*/

