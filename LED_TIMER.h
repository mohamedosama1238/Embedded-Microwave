#include "Io.h"
#include "DIO.h"
#include "tm4c123gh6pm.h"

#define NVIC_ST_CURRENT_R (*((volatile unsigned long *)0xE000E018))
#define NVIC_ST_CTRL_R (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R (*((volatile unsigned long *)0xE000E014))
void LED_vInit(unsigned char port_name,unsigned char pin_number);
void SysTick_wait(unsigned long d);
void Delay(unsigned int time);
void Led_On();
void Led_Off();
void Led_Blink();
void Led_Flash();


