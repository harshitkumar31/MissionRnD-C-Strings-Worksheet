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

int findStr(char *pattern, char *string);
void copyStr(char *src, char *dest);
int getLength(char *str,int *wordCount);



char ** commonWords(char *str1, char *str2) {

	
	if (str1 == 0 || str2 == 0)
		return NULL;
	
	char **wordsStr1;
	char **wordsStr2;



	int len1, len2, wordCount1 = 0, wordCount2 = 0;
	len1 = getLength(str1, &wordCount1);
	len2 = getLength(str2, &wordCount2);

	wordsStr1 = (char**)malloc(wordCount1* sizeof(char*));
	wordsStr2 = (char**)malloc(wordCount1* sizeof(char*));

	int i, j = 0, k = 0;
	for (i = 0; i < wordCount1; i++){
		wordsStr1[i] = (char*)malloc(31*sizeof(char));
		wordsStr2[i] = (char*)malloc(31*sizeof(char));
		wordsStr2[i][0] = '\0';
		}

	int boolFlag = 0;

	for (i = 0, j = 0; str1[i] != '\0' && j<wordCount1; i++){
		if (str1[i] != ' '){
			wordsStr1[j][k] = str1[i];
			k++;
			}
		else if (str1[i] == ' '){
			wordsStr1[j][k] = '\0';
			j++;
			k = 0;
			}
		}

	wordsStr1[j][k] = '\0';

	int commonWordsCount = 0;
	j=0;


	for (i = 0; i < wordCount1; i++){

		boolFlag = findStr(wordsStr1[i], str2);

		if (boolFlag){
			copyStr(wordsStr1[i], wordsStr2[j]);
			j++;
			commonWordsCount++;
			}
		}
		

	if (commonWordsCount > 0)
		return wordsStr2;
	else{
		return NULL;

		}

	}

int getLength(char *str, int *count){

	int i = 0;
	*count = 1;

	while (str[i] != '\0'){

		if (str[i] == ' ' )
			*count = *count + 1;

		i++;
		}

	return i;

	}


int findStr(char *pattern, char *string){

	int count1=0, count2=0;

	while (pattern[count1] != '\0')
		count1++;

	while (string[count2] != '\0')
		count2++;


	int flag = 0;

	int i, j,k;

	for (i = 0; i <= count2 - count1; i++){


		for (j = i; j < i + count1; j++){
			
			flag = 1;
			k = j - i;
			if (string[j] != pattern[k]){
				flag = 0;
				break;
				}

			}

		if (flag == 1)
			return 1;
		}

	return 0;
	}


void copyStr(char *src, char *dest){

	int i = 0;

	for (i; src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	}
