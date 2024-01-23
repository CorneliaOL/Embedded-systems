#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
    int mask = 1<<7;
    int value = atoi(argv[1]);
    printf("%d\n", value);
    char result[9];


    for (int i = 0; i < 8; i++){
        if((mask & value) == 0){
            result[i] = '0';
        } else{
            result[i] = '1';
        }
        mask >>= 1;
    }
    result[8] = '\0';
    printf("%s\n", result);
}