#define FCY 16000000UL 
#include <assert.h>
#include <stdbool.h>
#include "mcc_generated_files/system.h"
#include <stdio.h>
#include <stdlib.h>
#include <libpic30.h>
#include <xc.h>
#include <string.h>
#include "mcc_generated_files/i2c1.h"
#include "lps33hw.h"

#if defined(__dsPIC33E__)
	#include <p33exxxx.h>
#elif defined(__dsPIC33F__)
	#include <p33fxxxx.h>
#elif defined(__dsPIC30F__)
	#include <p30fxxxx.h>
#elif defined(__PIC24E__)
	#include <p24exxxx.h>
#elif defined(__PIC24H__)
	#include <p24hxxxx.h>
#elif defined(__PIC24F__) || defined(__PIC24FK__)
	#include <p24fxxxx.h>
#endif

float temperatur;                                   // definiert "temperatur"
float luftdruck;                                    // defienert "luftdruck"
    
/*
                         Main application
 */
int main(void){                                     // "main"
    SYSTEM_Initialize();                            // ruft "SYSTEM_Initialize" auf
    //LPS33HW_Init();
    __delay_ms(500);                                // warte 500ms
    
    while (1){                                      // Endloschleife
        temperatur = LPS33HW_temp_GetValue();       // schreibt ergebnis von "LPS33HW_temp_GetValue" in "temperatur"
        luftdruck = LPS33HW_press_GetValue();       // schreibt ergebnis von "LPS33HW_press_GetValue" in "luftdruck"
        printf("Temperatur = %.2fC   ",temperatur); // schreibt "Temperatur = %.2fC\r\n" an UART  
        printf("Luftdruck = %4.2fhPa\r\n",luftdruck);// schreibt "Luftdruck = %fhPa\r\n" an UART  
        __delay_ms(500);                            // warte 500ms
    }                                               // 
}                                                   // 

