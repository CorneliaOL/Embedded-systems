//Import standard input output
#include <stdio.h>
//Import standard library
#include <stdlib.h>
//Import time library
#include <time.h>

//Declare function that assigns random values to the array of random numbers with size MAX
void create_random(int*);
//Declare cuntion to count the number of occurences of each number between 0 and MAXNUMBER
void count_frequency(int*, int*);
// Declare function that draws histogram of frequency of each numbers occurance vertically
void draw_histogram_vertical(int*);
// Declare function that draws histogram of frequency of each numbers occurance horizontaly
void draw_histogram_horizontal(int*);
// Declare function that finds the max of an array of possitive ints
int findMax(int[]);

//Defines how long the array of random numbers is
int MAX;
//Defines the range of numbers ti be randomized between
int MAXNUMBER;

//Declare main function with return type int, arc is the count of arguments and argv are the arguments themselves
int main(int argc, char* argv[]){

    //Converts the first (non program-name) argument into a number and assigns it to MAX which defines how long the array of random numbers will be
    MAX = atoi(argv[1]);
    //Converts the second (non program-name) argument into a number and assigns it to MAXNUMBER which will define the range of random numbers
    MAXNUMBER = atoi(argv[2]);


    // Declares an array of ints with the size MAX
    int table[MAX];

    //Declares an array of ints with the length MAXNUMBER+1, the reason for this is that we need one index for every possible random number 
    //to assign it a number of occurences
    int frequency[MAXNUMBER+1];

    // Calls the create_random method and passes it a pointer to the start of the array table
    create_random(table);

    // For every index in the frequency array
    for(int i = 0; i <= MAXNUMBER; i++) {
        frequency[i] = 0; //Assign 0 to each index
    }

    // Calls the count_frequency method and passes it pointers to the starts of the table and frequency arrays
    count_frequency(table, frequency);

    // Calls the draw_histogram_vertical method and passes it a pointer to the start of the array frequency
    draw_histogram_vertical(frequency);

    printf("---------------------\n");

    // Calls the draw_histogram_horizontal method and passes it a pointer to the start of the array frequency
    draw_histogram_horizontal(frequency);
}

//Defines the method create_random
void create_random(int* tab){
    srand((unsigned) time(0)); // Sets a seed for the rand() function, this method was found here https://www.tutorialspoint.com/c_standard_library/c_function_srand.htm
    // For every index in the tab/table array
    for(int i = 0; i < MAX; i++){
        tab[i] = rand() % (MAXNUMBER + 1); //Generate a pseudorandom value that lies between 0 and MAXNUMBER and assign it to index i
    }
}

//Defines the method count_frequency
void count_frequency(int* tab, int* freq){
    int* iterator = tab; //Create pointer iterator that points to the start of the tab array

    //For every index in the tab/table array
    for(int i = 0; i < MAX; i++){
        //Increment the index in freq/frequency array that is equal to the number that is assigned to the adress the pointer points to,
        //I.E. increment by one in frequency at the index that coresponds to the value found in tab/table
        freq[*iterator]++;
        iterator++; //Iterate pointer to keep going through tab/table
    }
}

//Define draw_histogram_vertical method
void draw_histogram_vertical(int* frequency){
    //Loop through frequency array
    for(int i = 0; i <= MAXNUMBER; i++){
        //If a number occured 0 times, dont print it
        if(*frequency != 0){
            printf("%d:", i); //Print out the number which the histogram row is about
            //Print the amount of x as occurences of this number
            for(int j = 0; j < *frequency; j++){
                printf(" x");
            }
            printf("\n");
        }
        frequency++; //Iterate the pointer to go through the array
    }
}

//Defines the method draw_histogram horizontaly
void draw_histogram_horizontal(int* frequency){
    int max; //Defines variable max, that will hold the max value in the array frequency at a given point
    int* iterator; //Define the pointer iterator that will be used to repeatedly go through the frequency array
    //Define and instantiate the variable startMax that will hold the max value of frequency at the start of the method execution
    int startMax = findMax(frequency); 


    //The ammount of times this loop will run is given by the max value of frequency at the start of method execution
    max = findMax(frequency); //Find the current max value of frequency
    for(int i = 0; i < startMax; i++) {
        iterator = frequency; //Assign iterator to the start of the array frequency
        //Go thorugh each index of frequency
        for (int j = 0; j <= MAXNUMBER; j++) {
            //If the frequency of a given number is 0, dont print it
            if(*iterator != 0){
                //If the value currently pointed to by the iterator is equal to the maximum in the array
                if (*iterator >= max) {
                    printf("  x  "); //Print a marker to denote how many occurances there were
                } else { //If the value pointed to by the pointer is not max
                    printf("     "); //Print an empty space
                }
            }
            iterator++; // Increment the pointer to go through the array
        }
        max = max - 1; //Decrement max value
        printf("\n"); //Print a line break after the array is gone through
    }
    //For every index in frequency
    for(int i = 0; i <= MAXNUMBER; i++){
        //If the frequency of a number is 0, dont print it
        if(frequency[i] != 0){
            //if the number is less than 10
            if(i < 10) {
                printf("  %d  ", i); //Print the number that index coresponds to
            }
            // If the number is between 10 and 100
            else if(i < 100){
                printf(" %d  ", i); //Print the number that index coresponds to with changed spacing to account for multiple characters
            }
        }
    }
    printf("\n");

}

//Defines findMax method
int findMax(int array[]){
    int max = 0; //Define max variable and set to 0
    int* iterator = array; //Create a pointer that points to the start of the given array

    //For every index in the array that will in this case be frequency, this will only work for arrays of length MAXNUMBER+1, which is a point of
    //improvment
    for(int i = 0; i <= MAXNUMBER; i++){
        // If the value at the adress the pointer points to is greater than what max is
        if(*iterator > max){
            max = *iterator; //Assign the value at the iterator to the variable max
        }
        iterator++; //Increment the iterator to go through the array
    }
    return max; //Return the greates value found in the array
}
