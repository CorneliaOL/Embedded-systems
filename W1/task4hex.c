/*Directives for defining identifiers from standard libraries*/

#include <stdio.h>      /* preprocessor directive: includes Standard I/O library*/
#include <ctype.h>      /* preprocessor directive: includes validation function */
#include <stdlib.h>     /* preprocessor directive: includes functions library*/
#include <string.h>     /* preprocessor directive: includes functions*/


void binaryToHex(unsigned long long int value); // function prototype
int isValidUnsignedInt(const char *str); // function prototype


int main(int argc, char *argv[]) {  //start of main function

    const char *targetString = "-h";        // Variable initial: '-h' as string value to show help message
    char binaryString[9]; // String to store binary input


    if( argc != 2 ){

        scanf("%s", binaryString); // Read binary string

        if(isValidUnsignedInt(binaryString)){
            unsigned long long int binValue = strtoull(binaryString, NULL, 2); // Convert string to number
            binaryToHex(binValue);

        } else {

            printf("Error: Invalid input: Please enter valid binary digits.\n");
            return 0;                               //returns 1 in se of invalid user input
        }


    } else {

        if(isValidUnsignedInt(argv[1])){                // if-block to check the validity of input i.e. only digits allowed

            unsigned long long int binValue = strtoull(argv[1], NULL, 2); // Convert string to number

            binaryToHex(binValue);                  // function call by passing user input as argument

        } else if(strcmp(argv[1], targetString) == 0){    // else-if-Block to check argument for string 'h'

            printf("Help message - Please enter program name (space) valid decimal digits");
            return 0;                                               // exist program with return value 0

        } else {                                    //returns message in case of invalid user input
            printf("Error: Invalid input: Please enter valid binary digits.\n");
            return 0;                               //returns 1 in se of invalid user input
        }               // end of nested if statement

    }
    return 0;           // returns control to the OS with integar value 0 in case of normal execution
}                       // End of - main function

//Function to convert from binary to hex value with binary value as input argument
void binaryToHex(unsigned long long int value) {


    unsigned int bitsValue = 0;     // variable declaration to calculate MSB (most significant bit)

    // Calculate the minimum number of bits needed
    unsigned int tempValue = value; // temporary variable declaration to count the minimum bits required value
    while (tempValue > 0) {         // While loop to count the minimum bits required value
        bitsValue++;                // while loop increment
        tempValue >>= 1;            // right shift to find MSB and right shifting the value untill value is zero
    }


    int bytesNeeded = (bitsValue + 7) / 8;      // Add 7 and integer divide by 8 (alternative to ceil math function)
    int bitsToMask = bytesNeeded * 8;           // variable to hold value for multiple of 8's i.e. no of bytes

    unsigned int displayMask = 1 << (bitsToMask - 1);

    int fourBitsGroup = bitsToMask/4;           //variable to hold no. of 4-bits groups


    char hexString[fourBitsGroup+1]; // declare char array of n-elements based on fourBitsGroup variable
    int hexDigitIndex = fourBitsGroup-1;  // declare variable from where to start inserting the converted data

    hexString[fourBitsGroup] = '\0'; // null termination for string array i.e. the last array element

    for (int i = 0; i < fourBitsGroup; i++) { // Process two groups of 4 bits

        unsigned int fourBits = value & 0xF; // 0xF is the bitmask for 4 bits


        if (fourBits < 10) {                // if-block to check if the result is between1 - 10
            hexString[hexDigitIndex--] = '0' + fourBits;    // maps to digits 0-9 based on bitwise AND operation
        } else {                            // else-block to check if the results falls under A-F range and maps to it
            hexString[hexDigitIndex--] = 'A' + (fourBits - 10);     // mapping to ASCII character based on result
        }

        value >>= 4; // right shift by 4 bits for each iteration
    }

    printf("%s\n", hexString); // Print hex string



}                                           //bin2hex function ends here


// Function to check if a string represents a valid binary notation digits i.e. only 1's & 0's
int isValidUnsignedInt(const char *str) {   //checks the validity of user input, returns 1 if criteria is met
    while (*str) {

        if (*str != '0' && *str != '1') { //if-flase condition , in case of any other char than digits
            return 0;  // Return false (0) if a non-digit character is found
        }

        str++;         // increment to while statement
    }
    return 1;  // Return true (1) if only digit characters are found
}


