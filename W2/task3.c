// (C) Lucas Holter, Cornelia Olofsson, Rizwan Rafiq, group: 18 (2024)
// Work package 2
// Exercise 3
// Submission code: 240618

//Import statements
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// -----typedefs -------
typedef struct { //Defines struct
    char firstname[20]; //Defines struct field firstname which is a character array of length 20
    char famname[20]; //Defines struct field famname which is a character array of length 20
    char pers_number[13]; // Defines struct field pers_number which is a character array of length 13, expects format: yyyymmddnnnc
} PERSON; //Name of this struct

// Function declaration (to be extend)
PERSON input_record(void); // Reads a person’s record.
void write_new_file(PERSON *inrecord); // Creates a file and writes the first record
void printfile(void); // Prints out all persons in the file
void search_by_firstname(void); // Prints out the person with the coresponding first name if present
void search_by_famname(void); // Prints out the person with the coresponding famname if present
void append_file(PERSON *inrecord); // appends a new person to the file
PERSON* createPerson(void);
void clearBuffer(void);
int read(char*, int);

#define filename "record.bin"

int main(void){
    // declare PERSON ppost
    PERSON ppost;
    // declare pointer pPerson
    PERSON* pPerson;
    // declare and initalize cont, an integer that will be used as a flag in a while loop
    int cont = 1;
    // declare integer menuChoice, will get used in switch case
    int menuChoice;
    // declare char searchBy, will get used as a critera for searching by name
    char searchBy;

    while(cont == 1){
        printf("1 Create a new and delete the old file.\n");
        printf("2 Add a new person to the file.\n");
        printf("3 Search for a person in the file.\n");
        printf("4 Print out all in the file.\n");
        printf("5 Exit the program.\n");
        
        // getchar from user input
        menuChoice = getchar();
        // clear buffer from any content, will return if space is written in the previous line
        clearBuffer();

        switch (menuChoice) {
            //Case 1: delete old file and write new file with dummy data
            case '1':
                pPerson = &ppost; //assign pointer pPerson to PERSON ppost
                strcpy(pPerson -> firstname, "Test"); //put dummy data in to pPerson (line 56-58)
                strcpy(pPerson -> famname, "Testfam");
                strcpy(pPerson -> pers_number, "0123456789");
                // use write_new_file with pPerson as a parameter to delete old file, create a new file and input the dummy data as a first record
                write_new_file(pPerson);
                break;
            //Case 2: add a new person to the end of the list    
            case '2':
                // append_file will append a new record to the file and takes a pointer to a PERSON as parameter
                // createPerson() takes user input and returns a pointer to a PERSON instance
                append_file(createPerson());
                break;
            case '3':
                // case 3: search in file by first name or family name per choice
                printf("Search by first name(1) or family name(2)?\n");
                
                searchBy = getchar(); // get user input and assign it to searchBy char
                clearBuffer(); // clear buffer from any content, will return if space is written in the previous line
                // if user inputs 1, search_by_firstname will get used
                if(searchBy == '1'){
                    search_by_firstname();
                } else if(searchBy == '2'){
                // if user inputs 2, searh_by_famname will get used    
                    search_by_famname();
                } else{
                // if user input is not 1 or 2, print "error" message
                    printf("Invalid character\n");
                }
                break;
            case '4':
            // case 4: print file. Method will print entire file to console.
                printfile();
                break;
            case '5':
            // case 4: break switch case, set flag cont to 0 to terminate the while loop
                cont = 0;
                break;
            default:
            // default print that input is not valid
                printf("Input valid option\n");
                break;
        }
    }
    //return 0 to indicate success
    return 0;
}

//method that prints entire file
void printfile(void){
    // declare a pointer pFile
    FILE* pFile;
    // declare a PERSON person
    PERSON person;

    // try to open the file. If pFile is null, print to user and return
    if((pFile = fopen(filename, "rb")) == NULL){
        printf("Could not open file\n");
        return;
    }

    //while not EOF, read and print the persons in the file
    while(fread(&person, sizeof(PERSON), 1, pFile) != 0){
        printf("First name: %s\n", person.firstname);
        printf("Family name: %s\n", person.famname);
        printf("Personnummer %s\n", person.pers_number);
        printf("------------------\n");
    }
    //close stream from pFile
    fclose(pFile);
}


void search_by_firstname(void){
   
    char search[20]; // declare char search with size 20
    FILE* pFile; // declare a file pointer
    PERSON found; // declare a PERSON person

    printf("Type firstname you want to search:\n"); 
    while(read(search, sizeof(search)) != 0){ // read input with method read, if read() returns not 0, ask for new input
        printf("Invalid input, try again:\n");
    }


    if((pFile = fopen(filename, "rb")) == NULL){ // try to open the file, if pFile is null print message and return
        printf("Could not open file\n");
        return;
    }

    while (!feof(pFile)){ // while not at end of file, continue
        // if the read person found matches the string search, print the found instance. Otherwise do nothing and continue
        if(fread(&found, sizeof(PERSON), 1, pFile) && strcmp(found.firstname, search) == 0){
            printf("First Name: %s\n", found.firstname);
            printf("Family name: %s\n", found.famname);
            printf("Personnummer: %s\n", found.pers_number);
            printf("---------------------\n");
        }
    }
    //close stream from pFile
    fclose(pFile);
}

