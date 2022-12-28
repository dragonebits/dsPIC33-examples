
/**
 * 
  Generated main.c file from MPLAB Code Configurator

  @Company,.,,
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.1
        Device            :  dsPIC33CH512MP506
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


#ifndef FCY
#define FCY     (_XTAL_FREQ/2)
#endif

#include <libpic30.h> 

/*
                         Main application
 */

uint16_t varWord1;
uint16_t varWord2;
uint16_t Keypressed = 0x0;

uint16_t ReadWord(uint32_t PROG_ADDR)
{
    int addrOffset;
    
    TBLPAG = ((PROG_ADDR & 0x7F0000)>>16);
    addrOffset = (PROG_ADDR & 0x00FFFE);
    
    varWord1 = __builtin_tblrdl(addrOffset);
    varWord2 = __builtin_tblrdh(addrOffset);
    return 0x0;
    
}


uint16_t Erase2Part(){
    int INTCON2Save;
    NVMCON = 0x4004; // Set WREN and word inactive partition erase mode
    INTCON2Save = INTCON2;
    //  __builtin_disable_interrupts; // Disable interrupts for NVM unlock sequence
    
    INTCON2bits.GIE = 0;
    
    __builtin_write_NVM(); // initiate write
    while(NVMCONbits.WR);
    INTCON2 = INTCON2Save;
    return 0x0;
    
}

uint16_t Two_WordWrite(uint16_t *writedata, uint32_t PROG_ADDR)
{

    
 
    int TargetWriteAddressL = PROG_ADDR&0xFFFE; // bits[15:0]
    int TargetWriteAddressH = PROG_ADDR>>16; // bits[22:16]
    int INTCON2Save;
    
    NVMCON = 0x4001; // Set WREN and word program mode
    TBLPAG = 0xFA; // write latch upper address //Fix address
//    addrOffset = (PROG_ADDR & 0x00FFFE); // ensure address is properly aligned
    NVMADRL = TargetWriteAddressL; // set target write address
    NVMADRH = TargetWriteAddressH;
    __builtin_tblwtl(0,*(writedata)); // load write latches
    __builtin_tblwth(0,*(writedata+1));
    __builtin_tblwtl(0x2,*(writedata+2));
    __builtin_tblwth(0x2,*(writedata+3));
    INTCON2Save = INTCON2;
    //__builtin_disable_interrupts; // Disable interrupts for NVM unlock sequence
        INTCON2bits.GIE = 0;
    __builtin_write_NVM(); // initiate write
    INTCON2 = INTCON2Save;
    //__builtin_enable_interrupts; // Disable interrupts for NVM unlock sequence
    while (NVMCONbits.WR);      //waiting for programming complete
    return 0x0;
    
}

uint16_t get256word(uint32_t base_PROG_ADDR, uint16_t *array){
        uint16_t tempvar0,tempvar1;
        uint32_t PROG_ADDR;
          
    for (tempvar0 = 0;tempvar0<0x80;tempvar0++){
        tempvar1 = tempvar0<<1;
        PROG_ADDR = base_PROG_ADDR + (tempvar1);
        ReadWord(PROG_ADDR);
        *(array+tempvar1) = varWord1;
        *(array+(tempvar1+1)) = varWord2;
    }
    return 0x0;    
}

uint16_t write256word(uint32_t base_PROG_ADDR, uint16_t *array){
    uint16_t tempvar0,tempvar1;
         
    for (tempvar0 = 0;tempvar0<0x40;tempvar0++){
        tempvar1 = tempvar0<<2;
        Two_WordWrite(array+tempvar1, base_PROG_ADDR+tempvar1);
    }
    return 0x0;    
}

int copyfailure = 0; //indicate the content verification is failure

uint16_t copytopartition2(uint32_t base_PROG_ADDR){
    int tempvara;
    uint16_t temp_array2[0x10F];
    uint16_t temp_array1[0x10F];
    Erase2Part();
    get256word(base_PROG_ADDR,temp_array1);
 //   for (tempvara=0;tempvara<0x100;tempvara++){
 //       temp_array2[tempvara] = temp_array1[tempvara];
 //   }
     write256word(base_PROG_ADDR+0x400000,temp_array1);
     get256word(base_PROG_ADDR+0x400000,temp_array2);
      for (tempvara=0;tempvara<0x100;tempvara++){
        if (temp_array2[tempvara] != temp_array1[tempvara]) copyfailure = 1;
    }
     
     
    return 0x0;
}

int main(void)
{
    uint32_t base_PROG_ADDR = 0x0200;
   // uint32_t base_PROG_ADDR = 0x02BF00; //config area
    // initialize the device
    SYSTEM_Initialize();
    //copytopartition2(base_PROG_ADDR);
    /*
    Erase2Part();
    get256bytes(base_PROG_ADDR);
    Two_WordWrite(configarray, 0x400000);
    Two_WordWrite(configarray+4, 0x400004);
    Two_WordWrite(configarray+8, 0x400008);
    Two_WordWrite(configarray+12, 0x4000012);
    */


    //Two_WordWrite();
   // Erase2Part();
    
    
    
    while (1)
    {
        Nop();
        Nop();
         INTCON2bits.GIE = 0;   //needed to disable interrupt that use same register LATC
         TP45_Toggle();
         INTCON2bits.GIE = 1;
         if (Keypressed)    {
             copytopartition2(base_PROG_ADDR);
             Keypressed = 0;
         } 
        // Add your application code
         Nop();
         Nop();
    }
    return 1; 
}


void TMR1_CallBack(void)
{
    // Add your custom callback code here
    if (copyfailure != 0) 
        _LATC11 = 0;
    else { if (_LATC11) _LATC11 = 0;
             else _LATC11 = 1;
    }
}


void TP27_CallBack(void)
{
    Nop();
    __delay_ms(20);       //debounce key press
     Keypressed = (!PORTBbits.RB13)? 0x1: 0x0;
  
    Nop();

}

/**
 End of File
*/

