# dsPIC33CK-examples
The first example uses two UARTs of dsPIC33CK256MP506 to demonstrate the AUTOBAUD feature of Two UARTs.
The UART1 would send break character to UART2 to initiate the AUTOBAUD process.
After the UART2 adapted the speed of UART1, the UART1 would change his baud rate after sending some characters.

Sometimes, the Autobaud feature is needed when there are photocouplers between both UARTs such as in SMPS primary side and secondary side.
The temperature drift also affect the baud rates of both sides.

The second example is manually switching the context/register banks. Normally, the specific register context would be selected accoding to IPL interrupt priority level automatically. This example show how to switch the context manually in the main loop for reference.   

The third example uses dsPIC33CH device in dual partition mode. It will copy a flash page from active partition to inactive partition with verification.

The forth example use DMA channels to move ADC0 and ADC1 average values to the PWM1 period and duty registers. The ADC interrupt triggers need to be enabled for DMA but the the overall ADC interrupts would be disabled by IEC bits.  The purpose of using DMA is to avoid reading the ADC result buffer randomly by user program. otherwise, the incorrect result may be reported.

The fifth example is using structure in Flash area and how to access specific address in Flash area.

The sixth example is dsPIC33CH switching between dual panels.

The seventh example is switching between dual panels of slave core PRAM of dsPIC33CH128MP506
