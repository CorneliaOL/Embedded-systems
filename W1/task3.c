//Import standard input output
#include <stdio.h>
//Import standard library
#include <stdlib.h>
//Import time library
#include <time.h>
//Defines max ammount of guesses
#define MAX_GUESS 4

//TODO
int randomize();
//Define main function with return type int, argc is count of args and argv is the args themselves
int main(int argc, char* argv[]){
    int cont = 1;
    int inputNum;   //Declare the variable that will hold the users guess
    int numGuesses = 1;     //Declares the variable that hold the current used guesses

    srand((unsigned) time(0));  //Seeds the rand() function, this method was found here: https://www.tutorialspoint.com/c_standard_library/c_function_srand.htm
    //TODO
    int targetNumber; //Gives a psuedorandom rumber between 0 and 100 and assigns it to the targetnumber variable which is the "correct" number

    //TODO
    //When target number is 0
    targetNumber = randomize();
    //TODO
    while(cont == 1){
    printf("Guess a number between 1-100, you have four tries!\n");
    // While we have not exeeded the max ammount of guesses
        while((numGuesses <= MAX_GUESS) && (inputNum != targetNumber)){
            scanf("%d", &inputNum);         //Read a number from standard input until space is found
            //If the guess is between 1 and 100
            if(inputNum <= 100 && inputNum >= 1) {
                //If the guessed number is the right number
                if (inputNum == targetNumber) {
                    printf("You have guessed %d times, you guessed right!\n", numGuesses);
                }
                //If the input number is larget than the target number
                if (inputNum > targetNumber) {
                    printf("The number is smaller, you have %d guesses left!\n", MAX_GUESS - numGuesses);
                }

                //If the input number is smaller than the target number
                if (inputNum < targetNumber) {
                    printf("The number is higher, you have %d guesses left!\n", MAX_GUESS - numGuesses);
                }
                numGuesses++; //Increase the guess count
            }
            else{
                printf("Guess between 1-100!\n");
            }
        }
        printf("The number was %d!\n", targetNumber);

        printf("Do you want to play again? Yes(1)/No(0)\n");
        //TODO
        scanf("%d", &cont);
        targetNumber = randomize();
        numGuesses = 1;
    }
    return 0; //Return 0 indicating successfull execution
}


//TODO
int randomize(){
    srand((unsigned) time(0));  //Seeds the rand() function, this method was found here: https://www.tutorialspoint.com/c_standard_library/c_function_srand.htm
    int targetNumber = rand()%101;
    while (targetNumber == 0){
        targetNumber = rand()%101; //Reasign it to a new number between 0 and 100
    }
    return targetNumber;
}
