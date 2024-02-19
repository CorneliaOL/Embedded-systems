// (C) Lucas Holter, Cornelia Olofsson, Rizwan Rafiq, group: 18 (2024)
// Work package 4
// Exercise 4
// Submission code: ??????
//Import statements
#include <stdio.h> 

void sort (int number, int tab []); //Declare sort that sorts an array of ints
int search_number(int number, int tab[], int size); //Declare search_number that will check if number is in array tab of size size
void swap(int* swap1, int* swap2); //Swaps the values two int pointers are pointing too

//Start of main
int main(int argc, char** argv){

	int test[] = {1,2,34,5,67,3,23,12,13,10}; //Declare and initialize array that will be used for sorting and finding number

	int size = sizeof(test)/sizeof(int); //Create variable that will hold the size of the array, in indecies

	//If search number function is successful, I.E. returns 0
	if(search_number(10, test, size) != -1){
		printf("Number found\n"); //print success statement
	}
	//if not successfull
	else{
		printf("Number not found\n"); //Print fail statemenet
	}

	printf("\nBefore sort:\n");
	//Print out unsorted array
	for(int i = 0; i < size; i++){
		printf("Index %d: %d\n", i, test[i]);
	}


	printf("\nAfter sort:\n");
	sort(size, test); //Call the sort function
	//Print out the now sorted array
	for(int i = 0; i < size; i++){
		printf("Index %d: %d\n", i, test[i]);
	}
}

//Define function search_number
int search_number(int number, int tab[], int size){
	//Go through the array
	for(int i = 0; i < size; i++){
		//if the current index is equal to the number we're searching for
		if(tab[i] == number){
			return i; //return index
		}
	}
	return -1; //If the number is not found, return -1
}

//Define function sort
void sort(int number, int tab[]){
	//Take every index in the array
	for(int i = 0; i < number; i++){
		//For every index i, loop through the indecies after i
		for(int j = i; j < number; j++){
			//If the entry at index i is larger than at index j, swap them
			if(tab[i] > tab[j]){
				swap(&tab[i], &tab[j]); //Perform the swap
			}
			
		}
	}
}
//TODO
//define swap function
void swap(int* swap1, int* swap2){
	int temp = *swap1; //put the value swap1 is pointing to in the variable temp
	*swap1 = *swap2; //Point swap1 to the value swap2 is pointing to
	*swap2 = temp; //Point swap2 to the value of temp, which is the value swap1 is pointing to at the start of the function
}
