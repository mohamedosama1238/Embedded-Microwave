#include "tm4c123gh6pm.h"
#include "DIO.h"
#include "macros.h"
void Button_Init(unsigned char port_name,unsigned char pin_number){
	port_uinit(port_name);
	DIO_vSET_PIN_DIR(port_name,pin_number,0);
}
unsigned char Button_read(unsigned char port_name,unsigned char pin_number){
 return DIO_u8_READ_PIN(port_name,pin_number);
}
void Button_InitPullUp(unsigned char port_name,unsigned char pin_number){
	port_uinit(port_name);
	DIO_vSET_PIN_DIR(port_name,pin_number,0);
	DIO_vENABLE_PULL_UP(port_name,pin_number);
}