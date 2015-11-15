/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>

#define SIZE 31


int stringLength(char* array, int* wordCount){
	
	int length;
	for(length = 0; array[length] != '\0'; ++length)
		if(array[length] == ' ')
			(*wordCount)++;
	(*wordCount)++;
	return length;
}

void computeLPSArray(char *pat, int M, int *longestPrefixSuffix){
	int len = 0;
	int i;

	longestPrefixSuffix[0] = 0;
	i = 1;

	while (i < M)
		if (pat[i] == pat[len]){
			len++;
			longestPrefixSuffix[i] = len;
			i++;
		}
		else{
			if (len != 0)
				len = longestPrefixSuffix[len-1];			
			else{
				longestPrefixSuffix[i] = 0;
				i++;
			}
		}	
}

int KMPSearch(char *pat, char *txt, int M, int N){

	int *longestPrefixSuffix = (int*)malloc(sizeof(int) * M);
	int patIndex = 0; 

	computeLPSArray(pat, M, longestPrefixSuffix);

	int txtIndex = 0;
	
	while (txtIndex < N){
			
		if (pat[patIndex] == txt[txtIndex]){
			patIndex++;
			txtIndex++;
		}

		if (patIndex == M){
			return txtIndex - patIndex;
			patIndex = longestPrefixSuffix[patIndex - 1];
		}

		else if (txtIndex < N && pat[patIndex] != txt[txtIndex]){

			if (patIndex != 0)
			patIndex = longestPrefixSuffix[patIndex - 1];
			else
			txtIndex = txtIndex + 1;
		}
	}
	return -1;
}

void stringCopy(char* string1, char* string2, int len){

	int index = 0;
	while (len){
		string2[index] = string1[index];
		index++;
		len--;
	}
	string2[index] = '\0';
}

char ** commonWords(char *str1, char *str2) {

	if(str1 == NULL || str2 == NULL || str1[0] == '\0' || str2[0] == '\0')
		return NULL;

	int wordCount = 0;
	int len2 = stringLength(str2, &wordCount);
	
	char** words = (char**)calloc(wordCount, sizeof(char*));
	
	int wordIndex = 0;
	int index = 0;
	int begin = 0;

	while (1){
		
		if((str1[index] == ' ' && str1[index-1] != ' ') || str1[index] == '\0'){

			while(str1[begin] == ' ')
				begin++;
			if (index - begin < 1){
				index++;
				continue;
			}
			int position = KMPSearch(&str1[begin], str2, index - begin, len2);
			
			if(position != -1){
				words[wordIndex] = (char*)calloc(20, sizeof(char));
				stringCopy(&str2[position], &words[wordIndex][0], index - begin);
				wordIndex++;
			}
			begin = index+1;		
		}
		if(str1[index] == '\0')
			break;
		index++;				
	}
	
	if (wordIndex == 0)
		return NULL;
	for (int index = 0; index < wordIndex; ++index){
		printf("\n");
		for (int i = 0; words[index][i] != '\0'; ++i)
			printf("%c", words[index][i]);
	}

	return words;
}
