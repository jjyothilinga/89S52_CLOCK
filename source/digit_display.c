#include "typedefs.h"
#include "digitDisplay.h"
#include "board.h"

// Common Anode 7 segment
UINT8 Seven_seg_map[] = {0X03, 0X9F, 0X25, 0X0D, 0X99, 0X49, 0X41, 0X1F, 0X01, 0X09};

typedef struct _Display
{
	UINT8 display_Buf[3];
	UINT8 Buf_index;
}DISPLAY;

DISPLAY dis = {0};

// Initialization of Digit_Display
void Digit_Display_init(void)
{
	UINT8 i;
	for (i = 0; i < 3; i++)
	{
		dis.display_Buf[i] = 0X03;
	}
}


// Upadating display buffer
void Digit_Display_update(UINT8 *token_array)
{
	UINT8 i;
	for (i = 0; i < 3; i++)
	{
		dis.display_Buf[i] = Seven_seg_map[0x0F & token_array[i]];
	}
}

// Display Task
void Digit_Display_task(void)
{
	switch(dis.Buf_index)
	{
		case 0: OUTPUT_ENABLE_DIS1 = 1;
						OUTPUT_ENABLE_DIS2 = 1;
						OUTPUT_ENABLE_DIS3 = 1;
						OUTPUT_SEVEN_SEGMENT = ~(dis.display_Buf[0]);
						OUTPUT_ENABLE_DIS1 = 0;
						break;
		case 1: OUTPUT_ENABLE_DIS1 = 1;
						OUTPUT_ENABLE_DIS2 = 1;
						OUTPUT_ENABLE_DIS3 = 1;
						OUTPUT_SEVEN_SEGMENT = ~(dis.display_Buf[1]);
						OUTPUT_ENABLE_DIS2 = 0;
						break;
		case 2: OUTPUT_ENABLE_DIS1 = 1;
						OUTPUT_ENABLE_DIS2 = 1;
						OUTPUT_ENABLE_DIS3 = 1;
						OUTPUT_SEVEN_SEGMENT = ~(dis.display_Buf[2]);
						OUTPUT_ENABLE_DIS3 = 0;
						break;		
		default: break;
	}
	dis.Buf_index++;
	
	if(dis.Buf_index > 2)
	{
		dis.Buf_index = 0;
	}
}