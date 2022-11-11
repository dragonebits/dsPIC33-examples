# dsPIC33-examples
This example use two UART of dsPIC33CK256MP506 to demonstrate the AUTOBAUD feature of UARTs.
The UART1 would send break character to UART2 to initiate the AUTOBAUD process.
After the UART2 adapted the speed of UART1, the UART1 would change his baud rate after sending some characters.
