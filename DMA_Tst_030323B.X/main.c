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
        Device            :  dsPIC33CK64MP206
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
#include "mcc_generated_files/interrupt_manager.h"

/*
                         Main application
 */
uint16_t dma_variable __attribute__((address(0x2000)));
uint16_t dma_variable2 __attribute__((address(0x2002)));

int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    //Workaround for MCC
     // HALFIF disabled; LOWIF disabled; HALFEN disabled; DONEIF disabled; OVRUNIF disabled; CHSEL AD1FLTR2 - Oversample Filter 1; HIGHIF disabled; 
    DMAINT0= 0x4100;
    //Workaround for MCC
     // HALFIF disabled; LOWIF disabled; HALFEN disabled; DONEIF disabled; OVRUNIF disabled; CHSEL AD1FLTR2 - Oversample Filter 1; HIGHIF disabled; 
    DMAINT1= 0x4000;
       //disable channel_AN0 interrupt.
    IEC5bits.ADCAN0IE = 0;
    
     //disable channel_AN1 interrupt.
    IEC5bits.ADCAN0IE = 0;
    
    IEC7bits.ADFLTR0IE = 0;
    
    while (1)
    {
        // Add your application code
        Nop();
        Nop();
     //   PG1DC = dma_variable>>2;
        Nop();
        Nop();
        
    }
    return 1; 
}

void ADC1_channel_AN0_CallBack( uint16_t adcVal )
{ 
    Nop();
    Nop();
  // PG1DC = adcVal>>2 ;
    Nop();
    Nop();
            

}


void ADC1_channel_AN1_CallBack( uint16_t adcVal )
{ 
Nop();
    Nop();
 //  PG1PER = adcVal ;
    Nop();
    Nop();
}


void DMA_Channel0_CallBack(void)
{
    // Add your custom callback code here
    Nop();
    Nop();
    Nop();
    Nop();
}

void DMA_Channel1_CallBack(void)
{
    // Add your custom callback code here
    Nop();
    Nop();
    Nop();
    Nop();
}


void __attribute__ ( ( __interrupt__ , auto_psv, weak ) ) _ADFLTR0Interrupt( void )
{
    uint16_t valchannel_AN0;
    //Read the ADC value from the ADCBUF
    valchannel_AN0 = ADFL0DAT;
    Nop();
    Nop();
    Nop();
    Nop();

    //clear the oversampling interrupt flag
    IFS7bits.ADFLTR0IF = 0;
}

/**
 End of File
*/

