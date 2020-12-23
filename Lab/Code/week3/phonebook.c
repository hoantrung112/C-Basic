#include<stdio.h>
#include<stdlib.h>
#define MAX_LEN 100

typedef struct {
	char name[MAX_LEN];
	char tel[MAX_LEN];
	char email[MAX_LEN];
}contact_t;

int lineCount(FILE* fptr);
int main(){
    FILE *fptr, *fptr0;
    int i = 0;
    contact_t contact_list[MAX_LEN + 1];
    if((fptr = fopen("phonebook.txt", "r")) == NULL){
        printf("Cannot open file text to import!\n");
        exit(1);
    }else {
        while(fscanf(fptr, "%s %s %s", contact_list[i].name, contact_list[i].tel, contact_list[i].email) != EOF){
            i++;
        }
    }
    fptr0 = fopen("phonebook.dat", "w+");
    fwrite(contact_list, sizeof(contact_t), i, fptr0);
    return 0;
}
int lineCount(FILE* fptr)
{
	char* c;
	c = malloc(5 * MAX_LEN * sizeof(char));
	int count = 0;
	while (fgets(c, 5 * MAX_LEN, fptr))
		count++;
	rewind(fptr);
	return count;
}
