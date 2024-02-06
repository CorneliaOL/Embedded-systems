// (C) Lucas Holter, Cornelia Olofsson, Rizwan Rafiq, group: 18 (2024)
// Work package 2
// Exercise 2
// Submission code: 240618

//Import statements
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#### Constants #####
//Define MAX as 5, which will be the number of items in the randomly generated linked list
#define MAX 5

// ##### typedefs ####
typedef struct q{ //Defines a structure
    int number; //Declares the varialbe number, which is the data
    struct q *next; //Declares the field next, which is a pointer to another of the same struct
    struct q *prev; //Declares the field prev, which is a pointer to another of the same struct
} REGTYPE; //Name of the structure

// ##### Function declarations #####
REGTYPE* random_list(void); //Declares function random_list which returns a pointer to a REGTYPE struct
REGTYPE* add_first(REGTYPE* temp, int data); //Declares function add_first that takes in pointer to REGTYPE and an int, it then returns a pointer to a REGTYPE struct

//###### Main program #######
int main(){
    int nr=0; //Declares variable nr which is used to enumerate each of the entries in the linked list
    REGTYPE *act_post , *head=NULL; //Defines pointers to REGTYPE struct

    unsigned int seed = 3; //unsigned int to seed srand
    srand(seed); // Random seed


    head=random_list(); //Points variable head to the top of a randomly generated linked list
    act_post=head; // Points act_post to the same adress as head

    //While there is a next entry in the linked list
    while(act_post!=NULL){
        printf("\n Post nr %d : %d" , nr++, act_post->number);
        act_post=act_post->next; //Go to the next node in the linked list
    }

    head = add_first(head, 101); //Calls method to add a new first item to linked list, which will now be the head of the linkedlist

    act_post = head; //Sets act_post to the head of the linked list
    nr = 0; //Sets nr to 0 to enumerate the linked list entries again
    printf("\n");
    //While there is a next entry in the linked list
    while(act_post!=NULL){
        printf("\n Post nr %d : %d" , nr++, act_post->number);
        act_post=act_post->next; //Go to the next node in the linked list
    }
    printf("\n");
    act_post = head; //Sets act_post to the head of the linked list
// --- Free the allocated memory ---
    //While there is a next entry in the linked list, this statement also assigns act_post to the top of the linked list
    while((act_post=head)!=NULL){
        head=act_post->next; //Head is now the next item in the linked list
        free(act_post); //Free the old head, I.E. where act_post points
    }
    return 0; //Return 0, indicating successfull execution
}
// ==== End of main ======================================

//Defines function random_list which returns a pointer to the head of a linked list
REGTYPE* random_list(void){
    int nr = MAX, i; //Declares variables nr and i, nr refers to the amount of random entries in the linked list, i is a control variable
    REGTYPE *top, *old, *item; //Declares pointers to REGTYPE, top will hold the head, or first item of the linked list, item is the one currently being added and old is the last one that was added

    srand(time(0)); // Random seed

    old = NULL; //Sets old to NULL so that the first item in the linked list does not have a previous node
    //Generate as many linked list items as nr/MAX specifies
    for(i = 0; i < nr; i++){
        item = malloc(sizeof(REGTYPE)); //Allocate space for one node on the heap
        item -> number = rand()%101; //Randomize the value of number
        //If old is not null, I.E. this is not the first entry in the linked list
        if(old != NULL){
            item -> prev = old; //Set the pointer that points to previous entry to old for current entry
            old -> next = item; //Set the pointer that points to next entry to current entry for the previous entry
        }
        //If this is the first entry in the linked list
        if(i==0){
            top = item; //Point top(head) to current entry
        }
        old = item; //Assigns current entry to old to be used during next iteration
    }

    return(top); //Return a pointer to the first entry of the linked list
}
//==========================================================
//Define function add_first that takes in a pointer to a REGTYPE struct(specifically the head) and an int, returns a pointer to the first entry of a linked list
REGTYPE* add_first(REGTYPE* temp, int data){
    REGTYPE* head = malloc(sizeof(REGTYPE)); //Allocate space on the heap for one node of the linked list, this will be the new head, or first entry
    head -> number = data; //Assign the value of argument data to the new nodes number field
    head -> next = temp; //Set the new heads next value to point to the previous head

    //If the previous head is not NULL, I.E. we were not given an empty linked list
    if (temp != NULL) {
        temp -> prev = head; // Set the previous heads prev field to point to the new head
    }
    return head; //Return pointer to the new head
}
