#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "binaryfunctions.h"

void printusage();
void string_tolower(char *);
char* next_token(char [], char **);
int input_parser(int *, int *, int *, int *);

void print_usage(){
        printf("--------------------------------------------------\n");
        printf("|           Binary Pratice V1.0 (2025)           |\n");
        printf("| (1) Signed or Unsigned                         |\n");
        printf("| (2) From: Binary, Hexi, Deci                   |\n");
        printf("| (3) To: Binary, Hexi, Deci                     |\n");
		printf("| (4) x num of questions, default: 5             |\n");
        printf("--------------------------------------------------\n\n");
}

void string_tolower(char *string){
	while(*string){
		*string = tolower((unsigned char)*string);
		string++;
	}

}

char* next_token(char input_string[], char **last_input){
	char *tok;

	if(input_string != NULL && input_string != *last_input){
		*last_input = input_string;
		tok = strtok(input_string, " ");
	}
	else{
		tok = strtok(NULL, " ");
	}
	
	if(tok == NULL) {
		return NULL;
	}

	string_tolower(tok);
	//printf("%s\n", tok);
	return tok;
}

int input_parser(int *from, int *to, int *sign, int *questions_to_ask){
	print_usage();

	int input_good = FALSE;

	char input_string[256] = {};
	printf("Enter config: ");
	fgets(input_string, sizeof(input_string), stdin);
	input_string[strcspn(input_string, "\n")] = 0;

	char *last_input = NULL;
	char *tok = next_token(input_string, &last_input);

	if(tok == NULL){
		input_good = FALSE;
		printf("MISSING [FROM] KEYWORD (NULL)\n");
		return TRUE;
	}

	/*--------------*/
	/* SIGN KEYWORD */
	/*--------------*/

	if(strcmp(tok, "signed") != 0 && strcmp(tok, "unsigned") != 0){
		input_good = FALSE;
		printf("MISSING SIGN DECLARATION\n");
		return TRUE;
	}

	if(strcmp(tok, "signed") == 0){
		*sign = SIGNED;
	}
	else{
		*sign = UNSIGNED;
	}

	tok = next_token(input_string, &last_input);

	if(tok == NULL){
		input_good = FALSE;
		printf("MISSING [FROM] KEYWORD (NULL)\n");
		return TRUE;
	}

	/*--------------*/
	/* FROM KEYWORD */
	/*--------------*/

	if(strcmp(tok, "from") != 0){
		input_good = FALSE;
		printf("MISSING [FROM] KEYWORD\n");
		return TRUE;
	}

	tok = next_token(input_string, &last_input);

	if (tok == NULL) {
		input_good = FALSE;
		printf("Unexpected end of input [FROM]\n");
		return TRUE;
	}
	
	if(strcmp(tok, "binary") == 0){
		*from = BINARY;
	}
	else if(strcmp(tok, "hexi") == 0){
		*from = HEXIDECIMAL;
	}
	else if(strcmp(tok, "deci") == 0){
		*from = DECIMAL;
	}
	else{
		input_good = FALSE;
		printf("TYPE NOT SPECIFIED\n");
		return TRUE;
	}

	tok = next_token(input_string, &last_input);
	
	if (tok == NULL) {
		input_good = FALSE;
		printf("Unexpected end of input [TO] (NULL)\n");
		return TRUE;
	}

	/*------------*/
	/* TO KEYWORD */
	/*------------*/

	if(strcmp(tok, "to") != 0){
		input_good = FALSE;
		printf("MISSING [TO] KEYWORD\n");
		return TRUE;
	}

	tok = next_token(input_string, &last_input);

	if (tok == NULL) {
		input_good = FALSE;
		printf("Unexpected end of input [TO]\n");
	}

	if(strcmp(tok, "binary") == 0){
		*to = BINARY;
	}
	else if(strcmp(tok, "hexi") == 0){
		*to = HEXIDECIMAL;
	}
	else if(strcmp(tok, "deci") == 0){
		*to = DECIMAL;
	}
	else{
		input_good = FALSE;
		printf("TYPE NOT SPECIFIED\n");
		return FALSE;

	}

	tok = next_token(input_string, &last_input); //to get num of questions to ask

	if (tok == NULL) {
		input_good = TRUE;
		printf("optional num not found\n");
	}
	else{
		input_good = TRUE;

		*questions_to_ask = atoi(tok);
	}

	input_good = TRUE;

	return FALSE;
}
