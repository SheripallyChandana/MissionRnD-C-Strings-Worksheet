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

int power(int base, int exp){
	
    int result = 1;
	
	while(exp){
		if(exp & 1)
			result *= base;
		exp >>= 1;
		base *= base;
	}
    return result;
}

void reverseString(char* array, int length){
	
	int left = 0;
	int right = length - 1;
	int temp;
	
	while(left < right){
		
		temp = array[left];
		array[left++] = array[right];
		array[right--] = temp;
	}
}

int convertIntegerToCharacterArray(int number, char *array, int afterDecimal){

	int index = 0;
	int negFlag = 0;
	
	if(number < 0){
		negFlag = 1;
		number *= -1;
	}
	
	while(number){
		
		array[index++] = (number % 10) + 48;
		number /= 10;
	}

	if(negFlag == 1)
		array[index++] = '-';
		
	while(index < afterDecimal)
		array[index++] = '0';
	
	reverseString(array, index);
	array[index] = '\0';
	
    return index;
}

void number_to_str(float number, char *str,int afterdecimal){

	int integer = (int)number;
	float decimal = number - (float)integer;	
	
	if(decimal < 0)
		decimal *= -1;
	
	printf("\n%f\n", decimal);
	int index = convertIntegerToCharacterArray(integer, str, 0);	

	if(afterdecimal > 0){
		str[index] = '.';
		decimal = decimal * power(10, afterdecimal);
		convertIntegerToCharacterArray((int)decimal, str + index + 1, afterdecimal);
	}		
}
