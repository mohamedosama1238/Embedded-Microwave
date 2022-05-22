

#include "Io.h"
#include "DIO.h"
#include "tm4c123gh6pm.h"

void keypad_Init(void)
{
	DIO_vWRITE_LOW_LEVEL ('D', 0x0F);   //3ashan awel 4 bits output we a5er 4 input 
	DIO_vWRITE_LOW_LEVEL ('E', 0x00);
	DIO_vENABLE_PULL_UP ('E', 0);
	DIO_vENABLE_PULL_UP ('E', 1);
	DIO_vENABLE_PULL_UP ('E', 2);
	DIO_vENABLE_PULL_UP ('E', 3);
}

unsigned char keypad_v8Read(void)
{
	unsigned char arr [4][4]= { { '1', '2', '3', 'A' } , { '4', '5', '6', 'B' } , { '7', '8', '9', 'C' } , { '*', '0', '#', 'D' } } ;
	unsigned char row, col, x;
	unsigned char return_Value = 0xFF;
	for (row = 0; row < 4; row++)
	{
		DIO_vWRITE_LOW_LEVEL('D',0x0F);
		for (col=0; col<= 3; col++)
		{
			x = DIO_u8_READ_PIN('E',col);
			if (x==0)
			{
			return_Value = arr[row][col];
			//return return_Value;
			break;
			}
		}
	}
	return return_Value;
}