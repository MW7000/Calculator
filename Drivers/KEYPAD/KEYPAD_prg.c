#include "STD_Types.h"
#include "BIT_MATH.h"

#include "DIO_int.h"
#include "KEYPAD_int.h"
#include "KEYPAD_priv.h"
#include "KEYPAD_config.h"

#if(KEYPAD_Pull_Up_R_MODE == KEYPAD_internal_MODE)

void KEYPAD_vid_init(){

	DIO_vid_SETPIN(KEYPAD_pin_Row1 , DIO_PIN_HIGH);
	DIO_vid_SETPIN(KEYPAD_pin_Row2 , DIO_PIN_HIGH);
	DIO_vid_SETPIN(KEYPAD_pin_Row3 , DIO_PIN_HIGH);
	DIO_vid_SETPIN(KEYPAD_pin_Row4 , DIO_PIN_HIGH);
}

#endif


uint16  Local_Return_status;

uint16  KEYPAD_uint16_GetStatus(){

	Local_Return_status = 0;

	DIO_vid_SETPIN(KEYPAD_pin_Col1 , DIO_PIN_LOW);
	DIO_vid_SETPIN(KEYPAD_pin_Col2 , DIO_PIN_HIGH);
	DIO_vid_SETPIN(KEYPAD_pin_Col3 , DIO_PIN_HIGH);
	DIO_vid_SETPIN(KEYPAD_pin_Col4 , DIO_PIN_HIGH);

    KEYPAD_vid_Check_Row(0);

	DIO_vid_SETPIN(KEYPAD_pin_Col1 , DIO_PIN_HIGH);
	DIO_vid_SETPIN(KEYPAD_pin_Col2 , DIO_PIN_LOW);
	DIO_vid_SETPIN(KEYPAD_pin_Col3 , DIO_PIN_HIGH);
	DIO_vid_SETPIN(KEYPAD_pin_Col4 , DIO_PIN_HIGH);

    KEYPAD_vid_Check_Row(1);

	DIO_vid_SETPIN(KEYPAD_pin_Col1 , DIO_PIN_HIGH);
	DIO_vid_SETPIN(KEYPAD_pin_Col2 , DIO_PIN_HIGH);
	DIO_vid_SETPIN(KEYPAD_pin_Col3 , DIO_PIN_LOW);
	DIO_vid_SETPIN(KEYPAD_pin_Col4 , DIO_PIN_HIGH);

    KEYPAD_vid_Check_Row(2);

	DIO_vid_SETPIN(KEYPAD_pin_Col1 , DIO_PIN_HIGH);
	DIO_vid_SETPIN(KEYPAD_pin_Col2 , DIO_PIN_HIGH);
	DIO_vid_SETPIN(KEYPAD_pin_Col3 , DIO_PIN_HIGH);
	DIO_vid_SETPIN(KEYPAD_pin_Col4 , DIO_PIN_LOW);

    KEYPAD_vid_Check_Row(3);

    return Local_Return_status;

}


static void KEYPAD_vid_Check_Row(uint8 copy_uint8_NO){

if(DIO_unit8_GETPIN(KEYPAD_pin_Row1)==0){

	SET_BIT(Local_Return_status , (4*0) + copy_uint8_NO);
}

if(DIO_unit8_GETPIN(KEYPAD_pin_Row2)==0){

	SET_BIT(Local_Return_status , (4*1) + copy_uint8_NO);
}

if(DIO_unit8_GETPIN(KEYPAD_pin_Row3)==0){

	SET_BIT(Local_Return_status , (4*2) + copy_uint8_NO);
}

if(DIO_unit8_GETPIN(KEYPAD_pin_Row4)==0){

	SET_BIT(Local_Return_status , (4*3) + copy_uint8_NO);
}

}
