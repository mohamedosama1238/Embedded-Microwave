#include "tm4c123gh6pm.h"

void Button_Init(){ 
  SYSCTL_RCGCGPIO_R |= 0X20;
	while(!(SYSCTL_PRGPIO_R & 0X20)){};
	GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
	GPIO_PORTF_CR_R = 0X1F;

	GPIO_PORTF_DEN_R |= 0X1F;
	GPIO_PORTF_AFSEL_R &= 0XE0;
	GPIO_PORTF_PCTL_R &= 0X00000;
	GPIO_PORTF_AMSEL_R &= 0XE0;
	GPIO_PORTF_DIR_R |= 0X0E;
	GPIO_PORTF_PUR_R |= 0x11;
	GPIO_PORTF_DATA_R &= 0XF1;
}

unsigned char SW1(void){
return GPIO_PORTF_DATA_R & 0x01;
}
unsigned char SW2(void){
return GPIO_PORTF_DATA_R & 0x10;
}

void Button_extrnal_Init(){

SYSCTL_RCGCGPIO_R |= 0x01;
while ((SYSCTL_PRGPIO_R & 0x01) == 0)
GPIO_PORTA_LOCK_R = 0x4C4F434B;
GPIO_PORTA_CR_R |= 0x04;
GPIO_PORTA_AMSEL_R &= ~0x04;
GPIO_PORTA_PCTL_R &= 0x00000F00;
GPIO_PORTA_AFSEL_R &= 0xFB;
GPIO_PORTA_DIR_R &= 0xFB;
GPIO_PORTA_PUR_R |= 0x04;
GPIO_PORTA_DEN_R |= 0x04;
}
unsigned char SW3(void){
return (GPIO_PORTA_DATA_R & 0x04);
}
