#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_GUESS 4

// Links to where we found information
// https://www.tutorialspoint.com/c_standard_library/c_function_srand.htm

int main(int argc, char* argv[]){
    int inputNum;
    int numGuesses = 0;
    printf("Guess a number between 1-100, you have four tries!\n");

    srand((unsigned) time(0));
    int targetNumber = rand()%101;

    while (targetNumber == 0){
        targetNumber = rand()%101;
    }

    while(numGuesses <= MAX_GUESS){
        scanf("%d", &inputNum);
        if(inputNum <= 100 && inputNum >= 1) {
            if (inputNum == targetNumber) {
                printf("You guessed right!\n");

            }
            if (inputNum > targetNumber) {
                printf("The number is smaller, you have %d guesses left!\n", MAX_GUESS - numGuesses);
            }

            if (inputNum < targetNumber) {
                printf("The number is higher, you have %d guesses left!\n", MAX_GUESS - numGuesses);
            }
            numGuesses++;
        }
        else{
            printf("Guess between 1-100!\n");
        }
    }
    printf("The number was %d !", targetNumber);
    return 0;
}