#include <stdio.h>
#include <stdlib.h>

typedef struct phoneadress_t
{
	char name[20];
	char tel[11];
	char email[25];
} phoneadress;

void fileSplit(FILE *fptr, int n, FILE *fptr1, FILE *fptr2);

int main(int argc, char *argv[])
{
	FILE *fptr;
	FILE *fptr1;
	FILE *fptr2;
	int n;
	if (argc != 5)
		printf("Wrong syntax!!!\nCorrect syntax:phonebook file.dat n file.dat1 file.dat2\n");

	if ((fptr = fopen(argv[1], "rb")) == NULL)
	{
		printf("There is no such file!!");
		exit(1);
	}

	fptr1 = fopen(argv[3], "wb+");
	fptr2 = fopen(argv[4], "wb+");

	n = atoi(argv[2]);

	fileSplit(fptr, n, fptr1, fptr2);
}

void fileSplit(FILE *fptr, int n, FILE *fptr1, FILE *fptr2)
{
	phoneadress *pad;
	int count = 0;

	while (fread(pad, sizeof(pad), 1, fptr))
	{
		count++;
		if (count <= n)
			fwrite(pad, sizeof(pad), 1, fptr1);
		if (count > n)
			fwrite(pad, sizeof(pad), 1, fptr2);
	}

	fclose(fptr);
	fclose(fptr2);
	fclose(fptr1);
}

void fileMerge(FILE *fptr, FILE *fptr1, FILE *fptr2)
{
	fclose(fptr);
	fclose(fptr2);
	fclose(fptr1);
	phoneadress *pad;

	fptr = fopen(fptr, "ab");
	fptr1 = fopen(fptr1, "rb");
	fptr2 = fopen(fptr2, "rb");

	while (fread(pad, sizeof(pad), 1, fptr1))
		fwrite(pad, sizeof(pad), 1, fptr);

	while (fread(pad, sizeof(pad), 1, fptr2))
		fwrite(pad, sizeof(pad), 1, fptr);

	fclose(fptr);
	fclose(fptr2);
	fclose(fptr1);
}

void fileRead(FILE *fptr)
{
	phoneadress phonearr;

	int n = 31;
	int i = 0;

	while ((fread(&phonearr, sizeof(phoneadress), 1, fptr)))
	{
		i++;
		printf("%s-%s-%s %d\n", phonearr.name, phonearr.tel, phonearr.email, i);
	}
	fclose(fptr);
}
