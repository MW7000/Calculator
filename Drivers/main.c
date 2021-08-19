#include "STD_Types.h"
#include "BIT_MATH.h"

#include "DIO_int.h"
#include "LCD_int.h"
#include "KEYPAD_int.h"
#include "util/delay.h"


void main(){

	DIO_vid_init();
	LCD_vid_init();
	KEYPAD_vid_init();

	uint16  flag=0 , NO_flag1 = 0, NO_flag2 = 0, operation, counter = 0, flag_syntax = 0, minus_flag=0, enter_flag=0;
	sint16 first_factor, second_factor, result,temp, ones, tens, hundreds;

	LCD_vid_GoToRowColmun(1,3);

	LCD_vid_WRITE_STRING("Welcome To");

	LCD_vid_GoToRowColmun(2,4);

	LCD_vid_WRITE_STRING("MW CALC");

	_delay_ms(2000);

	LCD_vid_CLEARSCREEN();

while(1){

if(flag_syntax==1 && KEYPAD_uint16_GetStatus()>0){

	LCD_vid_CLEARSCREEN();          		// press any button to remove syntax error sentence
	flag_syntax=0;

	_delay_ms(500);

}else if(flag_syntax==0 && KEYPAD_uint16_GetStatus()>0){

	if(GET_BIT(KEYPAD_uint16_GetStatus() , 0)==1){

	LCD_vid_WRITE_CHARACTER('1');
	_delay_ms(500);

	if(flag == 1){

		if(NO_flag2==0){

		second_factor = 100;

		}else if(NO_flag2==1){

		second_factor= second_factor + 10*1;

		}else if(NO_flag2==2){

		second_factor = second_factor + 1;
		}
	NO_flag2++;
	}else{

		if(NO_flag1==0){

		first_factor = 100;

		}else if(NO_flag1==1){

		first_factor = first_factor + 10*1;

		}else if(NO_flag1==2){

		first_factor = first_factor + 1;
		}
	NO_flag1++;
	}

	}
	else if(GET_BIT(KEYPAD_uint16_GetStatus() , 1)==1){

	LCD_vid_WRITE_CHARACTER('2');
	_delay_ms(500);

	if(flag !=0){

		if(NO_flag2==0){

		second_factor = 200;

		}else if(NO_flag2==1){

		second_factor= second_factor + 10*2;

		}else if(NO_flag2==2){

		second_factor = second_factor + 2;
		}
		NO_flag2++;
	}else if (flag==0){

		if(NO_flag1==0){

		first_factor = 200;

		}else if(NO_flag1==1){

		first_factor = first_factor + 10*2;

		}else if(NO_flag1==2){

		first_factor = first_factor + 1;
		}
		NO_flag1++;
	}
	}
	else if(GET_BIT(KEYPAD_uint16_GetStatus() , 2)==1){

		LCD_vid_WRITE_CHARACTER('3');
		_delay_ms(500);

		if(flag != 0){

			if(NO_flag2==0){

			second_factor = 300;

			}else if(NO_flag2==1){

			second_factor= second_factor + 10*3;

			}else if(NO_flag2==2){

			second_factor = second_factor + 3;
			}
			NO_flag2++;
		}else if(flag == 0){

			if(NO_flag1==0){

			first_factor = 300;

			}else if(NO_flag1==1){

			first_factor = first_factor + 10*3;

			}else if(NO_flag1==2){

			first_factor = first_factor + 3;
			}
		NO_flag1++;
		}
	}
	else if(GET_BIT(KEYPAD_uint16_GetStatus() , 3)==1){

		LCD_vid_WRITE_CHARACTER('+');
		_delay_ms(500);
		operation = '+';
		flag++;
		if(NO_flag1==1){
			first_factor = first_factor/100;
		}else if(NO_flag1==2){

			first_factor = first_factor/10;
		}
	}
	else if(GET_BIT(KEYPAD_uint16_GetStatus() , 4)==1){

		LCD_vid_WRITE_CHARACTER('4');
		_delay_ms(500);

		if(flag != 0){

			if(NO_flag2==0){

			second_factor = 400;

			}else if(NO_flag2==1){

			second_factor= second_factor + 10*4;

			}else if(NO_flag2==2){

			second_factor = second_factor + 4;
			}
			NO_flag2++;
		}else if (flag ==0){

			if(NO_flag1==0){

			first_factor = 400;

			}else if(NO_flag1==1){

			first_factor = first_factor + 10*4;

			}else if(NO_flag1==2){

			first_factor = first_factor + 4;
			}
		NO_flag1++;
		}
	}
	else if(GET_BIT(KEYPAD_uint16_GetStatus() , 5)==1){

		LCD_vid_WRITE_CHARACTER('5');
		_delay_ms(500);

		if(flag !=0){

			if(NO_flag2==0){

			second_factor = 500;

			}else if(NO_flag2==1){

			second_factor= second_factor + 10*5;

			}else if(NO_flag2==2){

			second_factor = second_factor + 5;
			}
			NO_flag2++;
		}else if(flag == 0){

			if(NO_flag1==0){

			first_factor = 500;

			}else if(NO_flag1==1){

			first_factor = first_factor + 10*5;

			}else if(NO_flag1==2){

			first_factor = first_factor + 5;
			}
			NO_flag1++;
		}
	}
	else if(GET_BIT(KEYPAD_uint16_GetStatus() , 6)==1){

		LCD_vid_WRITE_CHARACTER('6');
		_delay_ms(500);

		if(flag != 0){

			if(NO_flag2==0){

			second_factor = 600;

			}else if(NO_flag2==1){

			second_factor= second_factor + 10*6;

			}else if(NO_flag2==2){

			second_factor = second_factor + 6;
			}
			NO_flag2++;
		}else if(flag == 0){

			if(NO_flag1==0){

			first_factor = 600;

			}else if(NO_flag1==1){

			first_factor = first_factor + 10*6;

			}else if(NO_flag1==2){

			first_factor = first_factor + 6;
			}
			NO_flag1++;
		}
	}
	else if(GET_BIT(KEYPAD_uint16_GetStatus() , 7)==1){

			LCD_vid_WRITE_CHARACTER('-');
			_delay_ms(500);

			minus_flag++;               // minus flag of negative operations

			if( (operation=='x') || (operation=='/')){

			continue;

			}


			if(NO_flag1==0){

			enter_flag =1 ;
				continue;        			// continue only in the first time
			}

		flag++;               //it indicates that the second factor will be written

	operation = '-';

	if((NO_flag2==0)){

		if(NO_flag1==1){
			first_factor = first_factor/100;
		}else if(NO_flag1==2){

			first_factor = first_factor/10;
		}
	}
	}else if(GET_BIT(KEYPAD_uint16_GetStatus() , 8)==1){

		LCD_vid_WRITE_CHARACTER('7');
		_delay_ms(500);

		if(flag != 0){

			if(NO_flag2==0){

			second_factor = 700;

			}else if(NO_flag2==1){

			second_factor= second_factor + 10*7;

			}else if(NO_flag2==2){

			second_factor = second_factor + 7;
			}
			NO_flag2++;
		}else if(flag == 0){

			if(NO_flag1==0){

			first_factor = 700;

			}else if(NO_flag1==1){

			first_factor = first_factor + 10*7;

			}else if(NO_flag1==2){

			first_factor = first_factor + 7;
			}
			NO_flag1++;
		}
	}
	else if(GET_BIT(KEYPAD_uint16_GetStatus() , 9)==1){

		LCD_vid_WRITE_CHARACTER('8');
		_delay_ms(500);

		if(flag != 0){

			if(NO_flag2==0){

			second_factor = 800;

			}else if(NO_flag2==1){

			second_factor= second_factor + 10*8;

			}else if(NO_flag2==2){

			second_factor = second_factor + 8;
			}
			NO_flag2++;
		}else if (flag ==0){

			if(NO_flag1==0){

			first_factor = 800;

			}else if(NO_flag1==1){

			first_factor = first_factor + 10*8;

			}else if(NO_flag1==2){

			first_factor = first_factor + 8;
			}
			NO_flag1++;
		}
	}
	else if(GET_BIT(KEYPAD_uint16_GetStatus() , 10)==1){

		LCD_vid_WRITE_CHARACTER('9');
		_delay_ms(500);

		if(flag != 0){

			if(NO_flag2==0){

			second_factor = 900;

			}else if(NO_flag2==1){

			second_factor= second_factor + 10*9;   // applying tens , hundreds, ones method

			}else if(NO_flag2==2){

			second_factor = second_factor + 9;
			}
			NO_flag2++;
		}else if (flag==0){

			if(NO_flag1==0){

			first_factor = 900;

			}else if(NO_flag1==1){

			first_factor = first_factor + 10*9;

			}else if(NO_flag1==2){

			first_factor = first_factor + 9;
			}
		NO_flag1++;
		}
	}
	else if(GET_BIT(KEYPAD_uint16_GetStatus() , 11)==1){

		LCD_vid_WRITE_CHARACTER('x');
		_delay_ms(500);
		flag++;
		operation = 'x';

		if(NO_flag1==1){
			first_factor = first_factor/100;    // modifying the first factor according to its length
		}else if(NO_flag1==2){

			first_factor = first_factor/10;
		}
	}
	else if(GET_BIT(KEYPAD_uint16_GetStatus() , 12)==1){

		LCD_vid_WRITE_CHARACTER('0');
		_delay_ms(500);
	if(flag==0){
		NO_flag1++;
	}else {
		NO_flag2++;
	}

	}
	else if(GET_BIT(KEYPAD_uint16_GetStatus() , 13)==1){
		LCD_vid_CLEARSCREEN();
		NO_flag1=0;
		NO_flag2=0;
		flag = 0;
		counter=0;
		minus_flag=0;
		enter_flag=0;
		first_factor=0;
		second_factor=0;
	}
	else if(GET_BIT(KEYPAD_uint16_GetStatus() , 14)==1){

		LCD_vid_WRITE_CHARACTER('=');
		_delay_ms(500);

	if((flag>1||NO_flag1==0||NO_flag2==0 )&& minus_flag == 0){

		LCD_vid_CLEARSCREEN();

		LCD_vid_GoToRowColmun(1,2);

		LCD_vid_WRITE_STRING("Syntax Error");   // syntax error condition

		LCD_vid_GoToRowColmun(2,2);

		LCD_vid_WRITE_STRING("Press any Key");
		NO_flag1=0;
		NO_flag2=0;
		flag = 0;
		counter=0;
		flag_syntax=1;
		minus_flag=0;
		enter_flag=0;

		continue;
	}

		if(NO_flag2==1){
			second_factor = second_factor/100;
		}else if(NO_flag2==2){

			second_factor = second_factor/10;
		}

		if(operation=='+'){

		if(minus_flag==0){

			result = first_factor + second_factor;}
		else if(minus_flag==1){

			result = -first_factor + second_factor;
		}

		}if(operation=='-'){
			if(minus_flag==2 && flag==1){

			result = -first_factor - second_factor;

			}else if(minus_flag==1 && flag==1){

			result = first_factor - second_factor;
			}

		}else if(operation=='x'){
			if(minus_flag==1){

			result = (-first_factor) *	second_factor;
			}else if(minus_flag==0||minus_flag==2){

			result = first_factor * second_factor;}

		}else if(operation=='/'){
			if(minus_flag==1){

			result = (-first_factor) /	second_factor;
			}
			else if(minus_flag==0||minus_flag==2){
			result = first_factor / second_factor;}
		}

	temp = result;

	while(temp!=0){

		temp = temp / 10;
		counter++;
	}

	if(result==1/0 && (first_factor!=0)&&(second_factor==0)){

			LCD_vid_CLEARSCREEN();

			LCD_vid_GoToRowColmun(1,1);

			LCD_vid_WRITE_STRING("Infinite Value");   // syntax error condition

			LCD_vid_GoToRowColmun(2,1);

			LCD_vid_WRITE_STRING("Press any Key");  // the condition of the result being infinity
			NO_flag1=0;
			NO_flag2=0;
			flag = 0;
			counter=0;
			flag_syntax=1;
			minus_flag=0;
			enter_flag=0;

			continue;
		}

	if((first_factor==0)&&(second_factor==0)){

				LCD_vid_CLEARSCREEN();

				LCD_vid_GoToRowColmun(1,0);

				LCD_vid_WRITE_STRING("Undefined Value");   // syntax error condition

				LCD_vid_GoToRowColmun(2,1);

				LCD_vid_WRITE_STRING("Press any Key");  // the condition of the result being undefined Value
				NO_flag1=0;
				NO_flag2=0;
				flag = 0;
				counter=0;
				flag_syntax=1;
				minus_flag=0;
				enter_flag=0;
				continue;
			}

	if(result<0){

		result = result*(-1);
		LCD_vid_WRITE_CHARACTER('-');  // if NO is Negative
	}


	if(counter>3){

			LCD_vid_CLEARSCREEN();

			LCD_vid_GoToRowColmun(1,2);

			LCD_vid_WRITE_STRING("Syntax Error");   // syntax error condition

			LCD_vid_GoToRowColmun(2,2);

			LCD_vid_WRITE_STRING("Press any Key");  // the condition of the result digits being more than 3 digits
			NO_flag1=0;
			NO_flag2=0;
			flag = 0;
			counter=0;
			flag_syntax=1;
			minus_flag=0;
			enter_flag=0;
			continue;
		}

if(counter==3){
	hundreds = result/100;

	LCD_vid_WRITE_CHARACTER(hundreds+'0');

	tens = result/10 - hundreds *10;

	LCD_vid_WRITE_CHARACTER(tens+'0');

	temp = result/10;

	ones= result - temp*10;

	LCD_vid_WRITE_CHARACTER(ones+'0');

}else if(counter==2){

	tens = result/10;
	LCD_vid_WRITE_CHARACTER(tens+'0');

	ones = result - tens*10;
	LCD_vid_WRITE_CHARACTER(ones+'0');   // positive NO

}else if(counter==1||result==0){

	LCD_vid_WRITE_CHARACTER(result+'0');
}

	NO_flag1=0;
	NO_flag2=0;
	flag = 0;
	counter=0;
	minus_flag=0;
	enter_flag=0;
	first_factor=0;
	second_factor=0;
	}
	else if(GET_BIT(KEYPAD_uint16_GetStatus() , 15)==1){
		LCD_vid_WRITE_CHARACTER(0b11111101);   // prints division char
		_delay_ms(500);
		operation = '/' ;
		flag++;

		if(NO_flag1==1){
			first_factor = first_factor/100;
		}else if(NO_flag1==2){

			first_factor = first_factor/10;
		}
	}

}

}

}
