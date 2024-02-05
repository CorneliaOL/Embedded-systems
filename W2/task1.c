//Import statements
#include <stdio.h>
#include <stdlib.h>

//Defines enum that assigns N to W with values 0 to 3
enum DIRECTION{N, O, S, W};

//Structure that will hold the positional information of the robot
typedef struct {
    int xpos; //Holds the robots x position
    int ypos; //Holds the robots y position
    enum DIRECTION dir; //Holds the robots rotational orientation
} ROBOT; //Defines the structures name


void turn(ROBOT*); //Declares the function turn
void move(ROBOT*); //Declares the function move
ROBOT initialize(); //Declares the function initialize
void clearBuffer(); //Declare the function clearBuffer

//Main function start
int main(int argc, char* argv[]){

    ROBOT robot; //Declares variable of type ROBOT
    ROBOT *pRobot; //Declares pointer towards type ROBOT
    char commands[30]; //Declares an array of characters of length 30 bytes
    char* iterator; //Defines iterator that will be used to iterate through the commands variable
    char exitFlag = 0; //Declares control-variable that will be used to indicate whether user wants to continue execution or not

    //Main loop that will run as long as exitFlag is set to 0
    while(exitFlag == 0){
        robot = initialize(); //Initializes the variable robot through user input
        pRobot = &robot; //Point pRobot pointer to the value of newly initialized robot variable

        printf("Give the robot commands, m = move, t = turn, x = exit\n");
        scanf("%29s", commands); //Reads the commands from the standard input with a maximum of 29 characters
        clearBuffer(); //Clears the buffer
        printf("Given commands: %s\n", commands);



        iterator = commands; //Points iterator pointer towards commands variable
        //While iterator is not equal to null terminator, I.E. while string is not at an end
        while(*iterator != '\0'){
            if (*iterator == 't'){ //Checks if current character is equal to 't'
                turn(pRobot); //If so, turn the robot
            } else if (*iterator == 'm'){ //If current character is not 't', check if it is 'm'
                move(pRobot); //If so, move the robot
            } else if (*iterator == 'x'){ //If neither of previous conditions is true, check if current character is 'x'
                exitFlag = 1; // If so, set exitFlag to 1, indicating the user wants to exit
            } else {    // else-block for validating 'commands' string as input
                printf("%c ignored, not a valid command.\n", *iterator);
            }
            iterator++; //Increment the iterator
        }

        printf("y value: %d\n", pRobot->ypos);
        printf("x value: %d\n", pRobot->xpos);
    }

    printf("Goodbye!\n");

    return 0; //Return 0, indicating successful execution
}

//Define function move, that takes a pointer to a robot
void move(ROBOT* pRobot){
    enum DIRECTION dir = pRobot -> dir; //Variable dir is assigned to the robots direction
    int xpos = pRobot -> xpos; //Variable xpos is assigned to the robots x position
    int ypos = pRobot -> ypos; //Variable ypos is assigned to the robots y position
    //Defines different cases that will happen depending on the value of dir
    switch(dir){
        case N: //if value of dir is equal to the enum direction value of N, i.e. 0
            pRobot -> ypos = ypos + 1; //Increment y position by 1
            break; //Break out of this case, ending the execution for the switch statement
        case O: //if value of dir is equal to the enum direction value of O, i.e. 1
            pRobot -> xpos = xpos + 1; //Increment x position by 1
            break; //Break out of this case, ending the execution for the switch statement
        case S: //if value of dir is equal to the enum direction value of S, i.e. 2
            pRobot -> ypos = ypos - 1; //Decrement y position by 1
            break; //Break out of this case, ending the execution for the switch statement
        case W: //if value of dir is equal to the enum direction value of W, i.e. 3
            pRobot -> xpos = xpos - 1; //Decrement x position by 1
            break; //Break out of this case, ending the execution for the switch statement
    }
}

//Defines function turn that takes pointer to a robot
void turn(ROBOT* pRobot){
    enum DIRECTION dir = pRobot -> dir; //Assigns variable dir to the value of robots variable dir
    pRobot -> dir = (dir + 1) % 4; //Increment direction by 1, thus turning the robot, if the value is more than 3 we wrap around to 0, thus constraining
    //the value to 0-3
}

//Defines the function initialize that returns a ROBOT struct
ROBOT initialize(){
    int xpos; //Declares variable xpos that will hold the x position of the robot
    int ypos; //Declares variable ypos that will hold the y position of the robot
    printf("Starting position:\n");
    printf("x: \n");
    scanf("%d", &xpos); //Reads standard input and assigns the number to the xpos variable, this will be the robots starting x position
    clearBuffer(); //Clears the buffer
    printf("y: \n");
    scanf("%d", &ypos); //Reads standard input and assigns the number to the ypos variable, this will be the robots starting y position
    clearBuffer(); //Clear the buffer

    ROBOT robot = {xpos, ypos, N}; //Initializes a robot with the starting values given earlier, robots always start facing north
    return robot; //Return the initialized robot
}

//check the buffer for spaces and remove superflous characters from buffer
void clearBuffer(){
    char ch; //Declare variable that will hold current character in buffer
    //While the current character in the buffer is not \n or EOF
    while((ch = getchar()) != '\n' && getchar() != EOF){
        if(ch == ' '){  // if-block for checking space btw characters
            printf("Space not allowed, exiting.\n");
            exit(0);    // exits in case of including space
        }
    }
}
