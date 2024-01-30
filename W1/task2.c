// (C) Lucas Holter, Cornelia Olofsson, Rizwan Rafiq, group: 18 (2024)
// Work package 1
// Exercise 2
// Submission code: 125455

#include <string.h> // Used by strlen
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>

// "Global" variable used for checking if ctrl Z has been pressed or not
int stopSignal = 0;

// A method that checks if the signum is the same as sigstp, if true it will change the stopSignal that are used in main
void ctrlZ(int signum) {
    //If the given signal is equal to the stop signal 
    if (signum == SIGTSTP || signum == SIGINT) {
        stopSignal = 1; //Change global stopsignal to 1
    }
}

//Define function to remove \n character from end of string, this will be null terminated twice which we are aware of
void stripNewLine(char* array){
    array[strlen(array)-1]='\0'; //Reasign the second last charcater from \n to \0
}


int main(int argc, char* argv[]){
    //set the sigtstp signal to the ctrlZ function that will get triggered when control + z is used by the user
    signal(SIGTSTP, ctrlZ);
    // If the wrong amount of arguments is inserted, return error code 1 and print a message to the user
    if (argc != 2){
        printf("Please only provide a number to set how many steps the letters shall shift\n");
        return 1; //Return 1 indicating unsuccessful termination
    }
    // declare char input as an array of length 100, will later get used to hold user input
    char input[100];

    // declare an int that will hold the number of character shift specified by user
    int shiftNum;
    //use errno from errno.h to check for error in the next step
    errno = 0;
    //Declare character pointer to hold eventual non numerical characters
    char* p;
    //Fetch the amounts of shift steps from the argv specified by user, any eventual non number characters will be stored in p, 10 is indicating that the recieved number is decimal
    long shiftNumConv = strtol(argv[1],&p, 10 );

    //Checks if character in *p is null terminator
    if ( *p != '\0' ){
        printf("Error\n");
        return 1; //Return 1, indicating unsuccessful execution
    }

    // if errno is not 0, return an error code. Else assign int shiftNum to the number extracted in line 13
    if (errno != 0) {
        return 1; //Return 1, indicating unsuccessful execution
    } else {
        shiftNum = shiftNumConv; //Put the inputed value into the variable that holds the number of character shifts, long -> int
    }

    printf("write a string! :D \n");
    //While true, perpetual loop
    while (1) {
        // use fgets as scanner to get user input, using 99 spaces instead of 99 to have place for end of line character
        fgets(input, 99, stdin);

        //Removes \n character that is included in fgets
        stripNewLine(input);

        //if global variable stopsignal is one it means that the control + z command has been executed, then we free the space malloc to
        //input and return 0 as a success return value
        if (stopSignal == 1) {
            printf("Stopping the program...\n");
            return 0; //Return 0, indicating successful execution
        }
        //Iterate over all characters in the input
        for(int i = 0; i < strlen(input); i++){
            //Declare an integer that will be a placeholder for shifting characters
            int charnum;
            //if the characters are bigger than 64 and smaller than 91, they will be capital letters, else they will be small letters
            if((int) input[i] > 64 && (int) input[i] < 91){
                // add 13 steps for offset and delete 65 steps, then perform modulo 26 (the amount of letters in the alphabet)  add back the 65 steps we previously deleted
                charnum = (((int)input[i]+shiftNum-65)%26)+65;
            }
            else{
                // add 13 steps for offset and delete 97 steps, then perform modulo 26 (the amount of letters in the alphabet)  add back the 97 steps we previously deleted
                charnum = (((int)input[i]+shiftNum-97)%26)+97;
            }
            // add the converted letter to the input char
            input[i] = (char)charnum;
        }
        //print all converted chars in one word
        printf("%s\n", input);
    }
}
