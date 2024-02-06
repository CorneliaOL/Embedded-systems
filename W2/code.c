/*
program to code and pack the bits in a byte (8-bits)
*/

//Import statements
#include <stdio.h>
#include <stdlib.h>

#define BITMASK_1BIT 0x1 //Define bitmask that checks the first bit
#define BITMASK_2BIT 0x3 //Define bitmask that checks the first two bit
#define BITMASK_3BIT 0x7 //Define bitmask that checks the first three bit


//Start of main
int main(int argc, char * argv[]) {

    // Input integers, used to store arguments
    unsigned int engine_on, gear_pos, key_pos, brake1, brake2;

    //If the program is not given the correct amount of arguments
    if(argc != 6){

        printf("Exactly five arguments allowed as input\n");

    //If the program is given the correct amount of arguments, I.E. 5 arguments
    } else {

        engine_on = atoi(argv[1]); //Decodes first argument into its coresponding variable
        gear_pos = atoi(argv[2]); //Decodes second argument into its coresponding variable
        key_pos = atoi(argv[3]); //Decodes third argument into its coresponding variable
        brake1 = atoi(argv[4]); //Decodes fourth argument into its coresponding variable
        brake2 = atoi(argv[5]); //Decodes fifth argument into its coresponding variable

        //If all inputs are not in valid range
        if ((engine_on < 0 || engine_on > 1) //Checks if engine_on is in bounds as defined by the task
        || (gear_pos < 0 || gear_pos > 4)  //Checks if gear_pos is in bounds as defined by the task
        || (key_pos < 0 || key_pos > 2) //Checks if key_pos is in bounds as defined by the task
        || (brake1 < 0 || brake1 > 1) //Checks if brake1 is in bounds as defined by the task
        || (brake2 < 0 || brake2 > 1)) //Checks if brake2 is in bounds as defined by the task
        {
            printf("input should be in the range\n");
        } else { //If all inputs are in valid range

            engine_on &= BITMASK_1BIT; // Sets the first bit if it is set in the program argument
            gear_pos &= BITMASK_3BIT; // Sets the first three bit if they are set in the program argument
            key_pos &= BITMASK_2BIT; // Sets the first two bit if they are set in the program argument
            brake1 &= BITMASK_1BIT; // Sets the first bit if it is set in the program argument
            brake2 &= BITMASK_1BIT; // Sets the first bit if it is set in the program argument

            // Pack the integers into a byte where the first argument is contained in the 8th bit and the last is contained in the 1st bit
            unsigned char packedByte = (engine_on << 7) | (gear_pos << 4) | (key_pos << 2) | (brake1 << 1) | (brake2 << 0);

            // Output the result
            printf("%02X\n", packedByte); 
        }
    }

    return 0; //Return 0, indicating successful execution
}
