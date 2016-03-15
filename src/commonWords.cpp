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

char ** commonWords(char *str1, char *str2) {
	int i,j,k,l,n=-1,m=0;
	char** output;
	output = (char**)malloc(sizeof(char*) * 5);
	for (int y = 0; y < 5; y++){
		output[y] = (char*)malloc(sizeof(char) * 31);
	}
	if (str1 != '\0'&&str2 != '\0'){
		for (i = 0; str1[i] != '\0'; i++){
			for (j = 0; str2[j] != '\0'; j++){
				if (str1[i] == ' '){
					break;
				}
				if (str1[i] == str2[j]){
					for (k = i + 1, l = j + 1; (str1[k] == ' ' && str2[l] == '\0') || (str1[k] == str2[l]) || (str1[k] == '\0' && str2[l] == ' '); k++, l++){
						n++;
						m = 0;
						for (int z = i; z < k; z++, m++){
							output[n][m] = str1[z];
						}
					}
				}
			}
		}
		return output;
	}
	return NULL;

}