/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>

void reverse(char* str,int start,int len){
	int i,j;
	for (i = start, j = len - 1; i < j; i++, j--){
		char ch = str[i];
		str[i] = str[j];
		str[j] = ch;
	}
}

void convert1(int value, char* str,int start){
	int i = start;
	while (value > 0){
		str[i++] = (value % 10) + '0';
		value = value / 10;
	}
	reverse(str, start, i);
	str[i] = '\0';
}

void convert2(int val1, int val2, char* str, int start){
	int i = start;
	while (val1 > 0){
		str[i++] = (val1 % 10) + '0';
		val1 = val1 / 10;
	}
	reverse(str, start, i);
	str[i] = '.';
	start = i + 1;
	i = i + 1;
	while (val2 > 0){
		str[i++] = (val2 % 10) + '0';
		val2 = val2 / 10;
	}
	reverse(str, start, i);
	str[i] = '\0';
}

void number_to_str(float number, char *str,int afterdecimal){
	if (afterdecimal == 0){
		int value = (int)number;
		if (number > 0){
			convert1(value, str,0);
		}
		else{
			str[0] = '-';
			value *= -1;
			convert1(value, str, 1);
		}
	}
	else{
		int ival = (int)number;
		float temp = number - ival;
		int temp1 = afterdecimal;
		while (temp1 > 0){
			temp *= 10;
			temp1--;
		}
		int fval = (int)temp;
		if (number > 0){
			convert2(ival, fval, str,0);
		}
		else{
			ival = ival * -1;
			fval = fval * -1;
			str[0] = '-';
			convert2(ival, fval, str, 1);
		}
	}
}
