#include<stdio.h>
#include<stdlib.h>
enum{SUCCESS, FAIL, MAX_LEN = 100};

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
int main(int argc, char* argv[]){
	FILE *fptr1, *fptr2, *fptr3;
	int reval = SUCCESS;
	int i = 0;
	typedef struct {
	char name[MAX_LEN];
	char tel[MAX_LEN];
	char email[MAX_LEN];
	}contact_t;
	contact_t *contact_list;
	contact_list = (contact_t*) malloc (sizeof(contact_t) * 100);

	if(argc != 4){
		printf("Syntax error. Please try again!");
		reval = FAIL;
	}else if((fptr1 = fopen(argv[1], "r")) == NULL){
		printf("Cannot open file %s to read", argv[1]);
		reval = FAIL;
	}else if((fptr2 = fopen(argv[2], "r")) == NULL){
		printf("Cannot open file %s to read", argv[2]);
		reval = FAIL;
	}else if((fptr3 = fopen(argv[3], "w")) == NULL){
		printf("Cannot open file %s to write", argv[3]);
		reval = FAIL;
	}else{
		while((fscanf(fptr1,"%s %s %s",contact_list[i].name, contact_list[i].tel, contact_list[i].email)) != EOF){
			i++;
		}
		while((fscanf(fptr2,"%s %s %s",contact_list[i].name, contact_list[i].tel, contact_list[i].email)) != EOF){
			i++;
		}
		fwrite(contact_list,sizeof(contact_t), i + 1, fptr3);
	}
	fclose(fptr1);
	fclose(fptr2);
	fclose(fptr3);
	free(contact_list);
	return reval;

}