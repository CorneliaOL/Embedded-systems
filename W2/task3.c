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
    PERSON ppost;
    PERSON* pPerson;
    int cont = 1;
    char menuChoice;
    char searchBy;

    while(cont == 1){
        printf("1 Create a new and delete the old file.\n");
        printf("2 Add a new person to the file.\n");
        printf("3 Search for a person in the file.\n");
        printf("4 Print out all in the file.\n");
        printf("5 Exit the program.\n");

        menuChoice = getchar();
        clearBuffer();

        switch (menuChoice) {
            case '1':
                pPerson = &ppost;
                strcpy(pPerson -> firstname, "Test");
                strcpy(pPerson -> famname, "Testfam");
                strcpy(pPerson -> pers_number, "0123456789");
                write_new_file(pPerson);
                break;
            case '2':
                append_file(createPerson());
                break;
            case '3':

                printf("Search by first name(1) or family name(2)?\n");
                searchBy = getchar();
                clearBuffer();

                if(searchBy == '1'){
                    search_by_firstname();
                } else if(searchBy == '2'){
                    search_by_famname();
                } else{
                    printf("Invalid character\n");
                }
                break;
            case '4':
                printfile();
                break;
            case '5':
                cont = 0;
                break;
            default:
                printf("Input valid option\n");
                break;
        }
    }
    return 0;
}

void printfile(void){
    FILE* pFile;
    PERSON person;

    if((pFile = fopen(filename, "rb")) == NULL){
        printf("Could not open file\n");
        return;
    }

    while(fread(&person, sizeof(PERSON), 1, pFile) != 0){
        printf("First name: %s\n", person.firstname);
        printf("Family name: %s\n", person.famname);
        printf("Personnummer %s\n", person.pers_number);
        printf("------------------\n");
    }
    fclose(pFile);
}


void search_by_firstname(void){
    char search[20];
    FILE* pFile;
    PERSON found;

    printf("Type firstname you want to search:\n");
    // scanf("%19s", search);
    // clearBuffer();
    while(read(search, sizeof(search)) != 0){
        printf("Invalid input, try again:\n");
    }


    if((pFile = fopen(filename, "rb")) == NULL){
        printf("Could not open file\n");
        return;
    }

    while (!feof(pFile)){

        if(fread(&found, sizeof(PERSON), 1, pFile) && strcmp(found.firstname, search) == 0){
            printf("First Name: %s\n", found.firstname);
            printf("Family name: %s\n", found.famname);
            printf("Personnummer: %s\n", found.pers_number);
            printf("---------------------\n");
        }
    }

    fclose(pFile);
    free(search);
}

void search_by_famname(void){
    char search[20];

    printf("Type family name you want to search:\n");
    // scanf("%19s", search);
    // clearBuffer();

    while(read(search, sizeof(search)) != 0){
        printf("Invalid input, try again:\n");
    }

    FILE* pFile;

    PERSON found;

    if((pFile = fopen(filename, "rb")) == NULL){
        printf("Could not open file\n");
        return;
    }

    while (!feof(pFile)){

        if(fread(&found, sizeof(PERSON), 1, pFile) && strcmp(found.famname, search) == 0){
            printf("First Name: %s\n", found.firstname);
            printf("Family name: %s\n", found.famname);
            printf("Personnummer: %s\n", found.pers_number);
            printf("---------------------\n");
        }
    }

    fclose(pFile);
}


void append_file(PERSON* inrecord){
    FILE* pFile;

    if((pFile = fopen(filename, "ab")) == NULL){
        printf("Could not open file\n");
        return;
    }

    fwrite(inrecord, sizeof(PERSON), 1, pFile);

    fclose(pFile);
    free(inrecord);
}

void write_new_file(PERSON* inrecord){
    FILE* pFile;

    if((pFile = fopen(filename, "wb")) == NULL){
        printf("Could not open file\n");
        return;
    }

    fwrite(inrecord, sizeof(PERSON), 1, pFile);

    fclose(pFile);

}

PERSON* createPerson(void){
    PERSON* pPerson = malloc(sizeof(PERSON));

    printf("First name?\n");
    // scanf("%19s", pPerson -> firstname);
    // clearBuffer();
    while(read(pPerson -> firstname, sizeof(pPerson -> firstname)) != 0){
        printf("Invalid input, try again:\n");
    }

    printf("Family name?\n");
    // scanf("%19s", pPerson -> famname);
    // clearBuffer();
    while(read(pPerson -> famname, sizeof(pPerson -> famname)) != 0){
        printf("Invalid input, try again:\n");
    }


    printf("Personnummber?\n");
    // scanf("%12s", pPerson -> pers_number);
    // clearBuffer();

    while(read(pPerson -> pers_number, sizeof(pPerson -> pers_number)) != 0){
        printf("Invalid input, try again:\n");
    }


    return pPerson;
}

int read(char* input, int size){
    char overFlowFlag = 1;
    if (fgets(input, size, stdin) == NULL){
        return -1;
    }

    char* iterator = input;
    while(*iterator != '\0'){
        if(*iterator == '\n'){
            *iterator = '\0';
            overFlowFlag = 0;
        }
    }

    if(overFlowFlag == 1){
        clearBuffer();
    }

    if(*input == '\0'){
        return -1;
    }

    return 0;
}

void clearBuffer(void){
    //While the current character in the buffer is not \n or EOF
    while((getchar()) != '\n' && getchar() != EOF){

    }
}
