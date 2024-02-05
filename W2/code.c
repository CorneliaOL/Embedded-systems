#include <stdio.h>
#include <stdlib.h>

#define BIT1 1
#define BIT2 1 << 1
#define BIT3 1 << 2
#define BIT4 1 << 3
#define BIT5 1 << 4
#define BIT6 1 << 5
#define BIT7 1 << 6
#define BIT8 1 << 7

void checkInput(char* argv[]);

int main(int argc, char* argv[]){
    unsigned char controlByte;

    if (argc != 6){
        printf("Error: Wrong amount of arguments\n");
        return 0;
    }

    checkInput(argv);

    controlByte = (atoi(argv[1]) << 7) + (atoi(argv[2]) << 4) + (atoi(argv[3]) << 2) + (atoi(argv[4]) << 1) + atoi(argv[5]);
    printf("%x\n", controlByte);

    return 0;
}

void checkInput(char* argv[]){

    if(atoi(argv[1]) > 1 || atoi(argv[1]) < 0){
        printf("First argument out of bounds\n");
        exit(0);
    }
    if(atoi(argv[2]) > 7 || atoi(argv[2]) < 0){
        printf("Second argument out of bounds\n");
        exit(0);
    }
    if(atoi(argv[3]) > 3 || atoi(argv[3]) < 0){
        printf("Third argument out of bounds\n");
        exit(0);
    }
    if(atoi(argv[4]) > 1 || atoi(argv[4]) < 0){
        printf("Fourth argument out of bounds\n");
        exit(0);
    }
    if(atoi(argv[5]) > 1 || atoi(argv[5]) < 0){
        printf("Fifth argument out of bounds\n");
        exit(0);
    }

}
