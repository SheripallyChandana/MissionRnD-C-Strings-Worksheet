/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void reverseString(char* left, char* right){
	
	char temp;
	
	while(left < right){
		temp     = *left;
		*left++  = *right;
		*right-- = temp;			
	}
}
void str_words_in_rev(char *input, int len){
		
	char* begin = input;
	char* temp  = input;

	while(*temp){
		temp++;
		if(*temp == '\0')
			reverseString(begin, temp - 1);
		else if(*temp == ' '){
			reverseString(begin, temp - 1);
			begin = temp + 1;
		}
	}		
	reverseString(input, temp - 1);				
}	

