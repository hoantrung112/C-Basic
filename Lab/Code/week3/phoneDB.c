#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LENG 100
#define PAGE_LENG 30


typedef struct pDB {
	char model[MAX_LENG];
	char memSpace[MAX_LENG];
	char screenSize[MAX_LENG];
	char price[MAX_LENG];
}phonedb_t;

void importDBtext(FILE* fptr, FILE* fptr2);
void importFromDB(FILE* fptr, phonedb_t c);
void fileRead(FILE* fptr);
void phoneSearch(FILE* fptr);
int lineCount(FILE* fptr);

int main()
{
	phonedb_t p;
	int inp;
	FILE* fptr;
	FILE* fptr2;

	while (1)
	{
		printf("1. Import DB from text\n");
		printf("2. Import form DB\n");
		printf("3. Print all database\n");
		printf("4. Search phone by phone model\n");
		printf("5. Quit\n");

		scanf("%d", &inp);

		switch (inp)
		{
		case(1):
			fptr = fopen("phoneDB.txt", "r");
			fptr2 = fopen("phoneDB.dat", "wb+");
			importDBtext(fptr, fptr2);
			fclose(fptr);
			fclose(fptr2);
			break;

		case(2):
			fptr = fopen("phoneDB.dat", "rb");
			importFromDB(fptr, p);
			fclose(fptr);
			break;

		case(3):
			fptr = fopen("phoneDB.dat", "rb");
			fileRead(fptr);
			fclose(fptr);
			break;

		case(4):
			fptr = fopen("phoneDB.dat", "rb");
			phoneSearch(fptr);
			fclose(fptr);
			break;

		case(5):
			exit(1);
		}
	}
}

int lineCount(FILE* fptr)
{
	char* c;
	c = malloc(9999 * sizeof(char));

	int count = 0;
	while (fgets(c, 9999, fptr))
		count++;

	rewind(fptr);
	return count;
}
/* Import text from fptr to fptr2 */
void importDBtext(FILE* fptr, FILE* fptr2)
{
	phonedb_t *p;
	p = malloc(lineCount(fptr) * sizeof(phonedb_t));
	int i = 0;

	while (fscanf(fptr, "%s %s %s %s", p[i].model, p[i].memSpace, p[i].screenSize, p[i].price) != EOF)
	{
		i++;
	}
	fwrite(p, sizeof(phonedb_t), i, fptr2);
}

void importFromDB(FILE* fptr, phonedb_t p)
{
	FILE* txt;
	txt = fopen("phoneDB.txt", "r");
	char c;
	int n;
	char sp;
	printf("Enter F for full reading mode or P for partial reading mode: \n");
	getchar();
	scanf("%c", &c);
	if (c == 'f' || c == 'F')
	{
		while(fread(&p, sizeof(phonedb_t), 1, fptr))
			printf("%s %s %s %s \n", p.model, p.memSpace, p.screenSize, p.price);
	}
	else if (c == 'p' || c == 'P')
	{
		printf("Enter B to start form the beginning or E to start from the ending: ");
		getchar();
		scanf("%c", &sp);
		printf("Enter number of records to read: ");
		scanf("%d", &n);
		
		if (sp == 'b' || sp == 'B')
		{
			for (int i = 0; i < n; i++) {
				fread(&p, sizeof(phonedb_t), 1, fptr);
				printf("%s %s %s %s\n", p.model, p.memSpace, p.screenSize, p.price);
			}
		}

		else if (sp == 'e' || sp == 'E')
		{
			fseek(fptr, (lineCount(txt) - n) * sizeof(phonedb_t), SEEK_SET);
		
			for (int i = 0; i < n; i++) {
				fread(&p, sizeof(phonedb_t), 1, fptr);
				printf("%s %s %s %s\n", p.model, p.memSpace, p.screenSize, p.price);
			}
		}
	}
	fclose(txt);
}

void fileRead(FILE* fptr)
{
	phonedb_t p;
	while (fread(&p, sizeof(phonedb_t), 1, fptr))
		printf("%s %s %s %s\n", p.model, p.memSpace, p.screenSize, p.price);
}

void phoneSearch(FILE *fptr)
{
	char mod[MAX_LENG];
	phonedb_t p;
	int i = 0, count = 0;
	FILE* fp;
	fp = fopen("phoneDB.txt", "r");
	printf("Enter a phone model for info: ");
	getchar(); 
	scanf("%s", mod);
	for (i = 0; i < lineCount(fp); i++)
	{
		fread(&p, sizeof(phonedb_t), 1, fptr);
		if(strcmp(strupr(p.model), strupr(mod)) == 0)
			printf("%s %s %s %s\n", p.model, p.memSpace, p.screenSize, p.price);
		else
			count += 1;	
	}
	if(count == lineCount(fp))
	printf("There's no such phone model. Please try again!\n");

	fclose(fp);
}