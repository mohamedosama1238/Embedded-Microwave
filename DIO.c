#include "Io.h"
#include "tm4c123gh6pm.h"

/*
 #define set_bit (unsigned char reg,unsigned char bit) reg|=(1<<bit)
 #define clr_bit (unsigned char reg,unsigned char bit) reg&=(~(1<<bit))
 #define tog_bit (unsigned char reg,unsigned char bit) reg^=(1<<bit)
 #define read_bit (unsigned char reg,unsigned char bit) (reg&(1<<bit))>>bit
*/

/*
 unsigned char set_bit ( unsigned char reg,int bit)
{
	return reg|=(1<<bit);
}

unsigned char clr_bit (unsigned char reg,int bit)
{
	return reg&=(~(1<<bit));
}

unsigned char tog_bit (unsigned char reg,int bit)
{
	return reg^=(1<<bit);
}

unsigned char read_bit (unsigned char reg,int bit)
{
	return (reg&(1<<bit))>>bit;
}
*/
/*#ifndef STD_MACROS_H_
#define STD_MACROS_H_
//MACROS File for setting, resetting, toggling and reading bits from registers.
#define set_bit(reg,bit)	reg|=(1<<bit) //asserting a bit in a register
#define clr_bit(reg,bit)	reg&=(~(1<<bit)) //deasserting a bit in a register
#define tog_bit(reg,bit)	reg^=(1<<bit) //toggling a bit in a register
#define read_bit(reg,bit)	reg&=(1<<bit)>>bit //reading a bit in a register.
*/
#ifndef STD_MACROS_H_
#define STD_MACROS_H_
//MACROS File for setting, resetting, toggling and reading bits from registers.
#define set_bit(reg,bit)	reg|=(1<<bit) //asserting a bit in a register
#define clr_bit(reg,bit)	reg&=(~(1<<bit)) //deasserting a bit in a register
#define tog_bit(reg,bit)	reg^=(1<<bit) //toggling a bit in a register
#define read_bit(reg,bit)	reg&=(1<<bit)>>bit //reading a bit in a register.



#endif /* STD_MACROS_H_ */






void port_uinit (unsigned char port_name)
{
	switch(port_name)
	{
		case 'A':
		case 'a':
		{
			set_bit(SYSCTL_RCGCGPIO_R,0);
			while(read_bit(SYSCTL_RCGCGPIO_R,0)==0);
			GPIO_PORTA_LOCK_R=0x4C4F434B;
			GPIO_PORTA_CR_R=0xFF;
			GPIO_PORTA_DEN_R=0xFF;
		}
		break;
		
		case 'B':
		case 'b':
		{
			set_bit (SYSCTL_RCGCGPIO_R,1);
			while (read_bit(SYSCTL_RCGCGPIO_R,1)==0);
			GPIO_PORTB_LOCK_R=0x4C4F434B;
			GPIO_PORTB_CR_R=0xFF;
			GPIO_PORTB_DEN_R=0xFF;
		}
		break;
		
		case 'C':
		case 'c':
		{
			set_bit (SYSCTL_RCGCGPIO_R,2);
			while (read_bit(SYSCTL_RCGCGPIO_R,2)==0);
			GPIO_PORTC_LOCK_R=0x4C4F434B;
			GPIO_PORTC_CR_R=0xFF;
			GPIO_PORTC_DEN_R=0xFF;
		}
		break;
	
		case 'D':
		case 'd':
		{
			set_bit (SYSCTL_RCGCGPIO_R,3);
			while (read_bit(SYSCTL_RCGCGPIO_R,3)==0);
			GPIO_PORTD_LOCK_R=0x4C4F434B;
			GPIO_PORTD_CR_R=0xFF;
			GPIO_PORTD_DEN_R=0xFF;
		}
		break;
		
		case 'E':
		case 'e':
		{
			set_bit (SYSCTL_RCGCGPIO_R,4);
			while (read_bit(SYSCTL_RCGCGPIO_R,4)==0);
			GPIO_PORTE_LOCK_R=0x4C4F434B;
			GPIO_PORTE_CR_R=0x2F;
			GPIO_PORTE_DEN_R=0x2F;
		}
		break;
		
		case 'F':
		case 'f':
		{
			set_bit (SYSCTL_RCGCGPIO_R,5);
			while (read_bit(SYSCTL_RCGCGPIO_R,5)==0);
			GPIO_PORTF_LOCK_R=0x4C4F434B;
			GPIO_PORTF_CR_R=0x1F;
			GPIO_PORTF_DEN_R=0x1F;
		}
		break;
	}
}
void DIO_vSET_PIN_DIR (unsigned char port_name, unsigned char pin_number, unsigned char direction)
{
	switch (port_name)
	{
		case 'A':
		case 'a':
		{
			if (direction==1)
			set_bit(GPIO_PORTA_DIR_R,pin_number);
			else
			clr_bit(GPIO_PORTA_DIR_R,pin_number);
		}
		break;
		
		case 'B':
		case 'b':
		{
			if (direction==1)
			set_bit(GPIO_PORTB_DIR_R,pin_number);
			else
			clr_bit(GPIO_PORTB_DIR_R,pin_number);
		}
		break;

		case 'C':
		case 'c':
		{
			if (direction==1)
			set_bit(GPIO_PORTC_DIR_R,pin_number);
			else
			clr_bit(GPIO_PORTC_DIR_R,pin_number);
		}
		break;
		
		case 'D':
		case 'd':
		{
			if (direction==1)
			set_bit(GPIO_PORTD_DIR_R,pin_number);
			else
			clr_bit(GPIO_PORTD_DIR_R,pin_number);
		}
		break;
		
		case 'E':
		case 'e':
		{
			if (direction==1)
			set_bit(GPIO_PORTE_DIR_R,pin_number);
			else
			clr_bit(GPIO_PORTE_DIR_R,pin_number);
		}
		break;
		
		case 'F':
		case 'f':
		{
			if (direction==1)
			set_bit(GPIO_PORTF_DIR_R,pin_number);
			else
			clr_bit(GPIO_PORTF_DIR_R,pin_number);
		}
		break;
	}
}

