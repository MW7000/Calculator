#include  "STD_Types.h"
#include  "BIT_MATH.h"

#include  "DIO_int.h"
#include  "LCD_int.h"
#include  "LCD_priv.h"
#include  "LCD_config.h"
#include  "util/delay.h"

void LCD_vid_init(){

	_delay_ms(30);
	LCD_vid_WRITE_CMD(0b00111000);
	_delay_ms(1);
	LCD_vid_WRITE_CMD(0b00001111);
	_delay_ms(1);
	LCD_vid_WRITE_CMD(0b00000001);
	_delay_ms(1);
	LCD_vid_WRITE_CMD(0b00000110);

}

static uint8 Local_var,Local_F_result;

void LCD_vid_WRITE_CMD(uint8 copy_uint8_CMD){

   DIO_vid_SETPIN(LCD_pin_RS, DIO_PIN_LOW);

   LCD_vid_EXCUTE_CMD(copy_uint8_CMD);

}

void LCD_vid_WRITE_CHARACTER(uint8 copy_uint8_CHARACTER){

        DIO_vid_SETPIN(LCD_pin_RS, DIO_PIN_HIGH);

	LCD_vid_EXCUTE_CMD(copy_uint8_CHARACTER);

}

void LCD_vid_WRITE_STRING(uint8 * copy_uint8_STRING){

	DIO_vid_SETPIN(LCD_pin_RS, DIO_PIN_HIGH);

	Local_var = 0;

	while(copy_uint8_STRING[Local_var]!='\0'){

	   LCD_vid_WRITE_CHARACTER(copy_uint8_STRING[Local_var]);

		Local_var ++;
	}

}

void LCD_vid_GoToRowColmun(uint8 copy_uint8_Row , uint8 copy_uint8_colmun){


	if(copy_uint8_Row == 1){

		Local_F_result = 0x00 + copy_uint8_colmun;


	}else if (copy_uint8_Row == 2){

		Local_F_result = 0x40 + copy_uint8_colmun;

	}

	LCD_vid_WRITE_CMD(Local_F_result | 0x80);

}

void LCD_vid_CLEARSCREEN(){

	LCD_vid_WRITE_CMD(0b00000001);

}


void LCD_vid_EXCUTE_CMD(uint8 copy_LCD_CMD){

	DIO_vid_SETPIN(LCD_pin_RW , DIO_PIN_LOW);
	_delay_ms(1);
	DIO_vid_SETPIN(LCD_pin_E, DIO_PIN_HIGH);
    _delay_ms(1);

	if(GET_BIT(copy_LCD_CMD, 0 )){

		DIO_vid_SETPIN(LCD_pin_D0 , DIO_PIN_HIGH);

	}else{

		DIO_vid_SETPIN(LCD_pin_D0 , DIO_PIN_LOW);

	}

	if(GET_BIT(copy_LCD_CMD, 1 )){

		DIO_vid_SETPIN(LCD_pin_D1 , DIO_PIN_HIGH);

	}else{

		DIO_vid_SETPIN(LCD_pin_D1 , DIO_PIN_LOW);

	}

	if(GET_BIT(copy_LCD_CMD, 2 )){

		DIO_vid_SETPIN(LCD_pin_D2 , DIO_PIN_HIGH);

	}else{

		DIO_vid_SETPIN(LCD_pin_D2 , DIO_PIN_LOW);

	}

	if(GET_BIT(copy_LCD_CMD, 3 )){

		DIO_vid_SETPIN(LCD_pin_D3 , DIO_PIN_HIGH);

	}else{

		DIO_vid_SETPIN(LCD_pin_D3 , DIO_PIN_LOW);

	}

	if(GET_BIT(copy_LCD_CMD, 4 )){

		DIO_vid_SETPIN(LCD_pin_D4 , DIO_PIN_HIGH);

	}else{

		DIO_vid_SETPIN(LCD_pin_D4 , DIO_PIN_LOW);

	}

	if(GET_BIT(copy_LCD_CMD, 5 )){

		DIO_vid_SETPIN(LCD_pin_D5 , DIO_PIN_HIGH);

	}else{

		DIO_vid_SETPIN(LCD_pin_D5 , DIO_PIN_LOW);

	}

	if(GET_BIT(copy_LCD_CMD, 6 )){

		DIO_vid_SETPIN(LCD_pin_D6 , DIO_PIN_HIGH);

	}else{

		DIO_vid_SETPIN(LCD_pin_D6 , DIO_PIN_LOW);

	}

	if(GET_BIT(copy_LCD_CMD, 7 )){

		DIO_vid_SETPIN(LCD_pin_D7 , DIO_PIN_HIGH);

	}else{

		DIO_vid_SETPIN(LCD_pin_D7 , DIO_PIN_LOW);

	}

	_delay_ms(1);
    DIO_vid_SETPIN(LCD_pin_E, DIO_PIN_LOW);
    _delay_ms(2);

}

