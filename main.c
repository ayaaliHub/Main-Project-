#include <avr/io.h>
#include "MemMap.h"
#include "StdTypes.h"
#define  F_CPU   8000000
#include "util/delay.h"

u8 segmentArr[10]={0x3F,0x06,0x5B,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

u8 segment_codes[10] = {
	0x3F,  // 0
	0x06,  // 1
	0x5B,  // 2
	0x4F,  // 3
	0x66,  // 4
	0x6D,  // 5
	0x7D,  // 6
	0x07,  // 7
	0x7F,  // 8
	0x6F   // 9
};

// Global variables to track the stopwatch state
volatile u8 timee=30;
u8 flag_mode=0;
u8 flag_Start_Stop=0;

u8 i;
void Segment_display_MLX(u8 n)
{
	u8 d0=n%10;
	u8 d1=n/10;
	
	SET_BIT(PORTC,0);
	CLR_BIT(PORTC,1);
	PORTA=segmentArr[d0];
	_delay_ms(5);
	SET_BIT(PORTC,1);
	CLR_BIT(PORTC,0);
	PORTA=segmentArr[d1];
	_delay_ms(5);
}
// Function to configure I/O pins for seven segments and buttons
 void DIO_init() {
	// Configure PORTA as output for seven-segment display
	DDRA = 0xFF;

	// Configure PORTD as input for buttons
	CLR_BIT(DDRD, 0);  // PD0 for Resume/Pause
	CLR_BIT(DDRD, 1);  // PD1 for Reset
	CLR_BIT(DDRD, 2);  // PD2 for Mode
	CLR_BIT(DDRD, 3);  // PD3 for Calibration Direction

	// Enable pull-up resistors for buttons
	SET_BIT(PORTD, 0);
	SET_BIT(PORTD, 1);
	SET_BIT(PORTD, 2);
	SET_BIT(PORTD, 3);

	// Configure PORTC as output for selecting display
	DDRC =0xff;
}
u8 reset=0;

int main(void) {
	u8 counter=0;
	DIO_init();  // Initialize I/O pins
	while (1) {
		//display_digit(seconds);
			for(int i=0;i<8;i++)
			{
				Segment_display_MLX(timee);
			}
			
			if (GET_BIT(PIND,0)==0){                  //calibiration mood
				_delay_ms(10);
				while(GET_BIT(PIND,0)==0)
					_delay_ms(10);
					flag_mode=flag_mode^1;
			}
			if(flag_mode==0){                        
				if (GET_BIT(PIND,1)==0){
					_delay_ms(10);
					while(GET_BIT(PIND,1)==0)
					_delay_ms(10);
					timee++;                
					
				}
				if (GET_BIT(PIND,2)==0){           
					_delay_ms(10);
					while(GET_BIT(PIND,2)==0)
					_delay_ms(10);
					timee--;
					
				}
				reset=timee;
			}
			if(flag_mode==1){
				if(GET_BIT(PIND,1)==0){
						_delay_ms(10);
						while(GET_BIT(PIND,1)==0)
						_delay_ms(10);
						flag_Start_Stop=flag_Start_Stop^1;
					
				}
				
				
			}
			if((flag_mode==1)&&(flag_Start_Stop==1)&&(timee>0)&&(counter<=10)){
				counter++;
				_delay_ms(1);
			}
			
			if(counter==10){
				timee--;
				counter=0;
			}
			if((flag_mode==1)){
				if(GET_BIT(PIND,2)==0){
					_delay_ms(10);
					while(GET_BIT(PIND,2)==0)
				    _delay_ms(10);
					timee=reset;

				}
				_delay_ms(1);
			}
	}
}
			
	