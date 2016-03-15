/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/


char removeSpaces(char *str) {
	if ((str != "") && (str != '\0')){
		int i = 0, j, start, end, k;
		for (i = 0; str[i] != '\0'; i++){
			
			if (str[i] == ' '){
				start = i;
				for (j = i + 1; str[j] == ' ' && str[j] != '\0'; j++);
				if (str[j] == '\0'){
					str[start] = '\0';
				}
				else{
					end = j;
					for (k = start; str[end] != '\0'; k++, end++){
						str[k] = str[end];
					}
					str[k] = '\0';
				}
			}
		}
		
	}
	return '\0';
}