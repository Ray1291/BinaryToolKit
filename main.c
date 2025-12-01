#include <stdio.h>

#include "binaryfunctions.h"
#include "input_parser.h"
#include "question_prompter.h"

typedef int bool;

int main(){
	bool config = TRUE;
	int convert_from = -1;
	int convert_to = -1;
	int is_signed = -1;
	int num_chances = 5;
	int num_questions_to_ask = 5;


	while(config == TRUE){
		config = input_parser(&convert_from, &convert_to, &is_signed, &num_questions_to_ask);
		printf("\n");
	}

	printf("CONFIG: CT: %d CT: %d SIGN: %d Qs: %d\n", convert_from, convert_to, is_signed, num_questions_to_ask);

	int result = TRUE;
	int question_number = 1;
	
	while(result == TRUE && num_questions_to_ask > 0){
		result = question_prompter(convert_from, convert_to, is_signed, num_questions_to_ask, question_number);
		num_questions_to_ask--;
		question_number++;
	}
}