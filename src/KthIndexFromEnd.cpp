/*
OVERVIEW: Given a string, return the letter at Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the letter at Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/

int l(char* str){
	int i = 0;
	for (i = 0; str[i] != '\0'; i++);
	return i;
}

char KthIndexFromEnd(char *str, int K) {
	if ((str != "") && (str != '\0') && (K >= 0)){
		int len = l(str);
		if (len <= K){
			return '\0';
		}
		else{
			return str[len - K - 1];
		}
	}
	return '\0';
}