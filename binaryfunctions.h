#define MAX 255
#define MIN 0
#define TRUE 1
#define FALSE 0

#define KNRM  "\x1B[0m" //RESET COLOR
#define KRED  "\x1B[31m" //RED COLOR
#define LINE_CLEAR "\033[K"

enum int_types {
	DECIMAL,
	HEXIDECIMAL,
	BINARY
};

enum signed_types {
	UNSIGNED, // 0
	SIGNED    // 1
};

void print_binary(unsigned int);
void read_binary(int *, int);