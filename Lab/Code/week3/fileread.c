#include<stdio.h>
#include<stdlib.h>
enum{SUCCESS, FAIL, MAX_LEN = 100};


int main(int argc, char* argv[]){
	FILE *fptr;
	int reval = SUCCESS;
	int i = 0, line;

	typedef struct {
	char name[MAX_LEN];
	char tel[MAX_LEN];
	char email[MAX_LEN];
	}contact_t;

	contact_t *contact_list;
	contact_list = (contact_t*) malloc (sizeof(contact_t) * 100);

	if(argc != 2){
		printf("Syntax error. Please try again!");
		reval = FAIL;
	}else if((fptr = fopen(argv[1], "rb")) == NULL){
		printf("Cannot open file %s to read", argv[1]);
		reval = FAIL;
	}else{
		while((fscanf(fptr,"%s %s %s",contact_list[i].name, contact_list[i].tel, contact_list[i].email)) != EOF){
			printf("%s %s %s\n", contact_list[i].name, contact_list[i].tel, contact_list[i].email);
			i++;
		}
	}
	fclose(fptr);
	free(contact_list);
	return reval;
}