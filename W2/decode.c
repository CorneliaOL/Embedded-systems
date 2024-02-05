#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decode(unsigned char);

#define BIT1 1
#define BIT2 1 << 1
#define BIT3 1 << 2
#define BIT4 1 << 3
#define BIT5 1 << 4
#define BIT6 1 << 5
#define BIT7 1 << 6
#define BIT8 1 << 7

int main(int argc, char* argv[]){

    if(argc != 2){
        printf("Error: provide one argument as hexadecimal value\n");
        return 0;
    }

    if(strlen(argv[1]) > 2){
        printf("Error: Provide one byte\n");
        return 0;
    }

    char* iterator = argv[1];
    while(*iterator != '\0'){
        if(!((*iterator >= '0' && *iterator <= '9') || (*iterator >= 'a' && *iterator <= 'f') || (*iterator >= 'A' && *iterator <= 'F'))){
            printf("Error: Invalid characters\n");
            return 0;
        }
        iterator++;
    }



    printf("%s\n", argv[1]);

    unsigned char hexValue = strtol(argv[1], NULL, 16);
    decode(hexValue);
    return 0;
}

void decode(unsigned char hexValue){

    unsigned char bitmask;
    unsigned char brake2;
    unsigned char brake1;
    unsigned char key_pos;
    unsigned char gear_pos;
    unsigned char engine_on;

    bitmask = BIT1;
    brake2 = (bitmask & hexValue);
    hexValue = hexValue >> 1;

    bitmask = BIT1;
    brake1 = (bitmask & hexValue);
    hexValue = hexValue >> 1;

    bitmask = (BIT1) + (BIT2);
    key_pos = (bitmask & hexValue);
    hexValue = hexValue >> 2;

    bitmask = (BIT1) + (BIT2) + (BIT3);
    gear_pos = (bitmask & hexValue);
    if (gear_pos > 4){
        printf("Unvalid byte.\n");
        exit(0);
    }
    hexValue = hexValue >> 3;

    bitmask = BIT1;
    engine_on = (bitmask & hexValue);


    printf("Name        Value\n");
    printf("-------------------------\n");
    printf("engine_on   %d\n", engine_on);
    printf("gear_pos    %d\n", gear_pos);
    printf("key_pos     %d\n", key_pos);
    printf("brake1      %d\n", brake1);
    printf("brake2      %d\n", brake2);
}
