/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void rev(char* str, int l, int r){
	int i, j;
	for (i = l, j = r - 1; i < j; i++, j--){
		char ch = str[i];
		str[i] = str[j];
		str[j] = ch;
	}
}

void str_words_in_rev(char *input, int len){
	int i = 0, start = 0, end;
	for (i = 0; input[i] != '\0'; i++){
		if (input[i] == ' '){
			end = i;
			rev(input, start, end);
			while (input[i+1] == ' '){
				i++;
			}
			start = i + 1;
		}
	}
	rev(input, start, i);
	rev(input, 0, i);
}
