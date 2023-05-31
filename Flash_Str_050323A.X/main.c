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


__prog__ unsigned int __attribute__((space(prog))) myPROGvar = 0x1234;
__prog__ unsigned int * myPROGpointer = &myPROGvar;

typedef struct mystruct __prog__ *treepointer;
typedef struct mystruct {
    const uint16_t num1;
    uint16_t num2;
    char myname[20];
    treepointer nextpointer;
} mytype1;

__prog__ mytype1 __attribute__((space(prog))) flash_structure = {
    .num1 = 0xabcd,
    .num2 = 0x5678,
    .myname[0] = 'J',
    .myname[1] = 'o',
    .myname[2] = 'h',
    .myname[3] = 'n'       
};

__prog__ mytype1 __attribute__((space(prog))) flash_structure_a;

__prog__ mytype1 __attribute__((space(prog), address(0x5000))) flash_structure_b = {
    .num1 = 0x1000,
    .num2 = 0x5678,
    .myname[0] = 'M',
    .myname[1] = 'a',
    .myname[2] = 'x',
    .nextpointer = &flash_structure_a        
};


__prog__ mytype1 __attribute__((space(prog), address(0x6000))) flash_structure_a = {
    .num1 = 0xabcd,
    .num2 = 0x5678,
    .myname[0] = 'A',
    .myname[1] = 'n',
    .myname[2] = 'n',
    .myname[3] = 'a',
    .nextpointer = &flash_structure_b        
};


__prog__ mytype1 * myPROGpointer2 = &flash_structure;
//__prog__ mytype1 * myPROGpointer3 =  flash_structure_a.nextpointer;

int flash_access(){
    int get_flash_var;
    get_flash_var = *myPROGpointer;
    return get_flash_var;
}
int main(void)
{
    unsigned int xxx;
    unsigned int yyy;
    unsigned int zzz;
     unsigned int aaa;
     uint16_t mytemp_a;
     unsigned char name[10] = {0,0,0,0,0,0,0,0,0,0};
     
     __prog__ mytype1 * myPROGpointer3;
     __prog__ void *myoffsetptr;
      __prog__ mytype1 * myPROGpointer4;

    
     myPROGpointer3 = flash_structure_a.nextpointer;
     myoffsetptr = &flash_structure_b;
     mytemp_a = flash_structure_b.num1;
     myoffsetptr = myoffsetptr + mytemp_a;
  //   myPROGpointer4 = myoffsetptr; 
     myPROGpointer4 = (__prog__ void * )&flash_structure_b + flash_structure_b.num1;
 //    myPROGpointer4 = (__prog__ void * )&flash_structure_b + 0x1000;
     
    Nop();
    Nop();
    xxx = flash_access();
    Nop();
    Nop();
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
    Nop();
    Nop();
    xxx = flash_access();
    yyy = myPROGvar;
    zzz = flash_structure.num1;
    aaa= myPROGpointer2->num2;
    name[0] = flash_structure.myname[0];
    name[1] = flash_structure.myname[1];
    *(name+2) = myPROGpointer2->myname[2];
    name[3] = flash_structure.myname[3];
    /*
    name[4] = myPROGpointer3->myname[0];
       name[5] = myPROGpointer3->myname[1];
      name[6] = myPROGpointer3->myname[2];  
    */
     name[4] = myPROGpointer4->myname[0];
       name[5] = myPROGpointer4->myname[1];
      name[6] = myPROGpointer4->myname[2];  
    
    Nop();
    Nop();
    
    
    
    
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

