/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>

int getTenPower(int num);//Function to find the closest power of 10 less than the number

int power(int num, int pow);//Function to find the power of a number

void number_to_str(float number, char *str, int afterdecimal){

	int strInd = 0, temp;

	int intPart = (int)number;
	float floatPart;
	
	char c;

	//If number is negative, add '-' in the string.
	if (number<0){

		str[strInd++] = '-';
		intPart *= -1;

		floatPart = -1 * (number + (int)intPart);

		}
	else{
		floatPart= number - (int)intPart;
		}


	int ten_power = getTenPower(intPart);


	while (ten_power > 0){

		temp = intPart / ten_power;

		c = temp + '0';

		str[strInd] = c;
		strInd++;

		intPart = intPart % ten_power;
		ten_power /= 10;

		}

	
	if (afterdecimal == 0){

		str[strInd] = '\0';
		return;
		}
	else if (afterdecimal>0){//If value after . has to be added to the string

		str[strInd++] = '.';

		ten_power = power(10, afterdecimal);

		int floatP = (floatPart)*ten_power;

		ten_power /= 10;

		while (ten_power > 0){

			temp = floatP / ten_power;

			c = temp + '0';

			str[strInd] = c;
			strInd++;

			floatP = floatP % ten_power;
			ten_power /= 10;

			}



		str[strInd] = '\0';
		return;
		}

	}

int getTenPower(int num){



	int i = 1;
	while ((i * 10) < num)
		i *= 10;

	return i;
	}


int power(int num, int pow){

	int i, res = 1;

	for (i = 0; i < pow; i++){
		res *= num;
		}

	return res;

	}