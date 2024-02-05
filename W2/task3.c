#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// -----typedefs -------
typedef struct {
    char firstname[20];
    char famname[20];
    char pers_number[13]; // yyyymmddnnnc
} PERSON;
// Function declaration (to be extend)
PERSON input_record(void); // Reads a person’s record.
void write_new_file(PERSON *inrecord); // Creates a file and writes the first record
void printfile(void); // Prints out all persons in the file
void search_by_firstname(char *name); // Prints out the person if in list
void append_file(PERSON *inrecord); // appends a new person to the file
PERSON* createPerson();
char* get_name_to_search();
void clearBuffer();

#define filename "record.bin"

int main(void){
    PERSON ppost;
    PERSON* pPerson;
    int cont = 1;
    int menuChoice;

    while(cont == 1){
        printf("1 Create a new and delete the old file.\n");
        printf("2 Add a new person to the file.\n");
        printf("3 Search for a person in the file.\n");
        printf("4 Print out all in the file.\n");
        printf("5 Exit the program.\n");

        scanf("%2d", &menuChoice);
        clearBuffer();

        switch (menuChoice) {
            case 1:
                pPerson = &ppost;
                strcpy(pPerson -> firstname, "Test");
                strcpy(pPerson -> famname, "Testfam");
                strcpy(pPerson -> pers_number, "0123456789");
                write_new_file(pPerson);
                break;
            case 2:
                append_file(createPerson());
                break;
            case 3:
                search_by_firstname(get_name_to_search());
                break;
            case 4:
                printfile();
                break;
            case 5:
                cont = 0;
                break;
            default:
                printf("Input valid option\n");
                break;
        }
    }
    return 0;
}

void printfile(){
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

char* get_name_to_search(){
    char* search = malloc(20);

    printf("Type firstname you want to search:\n");
    scanf("%19s", search);
    clearBuffer();


    return search;
}

void search_by_firstname(char* name){
    FILE* pFile;

    PERSON found;

    if((pFile = fopen(filename, "rb")) == NULL){
        printf("Could not open file\n");
        return;
    }

    while (!feof(pFile)){

        if(fread(&found, sizeof(PERSON), 1, pFile) && strcmp(found.firstname, name) == 0){
            printf("First Name: %s\n", found.firstname);
            printf("Family name: %s\n", found.famname);
            printf("Personnummer: %s\n", found.pers_number);
            printf("---------------------\n");
        }
    }

    fclose(pFile);
    free(name);
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

PERSON* createPerson(){

    PERSON* pPerson = malloc(sizeof(PERSON));

    printf("First name?\n");
    scanf("%19s", pPerson -> firstname);
    clearBuffer();


    printf("Family name?\n");
    scanf("%19s", pPerson -> famname);
    clearBuffer();


    printf("Personnummber?\n");
    scanf("%12s", pPerson -> pers_number);
    clearBuffer();


    return pPerson;
}

void clearBuffer(){
    //While the current character in the buffer is not \n or EOF
    while((getchar()) != '\n' && getchar() != EOF){

    }
}
