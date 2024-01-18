#include <string.h> // Used by strlen
#include <stdio.h>
int main(int argc, char* argv[]){
    char* input = argv[1];
    for(int i = 0; i < strlen(input); i++){
            int charnum;

        if((int) input[i] > 64 && (int) input[i] < 91){
            // add 13 steps for offset and delete 65 steps, then perform modulo 26 (the amount of letters in the alphabet)  add back the 65 steps we previously deleted

            charnum = (((int)input[i]+13-65)%26)+65;
        }
        else{
            // add 13 steps for offset and delete 97 steps, then perform modulo 26 (the amount of letters in the alphabet)  add back the 97 steps we previously deleted
            charnum = (((int)input[i]+13-97)%26)+97;
        }

        input[i] = (char)charnum;
    }
    printf("%s\n", input);
    return 0;
}