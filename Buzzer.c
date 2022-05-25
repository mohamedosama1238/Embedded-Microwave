#include "tm4c123gh6pm.h"


	void Buzzer_Init(void)
{
    SYSCTL_RCGCGPIO_R |=0x1;
    while((SYSCTL_PRGPIO_R &0x1)==0);


    GPIO_PORTA_CR_R |=0x08;
    GPIO_PORTA_PCTL_R &=~0x0000F000;
    GPIO_PORTA_AMSEL_R&=~0x08;
    GPIO_PORTA_AFSEL_R &=~0x08;
    GPIO_PORTA_DEN_R |=0xFF;
    GPIO_PORTA_DIR_R |=0x08;
	

}
void buzzer_on(void)
{
    GPIO_PORTA_DATA_R |= 0x08;
}
void buzzer_off(void)
{
    GPIO_PORTA_DATA_R &= ~0x08;
}

