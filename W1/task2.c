#include <string.h> // Used by strlen
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>

// "Global" variable used for checking if ctrl Z has been pressed or not
volatile int stopSignal = 0;

// A method that checks if the signum is the same as sigstp, if true it will change the stopSignal that are used in main
void ctrlZ(int signum) {
    if (signum == SIGTSTP) {
        stopSignal = 1;
    }
}


int main(int argc, char* argv[]){
    //set the sigtstp signal to the ctrlZ function that will get triggered when control + z is used by the user
    signal(SIGTSTP, ctrlZ);
    // If the wrong amount of arguments is inserted, return error code 1 and print a message to the user
    if (argc != 2){
        printf("Please only provide a number to set how many steps the letters shall shift\n");
        return 1;
    }
    // declare char input as null, will later get used to hold user input
    char *input = NULL;
    //malloc the input char to assign size 100
    input = (char *) malloc(100);

    // declare an int that will hold the number of character shift specified by user
    int shiftNum;
    //use errno from errno.h to check for error in the next step
    errno = 0;
    //Fetch the amounts of shift steps from the argv specified by user
    long shiftNumConv = strtol(argv[1],NULL, 10 );
    // if errno is not 0, return an error code. Else assign int shiftNum to the number extracted in line 13
    if (errno != 0) {
        return 1;
    } else {
        shiftNum = shiftNumConv;
    }

    printf("write a string! :D \n");
    while (1) {
        // use fgets as scanner to get user input, using 99 spaces instead of 99 to have place for end of line character
        fgets(input, 99, stdin);

        //if global variable stopsignal is one it means that the control + z command has been executed, then we free the space malloc to
        //input and return 0 as a success return value
        if (stopSignal == 1) {
            printf("Stopping the program...\n");
            free(input);
            return 0;
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