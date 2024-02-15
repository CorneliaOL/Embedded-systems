// (C) Lucas Holter, Cornelia Olofsson, Rizwan Rafiq, group: 18 (2024)
// Work package 3
// Exercise 5
// Submission code: 

//Import statements
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10 //Define size of array

void fillRand(unsigned int* array, int size); //Declare the fillRand function

//Main function, program execution starts here
int main(int argc, char** argv){

    unsigned int array[MAX]; //Declare an array of unsigned int of size MAX
    unsigned int* pArray = &array[0]; //Declare a pointer and point it to the adress of the first entry of the array
    fillRand(pArray, sizeof(array)/sizeof(int)); //Function that fills an array with random values, it requires a pointer to an array and the size

    printf("The value of the adress of the array is: %p\n", array); //Print the adress of the first value of the array
    printf("The first integer in the array is: %d\n", *pArray); //Prints first int of array
    printf("The last integer in the array is: ");
	//Increment pArray pointer to last value of the array
    for(int i = 0; i < MAX-1; i++){
        pArray++; //Increment pointer
    }
    printf("%d\n", *pArray); //Print value of last element in array

    printf("The size of an Integer is (in bytes): %d\n", sizeof(*pArray)); //Takes the size of the last entry in the array, which is an integer
    printf("The size of the whole array in bytes is: %d\n", sizeof(array)); //Takes the size of the whole array and prints it

    pArray = array; //reassigns pArray to the start of array
	//For every value in array
    for(int i = 0; i < MAX; i++){
        printf("Index: %d\n", i); //Print the index
        printf("Value: %d\n", *pArray); //Print the value
        printf("Value * 2: %d\n", *pArray*2); //Print the value times 2
        pArray++; //Increment pointer
        printf("----------------------\n"); //Divider
    }
}

//Defines function that fills arrays with size amount of random numbers from 1-99
void fillRand(unsigned int* array, int size){
    srand((unsigned) time(0)); //Seed random function

	//For size indecies in the given array
    for(int i = 0; i < size; i++){
        *array = (rand()%99) + 1; //Assign it a random number from 1-99
        array++; //Increment pointer
    }
}