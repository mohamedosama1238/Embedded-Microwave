#include "tm4c123gh6pm.h"

void Button_Init(){ 
  SYSCTL_RCGCGPIO_R |= 0x00000020;     // 1) activate clock for Port F
  while ((SYSCTL_PRGPIO_R & 0x20) == 0)   // allow time for clock to start
  GPIO_PORTF_LOCK_R = 0x4C4F434B;   // 2) unlock GPIO Port F
  GPIO_PORTF_CR_R = 0x1F;           // allow changes to PF4-0
  // only PF0 needs to be unlocked, other bits can't be locked
  GPIO_PORTF_AMSEL_R = 0x00;        // 3) disable analog on PF
  GPIO_PORTF_PCTL_R = 0x00000000;   // 4) PCTL GPIO on PF4-0
  GPIO_PORTF_DIR_R = 0x0E;          // 5) PF4,PF0 in, PF3-1 out
  GPIO_PORTF_AFSEL_R = 0x00;        // 6) disable alt funct on PF7-0
  GPIO_PORTF_PUR_R = 0x11;          // enable pull-up on PF0 and PF4
  GPIO_PORTF_DEN_R = 0x1F;// 7) enable digital I/O on PF4-0
	GPIO_PORTF_DATA_R &= ~0x0E;	
}

unsigned char SW1(void){
return GPIO_PORTF_DATA_R & 0x01;
}
unsigned char SW2(void){
return GPIO_PORTF_DATA_R & 0x10;
}

void Button_extrnal_Init(){

SYSCTL_RCGCGPIO_R |= 0x08;
while ((SYSCTL_PRGPIO_R & 0x08) == 0)
GPIO_PORTD_LOCK_R = 0x4C4F434B;
GPIO_PORTD_CR_R |= 0xFF;
GPIO_PORTD_AMSEL_R &= 0x00;
GPIO_PORTD_PCTL_R &= 0x00000000;
GPIO_PORTD_AFSEL_R &= 0x00;
GPIO_PORTD_DIR_R &= 0xFE;
GPIO_PORTD_PUR_R |= 0x01;
GPIO_PORTD_DEN_R |= 0xFF;
}
unsigned char SW3(void){
return (GPIO_PORTD_DATA_R & 0x01);
}

