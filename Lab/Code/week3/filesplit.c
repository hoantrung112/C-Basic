#include<stdio.h>
#include<stdlib.h>
enum{SUCCESS, FAIL, MAX_LEN = 100};

int main(int argc, char* argv[]){
	FILE *fptr, *fptr1, *fptr2;
	int reval = SUCCESS;
	int i = 0;
	typedef struct {
	char name[MAX_LEN];
	char tel[MAX_LEN];
	char email[MAX_LEN];
	}contact_t;
	contact_t *contact_list;
	contact_list = (contact_t*) malloc (sizeof(contact_t) * 100);

	if(argc != 5){
		printf("Syntax error. Please try again!");
		reval = FAIL;
	}else if((fptr = fopen(argv[1], "r")) == NULL){
		printf("Cannot open file %s to read", argv[1]);
		reval = FAIL;
	}else{
		if((fptr1 = fopen(argv[3], "w")) == NULL){
		printf("Cannot open file %s to write", argv[3]);
		reval = FAIL;
		}
		if((fptr2 = fopen(argv[4], "w")) == NULL){
		printf("Cannot open file %s to write", argv[4]);
		reval = FAIL;
		}
		
		while(fscanf(fptr, "%s %s %s", contact_list[i].name, contact_list[i].tel, contact_list[i].email) != EOF){
			i++;
		}
		fwrite(contact_list, sizeof(contact_t),atoi(argv[2]), fptr1);
		fwrite(contact_list + atoi(argv[2]), sizeof(contact_t), i + 1 - atoi(argv[2]), fptr2);
		fclose(fptr);
		fclose(fptr1);
		fclose(fptr2);
		free(contact_list);
		return reval;
	}
}



 