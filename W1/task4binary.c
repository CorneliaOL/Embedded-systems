

/*Directives for defining identifiers from standard libraries*/
#include <ctype.h>  /* preprocessor directive: includes validation function */
#include <stdlib.h> /* preprocessor directive: includes functions library*/
#include <limits.h> /*preprocessor directive: includes sizeof function from library*/
#include <stdio.h>  /* preprocessor directive: includes Standard I/O library*/
#include <string.h> /* preprocessor directive: includes functions*/

void displayBits(unsigned int value); // prototype

// Function to check if a string represents a valid unsigned integer
int isValidUnsignedInt(const char *str) {   //checks the validity of user input, returns 1 if all are digits
    while (*str) {
        if (!isdigit((unsigned char)*str)) { //if-flase condition , in case of any other char than digits
            return 0;  // Return false (0) if a non-digit character is found
        }
        str++;         // increment to while statement
    }
    return 1;  // Return true (1) if only digit characters are found
}

// Main function in the program, program arguments supported
int main(int argc, char *argv[]) {      /* Start of - main function*/

    const char *targetString = "-h";        /* Variable initial: '-h' as string value to show help message */

    if (argc == 2) {    /* condition: there is exactly one name argument*/

        if (isValidUnsignedInt(argv[1])) {     //implements validity check, and accepts input if all are digits
            unsigned int x = atoi(argv[1]);        // user input: with casting it from string to unsigned integer
            displayBits(x);                  // function call by using user input as argument
        } else if(strcmp(argv[1], targetString) == 0){  //returns the message if user input matches '-h'
            printf("Help message - Please enter program name (space) valid decimal digits");
        } else {                                    //returns message in case of invalid user input
            printf("Error: Invalid input: Please enter a valid unsigned integer.\n");
            return 0;                               //returns 1 in se of invalid user input
        }               // end of nested if statement

    } else {            // else block for No arguments

        printf("Error: Empty argument - field can not be empty, please enter valid input integer.\n");
        return 0;       // ends the program with return value 1

    }
    return 0;                   /* returns control to the OS with integar value 0 in case of normal execution  */
}                               /* End of - main function*/



void displayBits(unsigned int input) {


    int bitsValue = 0;

    // Calculate the minimum number of bits needed
    unsigned int tempValue = input;
    while (tempValue > 0) {
        bitsValue++;
        tempValue >>= 1;
    }

    // Round up to the nearest byte (8, 16, 24, 32, etc.)
    int bytesNeeded = (bitsValue + 7) / 8; // Add 7 and integer divide by 8
    int bitsToMask = bytesNeeded * 8;

    // Set the displayMask based on bitsToDisplay
    unsigned int displayMask = 1 << (bitsToMask - 1);

    // Loop through the bits to display
    for (int c = 1; c <= bitsToMask; ++c) {
        putchar(input & displayMask ? '1' : '0');
        displayMask >>= 1;
    }
}
