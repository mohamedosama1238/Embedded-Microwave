#include "tm4c123gh6pm.h"
#include "Io.h"
#include "DIO.h"
#include "keypad.h"   // momken tet8ayar
#include "LED_TIMER.h"
#include "BUTTON.h"
#include "LCD.h"
#include "Buzzer.h"
#include "Io.h"
#include <stdint.h>
#include "math.h"
#include "charTOint.h"
#include "Interrupt.h"




unsigned char arr_done[]={"cooking is done"};
unsigned char arr_welcome[]={"What to eat?"};
unsigned char arr_number[]={"Enter the number from 1 to 9:"};
unsigned char arr_ERR[] = { "ERR" };
unsigned char arr_popcorn[] = {"Popcorn"};
unsigned char arr_beef[]={"Beef weight?"};
unsigned char arr_chicken[]={"Chicken weight?"};
unsigned char arr_cooking[]={"Cooking time?"};
unsigned char arr_pause[]={"pausing"};
unsigned char timer[]={'0','0',':','0','0'};
int i ;
int j;
int x;
int z;
int xx;
int xy;
int ww ;
int  bb;
float bbflo;
int l;
int m;
int n;

int weighttotime;


unsigned char A;
unsigned char B;
unsigned char C;
unsigned char D;

int  main()
 {
  
	LCD_vInit();
	keypad_Init();
	Button_extrnal_Init();
  LED_vInit();
	Button_Init();
	Buzzer_init();


	// besm ellah elra7man elra7eem

	while(1)
		{
labelm:	LCD_vSendString(arr_welcome);
				Delay(5000);
				LCD_ClearScreen();
			
			switch(keypad_v8Read())
			{
				case'A':
				
					LCD_vSendString(arr_popcorn);
					Delay(2000);
					while((SW1()==0x00) || (SW3()==0x00)){};
					
					LCD_ClearScreen();
					Delay(500);
					for(i=5;i>=0;i--)
					{
						for (j=9;j>=0;j--)
						{
							while (SW1()==1){};
							//{
							
								
								if((SW2()==0x0) || (SW3()==0x00))
								{
									goto labelj;
								
								}
								
								timer[3]=i+ '0';
								timer[4]=j+ '0';
								LCD_vSendString(timer);					
label:					Led_On();
								Delay(1000);
								LCD_ClearScreen();
							
							
						//	}
							//else
							//{
								//Led_Off();
								//break;9
							//}
							
						}
					}
						
					goto labelr;
				/*	buzzer_on();
					buzzer_off();
					buzzer_on();
					buzzer_off();
					buzzer_on();
					buzzer_off();*/
					
					
				/*while(SW1()==0){};
				while(SW2()==0){};
label2:		GPIO_PORTF_DATA_R |= 0x0E ;
					Delay(1000);
					GPIO_PORTF_DATA_R &= 0xF1 ;
					Delay(1000);
					
					while (SW3()==0x00){};
						goto label2;

					while (SW3()==0x04){};
						goto label;}


				while(SW2()==1){};
					goto label;

				while(SW1()==1){};
					LCD_ClearScreen();
					Led_Off();*/
				
				
				
				/*LCD_ClearScreen();
					Led_Flash();
					buzzer_on();
					buzzer_off();
					buzzer_on();
					buzzer_off();
					buzzer_on();
					buzzer_off();*/
				
				
labelj:		while(1)
					{
					LCD_ClearScreen();
					LCD_vSendString(arr_pause);
					GPIO_PORTF_DATA_R |= 0x0E ;
					Delay(1000);
					GPIO_PORTF_DATA_R &=~0X0E ;
					Delay(1000);
						if(SW3()==0)
						{
							LCD_ClearScreen();
							goto label;
						}
					if(SW2()==0)
					{
						LCD_ClearScreen();
						goto labelm;
					}
					else if(SW1()==0)
						goto label;
					}
			
labelr:		LCD_ClearScreen();
					LCD_vSendString(arr_done);
					Delay(1000);
					LCD_ClearScreen();
					Buzzer();
					Buzzer_Blink();
				
					
				
				break;
				
			




				case'B':
				{	
				
				LCD_vSendString(arr_beef);
				Delay(2000);
				LCD_ClearScreen();
				LCD_vSendString(arr_number);
				Delay(2000);
				while(keypad_v8Read()==0x00){};
				LCD_ClearScreen();
					//ww = keypad_v8Read() ;
				//if( ww=='1' | ww=='3' | ww=='5' | ww =='7' | ww =='9')
				
					while((SW2()==0x00) || (SW3()==0x00)){};
					LCD_ClearScreen();
					//osamaweighttotime=((int)keypad_v8Read()-1) * 0.5 ;
					weighttotime =charToint(keypad_v8Read())*30 ; //time in seconds
				//while (SW12_Input()==0x11); // loop until sw2 pushed
				
				
			   l= ((weighttotime%600))/60 ;
				 m= ((weighttotime%60))/10;
				 n= ((weighttotime%10));
				//goto label3;
				z=l;
				i=m;
				j=n;
				for(;z>=0;z--)
				{
					for (;i>=0;i--)
					{
						for (;j>=0;j--)
						{
//label3:			
							while (SW1()==1){};
					
							if((SW2()==0x0) || (SW3()==0x00))
								{
									goto labelw;
								
								}
								
								timer[1]=z+'0';
								timer[3]=i+'0';
								timer[4]=j+'0';
					
								LCD_vSendString(timer);
labelb:					Led_On();
								Delay(1000);
								LCD_ClearScreen();
					  	}
							j= 9;
							/*else
							{
								Led_Off();
								break;
							}*/
						}
						i= 5;
					}
				goto labelq;
				

	   	 	//while(Button_read('F',4)==1 & Button_read('F',0)==1)
				/*	while(SW1()==0){};
					while(SW2()==0){};
label2b:	GPIO_PORTF_DATA_R |= 0x0E ;
					Delay(1000);
					GPIO_PORTF_DATA_R &= 0xF1 ;
					Delay(1000);
					
					while (SW3()==0x00){};
						goto label2b;

					while (SW3()==0x04){};
						goto labelb;}


					while(SW2()==1){};
					goto labelb;

					while(SW1()==1){};
					LCD_ClearScreen();
					Led_Off();*/
				
labelw:		while(1)
					{
					LCD_ClearScreen();
					LCD_vSendString(arr_pause);
					GPIO_PORTF_DATA_R |= 0x0E ;
					Delay(1000);
					GPIO_PORTF_DATA_R &=~0X0E ;
					Delay(1000);
						if(SW3()==0)
						{
							LCD_ClearScreen();
							goto label;
						}
					if(SW2()==0)
					{
						LCD_ClearScreen();
						goto labelm;
					}
					else if(SW1()==0)
						goto label;
					}
			
labelq:		LCD_ClearScreen();
					LCD_vSendString(arr_done);
					Delay(1000);
					LCD_ClearScreen();
					Buzzer();
					Buzzer_Blink();
				
				
				
				
				break;
			
			
				case'C':

				LCD_vSendString(arr_chicken);
				Delay(2000);
				LCD_ClearScreen();
				LCD_vSendString(arr_number);
				Delay(2000);
				while(keypad_v8Read()==0x00){};
				LCD_ClearScreen();
					//ww = keypad_v8Read() ;
				//if( ww=='1' | ww=='3' | ww=='5' | ww =='7' | ww =='9')
				
					while((SW2()==0x00) || (SW3()==0x00)){};
					LCD_ClearScreen();
					//osamaweighttotime=((int)keypad_v8Read()-1) * 0.5 ;
					weighttotime =charToint(keypad_v8Read())*12 ; //time in seconds
				//while (SW12_Input()==0x11); // loop until sw2 pushed
				
				
			   l= ((weighttotime%600))/60 ;
				 m= ((weighttotime%60))/10;
				 n= ((weighttotime%10));
				//goto label3;
				z=l;
				i=m;
				j=n;
				for(;z>=0;z--)
				{
					for (;i>=0;i--)
					{
						for (;j>=0;j--)
						{
//label3:			
							while (SW1()==1){};
					
							if((SW2()==0x0) || (SW3()==0x00))
								{
									goto labelp;
								
								}
								timer[1]=z+'0';
								timer[3]=i+'0';
								timer[4]=j+'0';
					
								LCD_vSendString(timer);
labelc:					Led_On();
								Delay(1000);
								LCD_ClearScreen();
					  	}
							j= 9;
							/*else
							{
								Led_Off();
								break;
							}*/
						}
						i= 5;
					}
				goto labelt;
				

	   	 	//while(Button_read('F',4)==1 & Button_read('F',0)==1)
				/*	while(SW1()==0){};
					while(SW2()==0){};
label2c:		GPIO_PORTF_DATA_R |= 0x0E ;
					Delay(1000);
					GPIO_PORTF_DATA_R &= 0xF1 ;
					Delay(1000);
					
					while (SW3()==0x00){};
						goto label2c;

					while (SW3()==0x04){};
						goto labelc;


				while(SW2()==1){};
					goto labelc;

				while(SW1()==1){};
					LCD_ClearScreen();
					Led_Off();*/
				
labelp:		while(1)
					{
					LCD_ClearScreen();
					LCD_vSendString(arr_pause);
					GPIO_PORTF_DATA_R |= 0x0E ;
					Delay(1000);
					GPIO_PORTF_DATA_R &=~0X0E ;
					Delay(1000);
						if(SW3()==0)
						{
							LCD_ClearScreen();
							goto label;
						}
					if(SW2()==0)
					{
						LCD_ClearScreen();
						goto labelm;
					}
					else if(SW1()==0)
						goto label;
					}
			
labelt:		LCD_ClearScreen();
					LCD_vSendString(arr_done);
					Delay(1000);
					LCD_ClearScreen();
					Buzzer();
					Buzzer_Blink();
				
				
				
				break;
			
			



				case'D':
label8:		LCD_vSendString(arr_cooking);
					Delay(2000);
					while(keypad_v8Read()==0x00){};
					LCD_ClearScreen();
					if(keypad_v8Read()=='0' | keypad_v8Read()=='1' | keypad_v8Read()=='3' | keypad_v8Read()=='5' | keypad_v8Read()=='7' | keypad_v8Read()=='9' |keypad_v8Read()=='2'  | keypad_v8Read()=='4' | keypad_v8Read()=='6' | keypad_v8Read()=='8' )
					{
						A= keypad_v8Read();
						timer[4]= A;
						//LCD_ClearScreen();
						LCD_vSendString(timer);
						Delay(1000);
						while(keypad_v8Read()==0x00){};
						
						if(keypad_v8Read()=='0' | keypad_v8Read()=='1' | keypad_v8Read()=='3' | keypad_v8Read()=='5' | keypad_v8Read()=='7' | keypad_v8Read()=='9' |keypad_v8Read()=='2'  | keypad_v8Read()=='4' | keypad_v8Read()=='6' | keypad_v8Read()=='8' )
						{
							B= keypad_v8Read();
							timer[3]= timer[4];
							timer[4]=B;
							//LCD_ClearScreen();
							LCD_vSendString(timer);
							Delay(1000);
							while(keypad_v8Read()==0x00){};

							if(keypad_v8Read()=='0' | keypad_v8Read()=='1' | keypad_v8Read()=='3' | keypad_v8Read()=='5' | keypad_v8Read()=='7' | keypad_v8Read()=='9' |keypad_v8Read()=='2'  | keypad_v8Read()=='4' | keypad_v8Read()=='6' | keypad_v8Read()=='8' )
							{
								if(keypad_v8Read()>'5')
								{
									goto labelz;
								}
								C=keypad_v8Read();
								timer[1]= timer[3];
								timer[3]= timer[4];
								timer[4]= C;
								//LCD_ClearScreen();
								LCD_vSendString(timer);
								Delay(1000);
								while(keypad_v8Read()==0x00){};
								

								if(keypad_v8Read()=='0' | keypad_v8Read()=='1' | keypad_v8Read()=='3' | keypad_v8Read()=='5' | keypad_v8Read()=='7' | keypad_v8Read()=='9' |keypad_v8Read()=='2'  | keypad_v8Read()=='4' | keypad_v8Read()=='6' | keypad_v8Read()=='8' )
								{
									D= keypad_v8Read();
									timer[0]= timer[1];
									timer[1]= timer[3];
									timer[3]= timer[4];
									timer[4]= D;
									//LCD_ClearScreen();
									LCD_vSendString(timer);
									Delay(1000);
								
									if((timer[0]>='3'&&timer[1]>'0')||(timer[0]>='3'&&timer[3]>'0')||(timer[0]>='3'&&timer[4]>'0'))
									{
										goto labelz;
									}
									
									/*	if(A>='3')
										{
											if(B>='0')
											{
												if(C>='0')
												{
													if(D>'0')
													{
														LCD_ClearScreen();
													  goto labelm;
													}
													
												}
											}
										}*/
									while(SW1()==1&&SW3()==0x00){};
									
									


										i=charToint(A);
										j=charToint(B);
										x=charToint(C);
										z=charToint(D);
										//goto label10;

									for(;i>=0;i--)
									{
										for (;j>=0;j--)
										{
											for (;x>=0;x--)
											{
												for(;z>=0;z--)
												{
//label10:									
												while (SW1()==1){};
					
											if((SW2()==0x0) || (SW3()==0x00))
											{
												goto labels;
								
											}
														timer[0]=i+'0';
														timer[1]=j+'0';
														timer[3]=x+'0';
														timer[4]=z+'0';
														LCD_vSendString(timer);
														Led_On();
														Delay(1000);
														LCD_ClearScreen();
													
												/*else
													{
														Led_Off();
														break;
													}*/
												}
												z= 9;
											}
												x= 5;
										}
										j=9;
									}
               goto labelu;
							/*	while(SW1()==1 & SW2()==1)
								{
label11:					GPIO_PORTF_DATA_R |= 0x0E ;
									Delay(1000);
									GPIO_PORTF_DATA_R &=~0x0E ;
									Delay(1000);
									if(SW3()==1)
									{
										goto label11;
									}
									else 
										goto label10;
								}


								if( SW2()==0)
								{
									LCD_ClearScreen();
									goto label10;

								}
								else if(SW1()==0)
								{
									LCD_ClearScreen();
									Led_Off();
								}*/
labels:		while(1)
					{
					LCD_ClearScreen();
					LCD_vSendString(arr_pause);
					GPIO_PORTF_DATA_R |= 0x0E ;
					Delay(1000);
					GPIO_PORTF_DATA_R &=~0X0E ;
					Delay(1000);
						if(SW3()==0)
						{
							LCD_ClearScreen();
							goto label;
						}
					if(SW2()==0)
					{
						LCD_ClearScreen();
						goto labelm;
					}
					else if(SW1()==0)
						goto label;
					}
			
labelu:		LCD_ClearScreen();
					LCD_vSendString(arr_done);
					Delay(1000);
					LCD_ClearScreen();
					Buzzer();
					Buzzer_Blink();
								
labelz:		LCD_ClearScreen();			
					break;
					


								
						
				}
				else
				{
					LCD_ClearScreen();
					LCD_vSendString(arr_ERR);
					Delay(2000);
					LCD_ClearScreen();
					goto label8;
				}
			}
		}
	}


				case 0xFF:
					break;


				default:
					LCD_vSendString(arr_ERR);
					Delay(2000);
					LCD_ClearScreen();
					break;
			}
		}
	}
}



 //elmafrood break btetla32 men loop wa7da 
	//lw madostesh 7aga we wesel le 0000 , hyatela3 men fpll wloop wehay5oah