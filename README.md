# dsPIC33CK-examples
The first example uses two UARTs of dsPIC33CK256MP506 to demonstrate the AUTOBAUD feature of Two UARTs.
The UART1 would send break character to UART2 to initiate the AUTOBAUD process.
After the UART2 adapted the speed of UART1, the UART1 would change his baud rate after sending some characters.

Sometimes, the Autobaud feature is needed when there are photocouplers between both UARTs such as in SMPS primary side and secondary side.
The temperature drift also affect the baud rates of both sides.

The second example is manually switching the context/register banks. Normally, the specific register context would be selected accoding to IPL interrupt priority level automatically. This example show how to switch the context manually in the main loop for reference.   

The third example uses dsPIC33CH device in dual partition mode. It will copy a flash page from active partition to inactive partition with verification.

