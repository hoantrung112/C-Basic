#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pdbSLL.h"

void importFromText(FILE *fptr, FILE *fptr2);
void importFromDB(FILE *fptr);
void modelSearch(FILE *fptr);
int lineCount(FILE *fptr);
void maxPriceSearch(FILE *fptr);
void exportToDB();
void manualInsertion();

int main()
{
	elementType p;
	int choice;
	FILE *fptr;
	FILE *fptr2;

	while (1)
	{
		printf("=============== PHONE DATABASE MENU ===============\n");
		printf("1. Import DB from text.\n");
		printf("2. Import from DB (phoneDB.dat).\n");
		printf("3. Print all database\n");
		printf("4. Search phone by model.\n");
		printf("5. Search phone models under inputted price.\n");
		printf("6. Export DB to .dat file.\n");
		printf("7. Manual insertion.\n");
		printf("8. Quit.\n");

		scanf("%d", &choice);

		switch (choice)
		{
		case (1):
			if ((fptr = fopen("phoneDB.txt", "r")) == NULL)
			{
				printf("Cannot open phoneDB.txt!\n");
				break;
			}
			if ((fptr2 = fopen("phoneDB.dat", "wb+")) == NULL)
			{
				printf("Cannot create phoneDB.dat!\n");
				break;
			}
			importFromText(fptr, fptr2);
			fclose(fptr);
			fclose(fptr2);
			break;

		case (2):
			if ((fptr = fopen("phoneDB.dat", "rb")) == NULL)
			{
				printf("File phoneDB.dat has yet to be created!\n");
				break;
			}
			importFromDB(fptr);
			fclose(fptr);
			break;

		case (3):
			traversingList(root);
			break;

		case (4):
			fptr = fopen("phoneDB.dat", "rb");
			modelSearch(fptr);
			fclose(fptr);
			break;

		case (5):
			fptr = fopen("phoneDB.dat", "rb");
			maxPriceSearch(fptr);
			fclose(fptr);
			break;

		case (6):
			exportToDB();
			break;

		case (7):
			manualInsertion();
			break;

		case (8):
			printf("PEACE!");
			exit(0);
		}
	}
}
// Program functions
int lineCount(FILE *fptr)
{
	char *c;
	c = malloc(9999 * sizeof(char));
	int count = 0;
	while (fgets(c, 9999, fptr))
		count++;
	rewind(fptr);
	free(c);
	return count;
}
/* Import text from fptr to fptr2 */
void importFromText(FILE *fptr, FILE *fptr2)
{
	elementType tmp;
	node *prev;
	freeList();
	while (fscanf(fptr, "%s %s %s %s", tmp.model, tmp.memSpace, tmp.screenSize, tmp.price) != EOF)
	{
		// Insert nodes from text file at the head of the list
		insertAtHead(tmp);
	}
	cur = root;
	while (cur != NULL)
	{
		fwrite(cur, sizeof(phonedb_t), 1, fptr2);
		prev = cur;
		cur = cur->next;
	}
	cur = prev;

	printf("Text file imported! Linked list created!\n");
}

void importFromDB(FILE *fptr)
{
	elementType tmp;
	freeList();
	while (fread(&tmp, sizeof(elementType), 1, fptr))
	{
		insertAfterCurrent(tmp);
	}
	printf("Linked list imported to phoneDB.dat successfully!\n");
}

void modelSearch(FILE *fptr)
{
	char search_mod[MAX_LEN];
	elementType p;
	int i = 0, count = 0;
	FILE *txtp;
	txtp = fopen("phoneDB.txt", "r");
	printf("Enter a phone model for info: ");
	getchar();
	scanf("%s", &search_mod);
	for (i = 0; i < lineCount(txtp); i++)
	{
		fread(&p, sizeof(elementType), 1, fptr);
		if (strcmp(strupr(p.model), strupr(search_mod)) == 0)
		{
			printf("%-20s %-20s %-20s %-20s\n", "Model", "Memory Space", "ScreenSize", "Price");
			printf("%-20s %-20s %-20s %-20s\n", p.model, p.memSpace, p.screenSize, p.price);
		}
		else
			count += 1;
	}
	if (count == lineCount(txtp))
		printf("There's no such phone model. Please try again!\n");

	fclose(txtp);
}
void maxPriceSearch(FILE *fptr)
{
	int maxprice, i, count = 0;
	elementType p;
	FILE *txtp;
	txtp = fopen("phoneDB.txt", "r");
	printf("Enter the max price to search for phone models:\n");
	scanf("%d", &maxprice);
	printf("Here is your result(s) for price limit of $%d\n", maxprice);
	printf("%-20s %-20s %-20s %-20s\n", "Model", "Memory Space", "ScreenSize", "Price");
	for (i = 0; i < lineCount(txtp); i++)
	{
		fread(&p, sizeof(elementType), 1, fptr);
		if (atof(p.price) <= maxprice)
		{
			printf("%-20s %-20s %-20s %-20s\n", p.model, p.memSpace, p.screenSize, p.price);
		}
		else
			count += 1;
	}
	if (count == lineCount(txtp))
		printf("There's no cheaper phone model than $%d\n", maxprice);
	fclose(txtp);
}
// return cur to root after exporting
void exportToDB()
{
	FILE *newfptr;
	newfptr = fopen("phoneDB.dat", "wb");
	cur = root;
	while (cur != NULL)
	{
		fwrite(cur, sizeof(elementType), 1, newfptr);
		cur = cur->next;
	}
	cur = root;
	printf("Linked list exported to phoneDB.dat successfully!\n");
	fclose(newfptr);
}
void manualInsertion()
{
	char insert_choice;
	elementType new_phone;
	new_phone = readNode();
	printf("====== Please enter 1 or 2 for inserting phone model =====\n");
	printf("1. After current node.\n");
	printf("2. Before current node.\n");
	scanf("%d\n", &insert_choice);

	if (insert_choice == 1)
	{
		insertAfterCurrent(new_phone);
		printf("Node added after current element successfully!\n");
	}
	else if (insert_choice == 2)
	{
		insertBeforeCurrent(new_phone);
		printf("Node added before current element successfully!\n");
	}
	else
	{
		printf("Syntax error\n");
		exit(1);
	}
}
