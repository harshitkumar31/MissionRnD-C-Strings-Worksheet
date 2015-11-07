/*
OVERVIEW: Given a string, return the Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/

char KthIndexFromEnd(char *str, int K) {

	if(  str==0 || str == "" || K<0 )
		return '\0';

	int i = 0, nextInd = 1;

	//To find end of string  using two loops
	while (str[i] != '\0'){
		
		i += nextInd;
		nextInd *= 2;
		}
	
	nextInd = 1;
	while (str[i] == '\0'){
		
		i -= 1;// nextInd;
		//nextInd *= 2;
		}

	return str[i - K];

}