void DIO_vWRITE_PIN (unsigned char port_name, unsigned char pin_number, unsigned char data)
{
	switch (port_name)
	{
		case 'A':
		case 'a':
		{
			if (data==1)
			set_bit(GPIO_PORTA_DATA_R, pin_number);
			else
			clr_bit(GPIO_PORTF_DIR_R,pin_number);
		}
		break;
		
		case 'B':
		case 'b':
		{
			if (data==1)
			set_bit(GPIO_PORTB_DATA_R, pin_number);
			else
			clr_bit(GPIO_PORTB_DIR_R,pin_number);
		}
		break;
			
		case 'C':
		case 'c':
		{
			if (data==1)
			set_bit(GPIO_PORTC_DATA_R, pin_number);
			else
			clr_bit(GPIO_PORTC_DIR_R,pin_number);
		}
		break;
		
		case 'D':
		case 'd':
		{
			if (data==1)
			set_bit(GPIO_PORTD_DATA_R, pin_number);
			else
			clr_bit(GPIO_PORTD_DIR_R,pin_number);
		}
		break;
		
		case 'E':
		case 'e':
		{
			if (data==1)
			set_bit(GPIO_PORTE_DATA_R, pin_number);
			else
			clr_bit(GPIO_PORTE_DIR_R,pin_number);
		}
		break;
		
		case 'F':
		case 'f':
		{
			if (data==1)
			set_bit(GPIO_PORTF_DATA_R, pin_number);
			else
			clr_bit(GPIO_PORTF_DIR_R,pin_number);
		}
		break;
	}
}

void DIO_vTOGGLE_PIN (unsigned char port_name, unsigned char pin_number)
{
	switch (port_name)
	{
		case 'A':
		case 'a':
		{
			tog_bit(GPIO_PORTA_DATA_R, pin_number);
		}
		break;
		
		case 'B':
		case 'b':
		{
			tog_bit(GPIO_PORTB_DATA_R, pin_number);
		}
		break;
		
		case 'C':
		case 'c':
		{
			tog_bit(GPIO_PORTC_DATA_R, pin_number);
		}
		break;
		case 'D':
		case 'd':
		{
			tog_bit(GPIO_PORTD_DATA_R, pin_number);
		}
		break;
		
		case 'E':
		case 'e':
		{
			tog_bit(GPIO_PORTE_DATA_R, pin_number);
		}
		break;
		
		case 'F':
		case 'f':
		{
			tog_bit(GPIO_PORTF_DATA_R, pin_number);
		}
		break;
	}		
}


void DIO_vSET_PORT_DIR (unsigned char port_name, unsigned char direction)
{
	switch (port_name)
	{		
		case 'A':
		case 'a':
		{
			GPIO_PORTA_DIR_R=direction;
		}
		break;
		
		case 'B':
		case 'b':
		{
			GPIO_PORTB_DIR_R=direction;
		}
		break;
		
		case 'C':
		case 'c':
		{
			GPIO_PORTC_DIR_R=direction;
		}
		break;
		
		case 'D':
		case 'd':
		{
			GPIO_PORTD_DIR_R=direction;
		}
		break;
		
		case 'F':
		case 'f':
		{
			GPIO_PORTF_DIR_R=direction;
		}
		break;
		
		case 'E':
		case 'e':
		{
			GPIO_PORTE_DIR_R=direction;
		}
		break;
	}		
}

void DIO_vSET_WRITE_PORT (unsigned char port_name, unsigned char data)
{
	switch (port_name)
	{		
		case 'A':
		case 'a':
		{
			GPIO_PORTA_DATA_R=data;
		}
		break;
		
		case 'B':
		case 'b':
		{
			GPIO_PORTB_DATA_R=data;
		}
		break;
		
		case 'C':
		case 'c':
		{
			GPIO_PORTC_DATA_R=data;
		}
		break;
		
		case 'D':
		case 'd':
		{
			GPIO_PORTD_DATA_R=data;
		}
		break;
		
		case 'E':
		case 'e':
		{
			GPIO_PORTE_DATA_R=data;
		}
		break;
		
		case 'F':
		case 'f':
		{
			GPIO_PORTF_DATA_R=data;
		}
		break;
	}		
}