void search_by_famname(void){
    char search[20]; // declare char search with size 20
    FILE* pFile; // declare a file pointer
    PERSON found; // declare a PERSON person

    printf("Type firstname you want to search:\n"); 
    while(read(search, sizeof(search)) != 0){ // read input with method read, if read() returns not 0, ask for new input
        printf("Invalid input, try again:\n");
    }


    if((pFile = fopen(filename, "rb")) == NULL){ // try to open the file, if pFile is null print message and return
        printf("Could not open file\n");
        return;
    }

    while (!feof(pFile)){ // while not at end of file, continue
        // if the read person found matches the string search, print the found instance. Otherwise do nothing and continue
        if(fread(&found, sizeof(PERSON), 1, pFile) && strcmp(found.famname, search) == 0){
            printf("First Name: %s\n", found.firstname);
            printf("Family name: %s\n", found.famname);
            printf("Personnummer: %s\n", found.pers_number);
            printf("---------------------\n");
        }
    }
    //close stream from pFile
    fclose(pFile);
}


void append_file(PERSON* inrecord){
    FILE* pFile; // declare pointer pFile

    // try to open a file with filename and let pointer pFile point to it. Mode ab indicates a binary file and it can be appended
    // if pFile is null, print message and return
    if((pFile = fopen(filename, "ab")) == NULL){
        printf("Could not open file\n");
        return;
    }

    // write inrecord to the file which pFile points to, with the same size as struct PERSON and 1 item.
    fwrite(inrecord, sizeof(PERSON), 1, pFile);

    //close stream from pFile
    fclose(pFile);
    //free the malloced space from pointer inrecord
    free(inrecord);
}

void write_new_file(PERSON* inrecord){
    FILE* pFile; // declare a pointer to a file pFile
    
    // try to open a file with filename and let pointer pFile point to it
    // if pFile is null, print message and return
    // wb indicates writing a new binary file
    if((pFile = fopen(filename, "wb")) == NULL){
        printf("Could not open file\n");
        return;
    }
    // write inrecord to the file which pFile points to, with the same size as struct PERSON and 1 item.
    fwrite(inrecord, sizeof(PERSON), 1, pFile);
    //close stream from pFile
    fclose(pFile);

}

PERSON* createPerson(void){
    //initialize a pointer to PERSON and malloc the size of PERSON to the pointer
    PERSON* pPerson = malloc(sizeof(PERSON));

    printf("First name?\n");
    // read input with method read, if read() returns not 0, ask for new input
    while(read(pPerson -> firstname, sizeof(pPerson -> firstname)) != 0){
        printf("Invalid input, try again:\n");
    }
    // read input with method read, if read() returns not 0, ask for new input
    printf("Family name?\n");
    while(read(pPerson -> famname, sizeof(pPerson -> famname)) != 0){
        printf("Invalid input, try again:\n");
    }

    // read input with method read, if read() returns not 0, ask for new input
    printf("Personnummber?\n");
    while(read(pPerson -> pers_number, sizeof(pPerson -> pers_number)) != 0){
        printf("Invalid input, try again:\n");
    }

    //return pointer pPerson
    return pPerson;
}

// method for reading user input
int read(char* input, int size){
    // initialize a overflow flag, will get used to clear the buffer if input is too big
    char overFlowFlag = 1;

    // use fgets and if it returns null, return -1 to indicate failure
    if (fgets(input, size, stdin) == NULL){
        return -1;
    }

    // initialize char pointer iterator to input
    char* iterator = input;
    //While the string is not at an end
    while(*iterator != '\0'){
        // check if the current character is EOL
        if(*iterator == '\n'){
        // if so, change character to null terminator
            *iterator = '\0';
        // set overFlowFlag to 0, indicating that there is no overflow
            overFlowFlag = 0;
        }
        // increase the iterator
        iterator++;
    }

    // if overFlowFlag is equal to 1, indicating overflow 
    if(overFlowFlag == 1){
        // use method clearBuffer
        clearBuffer();
    }

    // if input is null terminator, return -1 to indicate empty input
    if(*input == '\0'){
        return -1;
    }
    //return 0 to indicate success
    return 0;
}

void clearBuffer(void){
    //While the current character in the buffer is not \n or EOF
    while((getchar()) != '\n' && getchar() != EOF){
        // do nothing, continue to getChar until EOF
    }
}
