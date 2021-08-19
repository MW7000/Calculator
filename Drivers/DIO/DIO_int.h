#ifndef DIO_INT_H
#define DIO_INT_H

#define DIO_pin_NO_0      0
#define DIO_pin_NO_1      1
#define DIO_pin_NO_2      2
#define DIO_pin_NO_3      3
#define DIO_pin_NO_4      4
#define DIO_pin_NO_5      5
#define DIO_pin_NO_6      6
#define DIO_pin_NO_7      7
#define DIO_pin_NO_8      8
#define DIO_pin_NO_9      9
#define DIO_pin_NO_10     10
#define DIO_pin_NO_11     11
#define DIO_pin_NO_12     12
#define DIO_pin_NO_13     13
#define DIO_pin_NO_14     14
#define DIO_pin_NO_15     15
#define DIO_pin_NO_16     16
#define DIO_pin_NO_17     17
#define DIO_pin_NO_18     18
#define DIO_pin_NO_19     19
#define DIO_pin_NO_20     20
#define DIO_pin_NO_21     21
#define DIO_pin_NO_22     22
#define DIO_pin_NO_23     23
#define DIO_pin_NO_24     24
#define DIO_pin_NO_25     25
#define DIO_pin_NO_26     26
#define DIO_pin_NO_27     27
#define DIO_pin_NO_28     28
#define DIO_pin_NO_29     29
#define DIO_pin_NO_30     30
#define DIO_pin_NO_31     31

#define DIO_PIN_LOW    0
#define DIO_PIN_HIGH   1


void DIO_vid_init(void);

void DIO_vid_SETPIN(uint8 copy_uint8_pinNO , uint8 copy_uint8_pinVALUE);

uint8 DIO_unit8_GETPIN(uint8 copy_uint8_pinNO);


#endif
