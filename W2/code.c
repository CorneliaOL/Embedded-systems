// (C) Lucas Holter, Cornelia Olofsson, Rizwan Rafiq, group: 18 (2024)
// Work package 2
// Exercise 4a
// Submission code: 240618

//Import statements
#include <stdio.h>
#include <stdlib.h>

//Defines BIT1 - BIT8 as the corresponding bit set
#define BIT1 1
#define BIT2 1 << 1
#define BIT3 1 << 2
#define BIT4 1 << 3
#define BIT5 1 << 4
#define BIT6 1 << 5
#define BIT7 1 << 6
#define BIT8 1 << 7


//Defines the function checkInput
void checkInput(char* argv[]);

//Start of main
int main(int argc, char* argv[]){
    unsigned char controlByte; //Declares variable that will hold the byte which holds the information to be packed

    //If arguements is not 6
    if (argc != 6){
        printf("Error: Wrong amount of arguments\n"); //Indicate to user that wrong ammount of arguments were provided
        return 0;//Return 0 
    }

    checkInput(argv); //Call the checkInput function on the array of given arguments

    //Pack each given argument into it's corresponding bit(s) as decided by the task definition, e.g. the first argument is to be stored in the 8th bit, so it is left shifted 7 times.
    controlByte = (atoi(argv[1]) << 7) + (atoi(argv[2]) << 4) + (atoi(argv[3]) << 2) + (atoi(argv[4]) << 1) + atoi(argv[5]);

    printf("%x\n", controlByte);

    return 0; //Return 0, indicating successful termination
}

//Defines function that checks input
void checkInput(char* argv[]){

    //First argument is the program name

    //if second argument is out of bounds as specified in the task
    if(atoi(argv[1]) > 1 || atoi(argv[1]) < 0){
        printf("First argument out of bounds\n");
        exit(0); //Exit the program
    }
    //if third argument is out of bounds as specified in the task
    if(atoi(argv[2]) > 7 || atoi(argv[2]) < 0){
        printf("Second argument out of bounds\n");
        exit(0); //Exit the program
    }
    //if fourth argument is out of bounds as specified in the task
    if(atoi(argv[3]) > 3 || atoi(argv[3]) < 0){
        printf("Third argument out of bounds\n");
        exit(0); //Exit the program
    }
    //if fifth argument is out of bounds as specified in the task
    if(atoi(argv[4]) > 1 || atoi(argv[4]) < 0){
        printf("Fourth argument out of bounds\n");
        exit(0); //Exit the program
    }
    //if sixth argument is out of bounds as specified in the task
    if(atoi(argv[5]) > 1 || atoi(argv[5]) < 0){
        printf("Fifth argument out of bounds\n");
        exit(0); //Exit the program
    }

}
