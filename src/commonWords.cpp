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

int a(char** s1, char* str1){
	//	char *str1 = "the are all is well";

	int p1 = 0;
	int i, start = 0;
	for (i = 0; str1[i] != '\0'; i++){
		while (i == 0 && str1[i] == ' '){
			i++;
			start = i;
		}
		if (str1[i] == '\0')
			return 0;
		if (str1[i] == ' '){
			int k, j;
			char* s = (char*)malloc(sizeof(char)*(i - start + 1));
			int m = 0;
			for (j = start; j < i; j++){
				s[m++] = str1[j];
			}
			s[m] = '\0';
			printf("s = %s\n", s);
			s1[p1++] = s;
			start = i + 1;
		}
	}
	int j, k;
	char* s = (char*)malloc(sizeof(char)*(i - start + 1));
	int m = 0;
	for (j = start; j < i; j++){
		s[m++] = str1[j];
	}
	s[m] = '\0';
	printf("s = %s\n", s);
	s1[p1] = s;
	return p1 + 1;
}

int length(char* str){
	int i = 0;
	for (i = 0; str[i] != '\0'; i++);
	return i;
}

int com(char* str1, char* str2){
	int l1 = length(str1);
	int l2 = length(str2);
	if (l1 == l2){
		for (int i = 0; i < l1; i++){
			if (str1[i] != str2[i]){
				return -1;
			}
		}
		return 0;
	}
	else{
		return -1;
	}
}

char ** commonWords(char *str1, char *str2) {
	if (str1 != NULL && str2 != NULL){
		char **s1;
		s1 = (char**)malloc(sizeof(char*) * 5);
		for (int i = 0; i < 5; i++){
			s1[i] = (char*)malloc(sizeof(char) * 31);
		}
		char **s2;
		s2 = (char**)malloc(sizeof(char*) * 5);
		for (int i = 0; i < 5; i++){
			s2[i] = (char*)malloc(sizeof(char) * 31);
		}
		char **s;
		s = (char**)malloc(sizeof(char*) * 5);
		for (int i = 0; i < 5; i++){
			s[i] = (char*)malloc(sizeof(char) * 31);
		}
		int p = 0;
		int l1 = a(s1, str1);
		int l2 = a(s2, str2);
		for (int i = 0; i < l1; i++){
			for (int j = 0; j < l2; j++){
				if (com(s1[i], s2[j]) == 0){
					s[p++] = s1[i];
				}
			}
		}
		if (p == 0){
			return NULL;
		}
		return s;
	}
	return NULL;
 }