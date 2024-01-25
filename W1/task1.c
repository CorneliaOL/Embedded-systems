//Import standard input output
#include <stdio.h>

//Declare main function that returns type int, argc is argument count, and argv is the arguments themselves
int main (int argc, char *argv[]){
    //While true, perpetual loop
    while(1) {
        int inputNum; //Declares the variable that will hold the input value
        scanf("%d", &inputNum); //Scans the terminal for input, expects a number and takes the input and puts it into inputNum

        //Switch case, will execute different blocks depending on the value of inputNum
        switch (inputNum) {
            case 1: //In the case that inputNum is 1
                printf("One banana for you!\n");
                break; //Breaks out of this case block
            case 2: //In the case that inputNum is 2
                printf("I love C!\n");
                break; //Breaks out of this case block
            case 3: //In the case that inputNum is 3
                printf("Lets study!\n");
                break; //Breaks out of this case block

            case 4: //In the case that inputNum is 4
                printf("Wiho I'm learning C!\n");
                break; //Breaks out of this case block

            case 5: //In the case that inputNum is 5
                printf("Group 18 is amazing :D\n");
                break; //Breaks out of this case block
            default: //If none of the above cases are true
                return 0; //Return true, indicating successful execution
        }
    }
}
