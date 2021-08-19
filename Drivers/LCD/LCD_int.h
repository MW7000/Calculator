#ifndef  LCD_INT_H
#define  LCD_INT_H


void LCD_vid_init();

void LCD_vid_WRITE_CMD(uint8 copy_uint8_CMD);

void LCD_vid_WRITE_CHARACTER(uint8 copy_uint8_CHARACTER);

void LCD_vid_WRITE_TO_CG_RAM(uint8 copy_uint8_Row_content);

void LCD_vid_WRITE_STRING(uint8 * copy_uint8_STRING);

void LCD_vid_GoToRowColmun(uint8 copy_uint8_Row , uint8 copy_uint8_colmun);

void LCD_vid_CLEARSCREEN();

#endif
