// (C) Lucas Holter, Cornelia Olofsson, Rizwan Rafiq, group: 18 (2024)
// Work package 3
// Exercise 6
// Submission code: 655738

//Iimport statements
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copy(char* dest, char* toCpy); //Declare function copy

//Start of main
int main(int argc, char** argv){
    char buffer[1024]; //Declare variable buffer that will hold the input taken from stdin

    fgets(buffer, sizeof(buffer), stdin); //Reads standard input of the same size as buffer and puts it in buffer

    char* noLib = malloc(1024); //Allocate the same amount of memory as buffer
    char* libFunc = malloc(1024); //Allocate the same amount of memory as buffer

    strcpy(libFunc, buffer); //Copy string in buffer, with library function, to the variable libFunc
    copy(noLib, buffer); //Copy string in buffer, with my own function, to the variable noLib

    //Print out the results
    printf("Library function: %s\n", libFunc);
    printf("Non library function: %s\n", noLib);

    free(noLib); //Free heap memory tied to noLib
    free(libFunc); //Free heap memory tied to libFunc


}

//Defines function copy, that copies a string from one variable to another
void copy(char* dest, char* toCpy){

    //While the string is not at an end
    while(*toCpy != '\0'){
        *dest = *toCpy; //Put the char of the string to be copied into the destination
        dest++; //Increment dest pointer
        toCpy++; //Increment toCpy pointer
    }
    *dest = '\0'; //Null terminates the new string
}