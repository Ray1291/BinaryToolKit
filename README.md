BinaryToolKit

A program to run in Linux CLI to test your skills converting decimal, binary or hexidecimal. This program relies only on standard C library features

This project consists of the following C source files:
- main.c
- input_parser.c
- binary_functions.c
- question_prompter.c

# Features:
Converts numbers between binary, decimal, and hexidecimal
User-Friendly command-line interface
Error checking for invalid inputs

# Installation:
Clone the repo
` git clone https://github.com/Ray1291/BinaryToolKit`
Navigate to the directory
` cd "YOUR_DIRECTORY"`
compile the program
` gcc input_parser.c question_prompter.c binaryfunctions.c main.c -o run.out `
Run it
` ./run.out`

# Usage

The program will first prompt you to to config the mode you want to play

```Enter Config:```

The proper order of items into for it to run is:
<SIGN> from <BASE> to <BASE> <# questions>

SIGN = signed or unsigned
BASE = binary, hexidecimal, or decimal
\# Questions = optional number of questions to ask before quiting (Default: 5)