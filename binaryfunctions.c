#include <stdio.h>
#include <time.h>
#include <string.h>
#include "binaryfunctions.h"

void print_binary(unsigned int);
void read_binary(int *, int);

void print_binary(unsigned int bit_string){
	for(int i = 7; i >= 0; i--){
		printf("%d", (bit_string >> i) & 1);
	}
}

void read_binary(int *result, int sign){
	char bit_string[8];
	scanf("%s", bit_string);
	int length = strlen(bit_string);

	int n = 0;

	if(sign == SIGNED){
		for(int i = length - 1; i >= 0; i--){
			if(bit_string[i] == '0'){
				n++; //increment power
			}
			else{
				*result += 1 << n;
				n++;
			}

			printf("%c * 2^%d = %d\n", bit_string[i], n, *result);
		}
	}
	else{
		for(int i = length - 1; i >= 0; i--){
			if(bit_string[i] == '0'){
				n++; //increment power
			}
			else{
				*result += 1 << n;
				n++;
			}

			printf("%c * 2^%d = %d\n", bit_string[i], n, *result);
		}
	}
}