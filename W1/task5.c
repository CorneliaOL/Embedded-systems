#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void create_random(int*);
void count_frequency(int*, int*);
void draw_histogram(int*);
int findMax(int[]);

int MAX;
int MAXNUMBER;

int main(int argc, char* argv[]){

    MAX = atoi(argv[1]);
    MAXNUMBER = atoi(argv[2]);


    int table[MAX];

    int frequency[MAXNUMBER+1];

    create_random(table);

    for(int i = 0; i <= MAXNUMBER; i++) {
        frequency[i] = 0;
    }

    count_frequency(table, frequency);

    draw_histogram(frequency);



}

void create_random(int* tab){
    srand((unsigned) time(0));
//Assign random values to every index
    for(int i = 0; i < MAX; i++){
        tab[i] = rand() % (MAXNUMBER + 1);
    }
}

void count_frequency(int* tab, int* freq){
    int* iterator = tab;

    for(int i = 0; i < MAX; i++){
        freq[*iterator]++;
        iterator++;
    }
}

void draw_histogram(int* frequency){
    int max;
    int* iterator;
    int startMax = findMax(frequency);

    for(int i = 0; i < startMax; i++) {
        iterator = frequency;
        max = findMax(frequency);
        for (int j = 0; j <= MAXNUMBER; j++) {
            if (*iterator == max) {
                printf("  x  ");
                *iterator = *iterator - 1;
            } else {
                printf("     ");
            }
            iterator++;
        }
        printf("\n");
    }
    for(int i = 0; i <= MAXNUMBER; i++){
        if(i < 10) {
            printf("  %d  ", i);
        }
        else if(i < 100){
            printf(" %d  ", i);
        }
    }
    printf("\n");

}

int findMax(int array[]){
    int max = 0;
    int* iterator = array;

    for(int i = 0; i <= MAXNUMBER; i++){
        if(*iterator > max){
            max = *iterator;
        }
        iterator++;
    }
    return max;
}