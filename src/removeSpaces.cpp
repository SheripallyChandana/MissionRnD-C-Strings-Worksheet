/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/
#include<stdio.h>

char removeSpaces(char *str) {
	if (str == NULL || str[0] == '\0')
		return '\0';

	int index = 0;
	int newIndex = 0;
	
	while(str[index] != '\0'){
		if(str[index] == ' ');
		else
			str[newIndex++] = str[index];
		index++;
	}
			
	str[newIndex] = '\0';	
	return 'a';	
}