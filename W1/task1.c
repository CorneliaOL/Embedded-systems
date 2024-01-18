#include <stdio.h>
int main (int argc, char *argv[]){
    while(1) {
        int inputNum;
        scanf("%d", &inputNum);

        switch (inputNum) {
            case 1:
                printf("One banana for you!\n");
                break;
            case 2:
                printf("I love C!\n");
                break;
            case 3:
                printf("Lets study!\n");
                break;

            case 4:
                printf("Wiho I'm learning C!\n");
                break;

            case 5:
                printf("Group 18 is amazing :D\n");
                break;
            default:
                return 0;
        }
    }
}