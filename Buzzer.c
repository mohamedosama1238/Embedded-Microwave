#include "tm4c123gh6pm.h"
#include "DIO.h"	
#include "LED_TIMER.h"
#include "macros.h"
void Buzzer_Init(unsigned char port_name,unsigned char pin_number){
	port_uinit(port_name);
	DIO_vSET_PIN_DIR(port_name,pin_number,1);
}
void Buzzer_High_low ( unsigned char port_name, unsigned char pin_number)
{
	int i;
	for(i=0; i<=3; i++)
	{
		DIO_vWRITE_PIN (port_name,pin_number, 1); //BUZZER PIN IS LOGIC HIGH (BUZZER ON) 
		Delay(1000);
		DIO_vWRITE_PIN ( port_name, pin_number, 0); //BUZZER PIN IS LOGIC LOW (BUZZER OFF)
	}
}