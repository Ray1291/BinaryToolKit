#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "binaryfunctions.h"

int question_prompter(int, int, int, int, int);

int question_prompter(int convert_from, int convert_to, int sign, int chances, int question_number){
	srand(time(0));
	int random_num = rand() % 255;
	int guess = -1;

    printf("CONFIG: CT: %d CT: %d SIGN: %d Q#s: %d\n", convert_from, convert_to, sign, question_number);

	while(chances > 0){
	
		printf("(%d) What is: ", question_number);
		switch(convert_from){
			case BINARY:
				print_binary(random_num);
				break;
			case HEXIDECIMAL:
				printf("[%2x] ", random_num);
				break;
			case DECIMAL:
				printf("[%d] ", random_num);
				break;
			default:
				printf("convert_from_error");
				break;
		}

		printf(" in");

		switch(convert_to){
			case BINARY:
				printf(" binary");
				if(sign == SIGNED){
                    printf(" (SIGNED)\nAnswer: ");
					signed int result = 0;
					read_binary(&result, sign);
					guess = result;
				}
				else{
                    printf(" (UNSIGNED)\nAnswer: ");
					unsigned int result = 0;
					read_binary(&result, sign);
					guess = result;
				}
				break;
			case HEXIDECIMAL:
            	printf(" hexidecimal ");
                if(sign == SIGNED){
                    printf(" (SIGNED)\nAnswer: ");
                }
                else{
                    printf("(UNSIGNED)\nAnswer: ");      
                }
				scanf("%200x", &guess);
				break;
			case DECIMAL:
				printf(" decimal ");
                if(sign == SIGNED){
                    printf("(SIGNED)\nAnswer: ");
                }
                else{
                    printf("(UNSIGNED)\nAnswer: ");      
                }
				scanf("%d", &guess);
				break;
			default:
				printf("convert_to_error");
		}

		if(guess == random_num){
			printf("\n-----------\n");
			printf("|-CORRECT-|\n");
			printf("-----------\n");
			return TRUE;
		}
		else{
			printf("\n-----------\n");
			printf("|--WRONG--|\n");
			printf("-----------\n");
			chances--;

			printf("\n --Answers left: %d--\n", chances);
		}
	}
	return 0;
}