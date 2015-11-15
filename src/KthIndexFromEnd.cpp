/*
OVERVIEW: Given a string, return the Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
#include<stdio.h>

char KthIndexFromEnd(char *str, int K) {


	if (str == NULL || str[0] == '\0' || K < 0)
		return '\0';
	
	int length;
	for(length = 0; str[length] != '\0'; ++length);
	
	if(length >= K)
		return str[length - K - 1];		
	return '\0';
}