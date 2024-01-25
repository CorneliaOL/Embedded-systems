/*Directives for defining identifiers from standard libraries*/

#include <stdio.h>      /* preprocessor directive: includes Standard I/O library*/
#include <ctype.h>      /* preprocessor directive: includes validation function */
#include <stdlib.h>     /* preprocessor directive: includes functions library*/
#include <string.h>     /* preprocessor directive: includes functions*/

#define BYTES 8         /* preprocessor directive: MACRO for defining number of bytes for system. 1 Byte = 8-bit*/


void binaryToHex(unsigned int value);       // function prototype
int isValidUnsignedInt(const char *str);    // function prototype



int main(int argc, char *argv[]) {

    const char *targetString = "-h";        /* Variable initial: '-h' as string value to show help message */
    char binaryString[BYTES*8+1];           // String to store binary input


    if( argc != 2 ){

        scanf("%64s", binaryString); // Read binary string
        unsigned int binValue = strtoul(binaryString, NULL, 2);     // Convert string to number
        binaryToHex(binValue);                                      // function call

    } else {

        if(isValidUnsignedInt(argv[1])){                            // validation function to verify digits in the input value

            unsigned int binValue = strtoul(argv[1], NULL, 2);      // Convert string to number

            binaryToHex(binValue);                                  // function call

        } else if(strcmp(argv[1], targetString) == 0){              // matches the argument with the defined string i.e. '-h' in this case

            printf("Help message - Please enter program name (space) valid decimal digits");
            return 0;                                               // exist program with return value 0

        } else {                                    //returns message in case of invalid user input
            printf("Error: Invalid input: Please enter a valid unsigned integer.\n");
            return 0;                               //returns 1 in se of invalid user input
        }               // end of nested if statement

    }
    return 0;           // exits the main function with return value 0

}


//Function to convert from binary to hex value with binary value as input argument
void binaryToHex(unsigned int value) {
    char hexString[BYTES*2+1];              // String initialization for 2 hex digits for two groups of 4 bits + null terminator
    int lastIndex = BYTES*2;                // variable declaration & initialization for the last index

    hexString[lastIndex--] = '\0';          // null terminator for string

    for (int i = 0; i < (BYTES*2+1); i++) { // for-loop for iterating over groups of 4-bits i.e. depends on defined Macro
        // Extract the rightmost 4 bits and map to hex character

        unsigned int fourBits = value & 0xF; // Bit masking for 4-bits groups

        if (fourBits < 10) {                //for-loop for mapping value from 0-9 as Hexadecimal
            hexString[lastIndex--] = '0' + fourBits;        //maps result to range [0-9]
        } else {                                            //else for mapping value greater than 10
            hexString[lastIndex--] = 'A' + (fourBits - 10); //maps result to range [A-F]
        }
        value >>= 4; // right shift to bit mask next 4-bits group
    }
    printf("%s\n", hexString); // Print hex string
}


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


