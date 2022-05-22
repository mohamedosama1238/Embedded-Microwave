#include "Io.h"
#include "tm4c123gh6pm.h"



#ifndef STD_MACROS_H_
#define STD_MACROS_H_
//MACROS File for setting, resetting, toggling and reading bits from registers.
#define set_bit(reg,bit)	reg|=(1<<bit) //asserting a bit in a register
#define clr_bit(reg,bit)	reg&=(~(1<<bit)) //deasserting a bit in a register
#define tog_bit(reg,bit)	reg^=(1<<bit) //toggling a bit in a register
#define read_bit(reg,bit)	reg&=(1<<bit)>>bit //reading a bit in a register.



#endif /* STD_MACROS_H_ */




/*
 #define set_bit (unsigned char reg,unsigned char bit) reg|=(1<<bit)
 #define clr_bit (unsigned char reg,unsigned char bit) reg&=(~(1<<bit))
 #define tog_bit (unsigned char reg,unsigned char bit) reg^=(1<<bit)
 #define read_bit (unsigned char reg,unsigned char bit) (reg&(1<<bit))>>bit
*/

/*
unsigned char set_bit ( unsigned char reg,int bit);
unsigned char clr_bit (unsigned char reg,int bit);
unsigned char tog_bit (unsigned char reg,int bit);
unsigned char read_bit (unsigned char reg,int bit);
*/

void port_uinit (unsigned char port_name);
void DIO_vSET_PIN_DIR (unsigned char port_name, unsigned char pin_number, unsigned char direction);
void DIO_vWRITE_PIN (unsigned char port_name, unsigned char pin_number, unsigned char data);
void DIO_vTOGGLE_PIN (unsigned char port_name, unsigned char pin_number);
void DIO_vSET_PORT_DIR (unsigned char port_name, unsigned char direction);
void DIO_vSET_WRITE_PORT (unsigned char port_name, unsigned char data);
unsigned char DIO_u8_READ_PIN (unsigned char port_name, unsigned char pin_number);
unsigned char DIO_u8_READ_PORT (unsigned char port_name);
void DIO_vENABLE_PULL_UP (unsigned char port_name, unsigned char pin_number);
void DIO_vWRITE_HIGH_LEVEL (unsigned char port_name, unsigned char data);
void DIO_vWRITE_LOW_LEVEL (unsigned char port_name, unsigned char data);
