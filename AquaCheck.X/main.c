/*
 * File:   main.c
 * Author: Juan
 *
 * Created on 1 de septiembre de 2015, 02:52 PM
 */


#pragma config FOSC = INTIO67
#pragma config PLLCFG = OFF          // Multiply the internal oscillator speed by 4
#pragma config PRICLKEN = OFF       // Primary clock enabled
#pragma config FCMEN = OFF          // Fail-Safe Clock Monitor enabled
#pragma config IESO = OFF           // Oscillator Switchover mode disabled
#pragma config PWRTEN = ON          // Power up timer enabled
#pragma config BOREN = ON          // Brown-out Reset disabled in hardware and software 
#pragma config BORV = 285           // VBOR set to 2.85 V nominal 
#pragma config WDTEN = ON         // WDT is controlled by SWDTEN bit of the WDTCON register
// #pragma config WDTPS = 32768            // Watchdog timer postscalar
#pragma config WDTPS = 8192            // Watchdog timer postscalar
#pragma config CCP2MX = PORTC1      // CCP2 input/output is multiplexed with RC1  
#pragma config PBADEN = OFF         // PORTB<5:0> pins are configured as digital I/O on Reset 
#pragma config CCP3MX = PORTB5      // P3A/CCP3 input/output is multiplexed with RB5  
#pragma config HFOFST = OFF         // HFINTOSC output and ready status are delayed by the oscillator stable status  
#pragma config T3CMX = PORTC0       // T3CKI is on RC0  
#pragma config P2BMX = PORTC0       // P2B is on RC0 
#pragma config MCLRE = EXTMCLR      // MCLR pin enabled, RE3 input pin disabled  
#pragma config STVREN = OFF         // Stack full/underflow will not cause Reset 
#pragma config LVP = OFF            // Single-Supply ICSP disabled 
#pragma config XINST = OFF          // Instruction set extension and Indexed Addressing mode disabled (Legacy mode) 
#pragma config DEBUG = OFF           // Block 0 (000800-003FFFh) code-protected 

//#include <plib/usart.h>

# ifndef 	MAXBUFFERSIZE
# define	MAXBUFFERSIZE	64
# endif

# define true   1
# define false  0

char Buffer[MAXBUFFERSIZE];

#include "comun.c"

void main(void) {

return;
}
