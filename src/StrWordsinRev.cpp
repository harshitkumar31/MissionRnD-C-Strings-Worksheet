/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void reverseWord(char *inp, int st, int end);

void str_words_in_rev(char *input, int len){
	int i ,j;
	int count = 0;

	char temp;

	for (i = 0, j = len - 1; i < j; i++, j--){

		temp = input[i];
		input[i] = input[j];
		input[j] = temp;
		}

	for (i = 0, j = 0; i <= j && input[j]!='\0';){

		if (input[j] != ' '){
			j++;
			}
		else{
			count++;
			reverseWord(input, i, j-1);
			j++;

			i = j;
			}
		}

	

	if (count == 0){
		reverseWord(input, 0, len - 1);
		return;
		}

	reverseWord(input, i, j - 1);
	
}

void reverseWord(char *inp, int st, int end){

	char temp;
	while (st < end){

		temp = inp[st];
		inp[st] = inp[end];
		inp[end] = temp;

		st++;
		end--;
		}
	return;
	}