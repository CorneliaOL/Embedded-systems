//Import statements
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decode(unsigned char); //Defines the decode function

//Defines BIT1-BIT8 corresponding to bit 1 set to bit 8 set
#define BIT1 1
#define BIT2 1 << 1
#define BIT3 1 << 2
#define BIT4 1 << 3
#define BIT5 1 << 4
#define BIT6 1 << 5
#define BIT7 1 << 6
#define BIT8 1 << 7

//Start of main
int main(int argc, char* argv[]){

    // If there are not 2 arguments
    if(argc != 2){
        printf("Error: provide one argument as hexadecimal value\n");
        return 0; //Return 0 to end execution since wrong amount of arguments provided
    }

    //Checks if length of the second argument is more than 2
    if(strlen(argv[1]) > 2){
        printf("Error: Provide one byte\n");
        return 0; //if so return since we expect one byte of hexadecimal
    }

    char* iterator = argv[1]; //Declare variable that points to the second argument to iterate through it and validate each character
    //While the string is not at an end
    while(*iterator != '\0'){
        //Checks if the character pointed to by iterator is a valid hexadecimal character
        if(!((*iterator >= '0' && *iterator <= '9') || (*iterator >= 'a' && *iterator <= 'f') || (*iterator >= 'A' && *iterator <= 'F'))){
            printf("Error: Invalid characters\n");
            return 0; //If not, return 0 due to invalid characters
        }
        iterator++; //Increment pointer to check next character
    }



    printf("%s\n", argv[1]);

    unsigned char hexValue = strtol(argv[1], NULL, 16); //Convert the string in second argument to a number, indicate that the number in the argument is base 16
    decode(hexValue); //Call the method decode on the converted value to decode the information stored in the byte
    return 0; //Return 0 indicating successful termination
}

//Define function decode
void decode(unsigned char hexValue){

    unsigned char bitmask; //Declare variable bitmask that is used to determined the data stored in the given value
    //Declares one variable for each of the different parameters we have stored in the bit
    unsigned char brake2; //Declare variable brake2
    unsigned char brake1; //Declare variable brake1
    unsigned char key_pos; //Declare variable key_pos
    unsigned char gear_pos; //Declare variable gear_pos
    unsigned char engine_on; //Declare variable engine_on


    //In this section we will take the x first bits and put them in the coresponding variable as specified in the task, the number of x is decided by the size of the information as specified in the task
    //Then we shift the newly read bits to the right, so the next first bit(s) are now the next piece of information

    bitmask = BIT1; //Set bitmask to the first bit
    brake2 = (bitmask & hexValue); //Sets the first bit of brake2 variable to the same as hexValue, which is the argument to the program
    hexValue = hexValue >> 1; //Bit shift once to the right, this will throw away the bit we just checked

    bitmask = BIT1; //Set bitmask to the first bit
    brake1 = (bitmask & hexValue); //Sets the first bit of brake1 variable to the same as hexValue, which is the argument to the program
    hexValue = hexValue >> 1; //Bit shift once to the right, this will throw away the bit we just checked

    bitmask = (BIT1) + (BIT2); //Set bitmask to the first bit + second bit
    key_pos = (bitmask & hexValue); //Sets the first two bits of key_pos variable to the same as hexValue, which is the argument to the program
    hexValue = hexValue >> 2; //Bit shift twice to the right, this will throw away the bits we just checked
    //This value consists of 2 bits, so it can be up to 3, but it is specified in the task that max value is 2
    if(key_pos > 2){
        printf("Unvalid byte.\n");
        exit(0); //If the value of gear_pos is greater than 4, exit the program
    }

    bitmask = (BIT1) + (BIT2) + (BIT3); //Set bitmask to the first bit + second bit + third bit
    gear_pos = (bitmask & hexValue); //Sets the first three bits of gear_pos variable to the same as hexValue, which is the argument to the program
    //It is specified in the task that max value of gear_pos is 4, but it can be up to 7, so we must check that the given hex does not corespond to a value of gear_pos greater than 4
    if (gear_pos > 4){
        printf("Unvalid byte.\n");
        exit(0); //If the value of gear_pos is greater than 4, exit the program
    }
    hexValue = hexValue >> 3; //Bit shift thrice to the right, this will throw away the bits we just checked

    bitmask = BIT1; //Set bitmask to the first bit
    engine_on = (bitmask & hexValue); //Set engine_on to the value of the first bit of hexValue, which is the argument of the program


    printf("Name        Value\n");
    printf("-------------------------\n");
    printf("engine_on   %d\n", engine_on);
    printf("gear_pos    %d\n", gear_pos);
    printf("key_pos     %d\n", key_pos);
    printf("brake1      %d\n", brake1);
    printf("brake2      %d\n", brake2);
}