unsigned char DIO_u8_READ_PIN (unsigned char port_name, unsigned char pin_number)
{
	switch (port_name)
	{
		case 'A':
		case 'a':
		{
			return read_bit(GPIO_PORTA_DATA_R, pin_number);
		}
		
		case 'B':
		case 'b':
		{
			return read_bit(GPIO_PORTB_DATA_R, pin_number);
		}
		
		case 'C':
		case 'c':
		{
			return read_bit(GPIO_PORTC_DATA_R, pin_number);
		}
		
		case 'D':
		case 'd':
		{
			return read_bit(GPIO_PORTD_DATA_R, pin_number);
		}
		
		case 'E':
		case 'e':
		{
			return read_bit(GPIO_PORTE_DATA_R, pin_number);
		}
		
		case 'F':
		case 'f':
		{
			return read_bit(GPIO_PORTF_DATA_R, pin_number);
		}
	}
}

unsigned char DIO_u8_READ_PORT (unsigned char port_name)
{
	switch (port_name)
	{
		case 'A':
		case 'a':
		{
			return GPIO_PORTA_DATA_R;
		}
		
		case 'B':
		case 'b':
		{
			return GPIO_PORTB_DATA_R;
		}
		
		case 'C':
		case 'c':
		{
			return GPIO_PORTC_DATA_R;
		}
		
		case 'D':
		case 'd':
		{
			return GPIO_PORTD_DATA_R;
		}
		
		case 'E':
		case 'e':
		{
			return GPIO_PORTE_DATA_R;
		}
		
		case 'F':
		case 'f':
		{
			return GPIO_PORTF_DATA_R;
		}
	}
}

void DIO_vENABLE_PULL_UP (unsigned char port_name, unsigned char pin_number)
{
	switch (port_name)
	{
		case 'A':
		case 'a':
		{
			set_bit(GPIO_PORTA_PUR_R, pin_number);
		}
		break;
		
		case 'B':
		case 'b':
		{
			set_bit(GPIO_PORTB_PUR_R, pin_number);
		}
		break;
		
		case 'C':
		case 'c':
		{
			set_bit(GPIO_PORTC_PUR_R, pin_number);
		}
		break;
		
		case 'D':
		case 'd':
		{
			set_bit(GPIO_PORTD_PUR_R, pin_number);
		}
		break;
		
		case 'E':
		case 'e':
		{
			set_bit(GPIO_PORTE_PUR_R, pin_number);
		}
		break;
		
		case 'F':
		case 'f':
		{
			set_bit(GPIO_PORTF_PUR_R, pin_number);
		}
		break;
	}
}

void DIO_vWRITE_HIGH_LEVEL (unsigned char port_name, unsigned char data)
{
	data<<=4;
	
	switch (port_name)
	{
		case 'A':
		case 'a':
		{
			GPIO_PORTA_DATA_R &= 0x0F;
			GPIO_PORTA_DATA_R |= data;
		}
		break;
		
		case 'B':
		case 'b':
		{
			GPIO_PORTB_DATA_R &= 0x0F;
			GPIO_PORTB_DATA_R |= data;
		}
		break;
		
		case 'C':
		case 'c':
		{
			GPIO_PORTC_DATA_R &= 0x0F;
			GPIO_PORTC_DATA_R |= data;
		}
		break;
		
		case 'D':
		case 'd':
		{
			GPIO_PORTD_DATA_R &= 0x0F;
			GPIO_PORTD_DATA_R |= data;
		}
		break;
		
		case 'E':
		case 'e':
		{
			GPIO_PORTE_DATA_R &= 0x0F;
			GPIO_PORTE_DATA_R |= data;
		}
		break;
		
		case 'F':
		case 'f':
		{
			GPIO_PORTF_DATA_R &= 0x0F;
			GPIO_PORTF_DATA_R |= data;
		}
		break;
	}
}
			
void DIO_vWRITE_LOW_LEVEL (unsigned char port_name, unsigned char data)
{
	switch (port_name)
	{
		case 'A':
		case 'a':
		{
			GPIO_PORTA_DATA_R &= 0xF0;
			GPIO_PORTA_DATA_R |= data;
		}
		break;
		
		case 'B':
		case 'b':
		{
			GPIO_PORTB_DATA_R &= 0xF0;
			GPIO_PORTB_DATA_R |= data;
		}
		break;
		
		case 'C':
		case 'c':
		{
			GPIO_PORTC_DATA_R &= 0xF0;
			GPIO_PORTC_DATA_R |= data;
		}
		break;
		
		case 'D':
		case 'd':
		{
			GPIO_PORTD_DATA_R &= 0xF0;
			GPIO_PORTD_DATA_R |= data;
		}
		break;
		
		case 'E':
		case 'e':
		{
			GPIO_PORTE_DATA_R &= 0xF0;
			GPIO_PORTE_DATA_R |= data;
		}
		break;
		
		case 'F':
		case 'f':
		{
			GPIO_PORTF_DATA_R &= 0xF0;
			GPIO_PORTF_DATA_R |= data;
		}
		break;
	}
}
