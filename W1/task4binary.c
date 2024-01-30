// (C) Lucas Holter, Cornelia Olofsson, Rizwan Rafiq, group: 18 (2024)
// Work package 1
// Exercise 4a
// Submission code: 125455

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


    unsigned int bitsValue = 0; //Initialize variable used to find most significant bit

    // Calculate the minimum number of bits needed
    unsigned int tempValue = input; // temporary variable declaration to count the minimum bits required value
    while (tempValue > 0) {         // While loop to count the minimum bits required value
        bitsValue++;                // while loop increment
        tempValue >>= 1;            // right shift to find MSB and right shifting the value untill value is zero
    }

    //printf("bits value for %d is: %u \n", input,bitsValue);

/*    https://www.scaler.com/topics/ceil-function-in-c/ *ceil function reference which requires double data type
    Round up to the nearest byte (8, 16, 24, 32, etc.) */
    int bytesNeeded = (bitsValue + 7) / 8; // Add 7 and integer divide by 8 (alternative to ceil math function)
    int bitsToMask = bytesNeeded * 8;       //bitsMask factor to use for Bitwise Operation in for-loop

    //printf("bytes needed: %d - bitsToMask: %d\n", bytesNeeded, bitsToMask);

    // Set the displayMask based on bitsToDisplay
    unsigned int displayMask = 1 << (bitsToMask - 1);   // Dynamic Bitmask value based on counted MSB position
    // calculated by finding upper bound ( multiple of 8)

    // Loop through the bits to display
    for (int c = 1; c <= bitsToMask; ++c) {             // for-loop to perform bitwise operation
        putchar(input & displayMask ? '1' : '0');       // prints 1's or 0's based on bitwise AND operation
        displayMask >>= 1;                              // between bitMask and input value
    }                                                   // bits can be printed by either right shifting bitMask value
}                                                       // or left shifting input-value and performing AND operation
