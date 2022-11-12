# dsPIC33-examples
This example uses two UARTs of dsPIC33CK256MP506 to demonstrate the AUTOBAUD feature of Two UARTs.
The UART1 would send break character to UART2 to initiate the AUTOBAUD process.
After the UART2 adapted the speed of UART1, the UART1 would change his baud rate after sending some characters.

Sometimes, the Autobaud feature is needed when there are photocouplers between both UARTs such as in SMPS primary side and secondary side.
The temperature drift also affect the baud rates of both sides.
