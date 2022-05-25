#include "tm4c123gh6pm.h"
#include "lED_TIMER.h"
void Buzzer_init()
{
	//buzzer connceted to pinE5
	SYSCTL_RCGCGPIO_R |= 0x10;
  while((SYSCTL_PRGPIO_R &= 0x10)==0);
	GPIO_PORTE_CR_R |= 0x20;
	GPIO_PORTE_AFSEL_R &= ~0x20;
	GPIO_PORTE_PCTL_R &=~ 0xf00000;
	GPIO_PORTE_AMSEL_R &=~0x20;
	GPIO_PORTE_DEN_R |= 0x20;
	GPIO_PORTE_DIR_R |= 0x20;
}
void blink()
{
		    
				GPIO_PORTF_DATA_R =GPIO_PORTF_DATA_R |= 0x0E;
				Delay(500);
				GPIO_PORTF_DATA_R =GPIO_PORTF_DATA_R &=~ 0x0E;
				
				
	}

void Buzzer()
{
	
		GPIO_PORTE_DATA_R |= 0x20;    //buzzer on 
		blink();
	  GPIO_PORTE_DATA_R &= ~0x20;   //buzzer off
	  
 }

void Buzzer_Blink()
{ 
							char y;
							
									for(y=0;y<3;y++)
									{
										Buzzer();
										Delay(500);
									}
								
	}
