#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pdbSLL.h"

void importDBtext(FILE *fptr, FILE *fptr2);
void importFromDB(FILE *fptr);
void fileRead(FILE *fptr);
void modelSearch(FILE *fptr);
int lineCount(FILE *fptr);
void displayNode(node_pmd_t *p);
void traversingList();
phonedb_t readNode();
node_pmd_t *makeNewNode(phonedb_t pmd);
void insertAtHead(phonedb_t pmd);
void insertAfterCurrent(phonedb_t pmd);
void insertBeforeCurrent(phonedb_t addr);
void maxPriceSearch(FILE *fptr);
void exportToDB();
void manualInsertion();

int main()
{
	phonedb_t p;
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
			importDBtext(fptr, fptr2);
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
			traversingList();
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
			//fptr = fopen("phoneDB.dat", "r+b");
			exportToDB(fptr);
			//fclose(fptr);
			break;
		case (7):
			manualInsertion();
			break;
		case (8):
			exit(1);
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
void importDBtext(FILE *fptr, FILE *fptr2)
{
	phonedb_t tmp;
	node_pmd_t *prev;

	while (fscanf(fptr, "%s %s %s %s", tmp.model, tmp.memSpace, tmp.screenSize, tmp.price) != EOF)
	{
		// Insert nodes from text file at the head of the list
		insertAtHead(tmp);
	}
	// traversingList();
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
	phonedb_t tmp;
	while (fread(&tmp, sizeof(phonedb_t), 1, fptr))
	{
		insertAfterCurrent(tmp);
	}
	traversingList();
}

void fileRead(FILE *fptr)
{
	phonedb_t p;
	while (fread(&p, sizeof(phonedb_t), 1, fptr))
		printf("%s %s %s %s\n", p.model, p.memSpace, p.screenSize, p.price);
}

void modelSearch(FILE *fptr)
{
	char search_mod[MAX_LEN];
	phonedb_t p;
	int i = 0, count = 0;
	FILE *txtp;
	txtp = fopen("phoneDB.txt", "r");
	printf("Enter a phone model for info: ");
	getchar();
	scanf("%s", &search_mod);
	for (i = 0; i < lineCount(txtp); i++)
	{
		fread(&p, sizeof(phonedb_t), 1, fptr);
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
	phonedb_t p;
	FILE *txtp;
	txtp = fopen("phoneDB.txt", "r");
	printf("Enter the max price to search for phone models:\n");
	scanf("%d", &maxprice);
	printf("Here is your result(s) for price limit of $%d\n", maxprice);
	printf("%-20s %-20s %-20s %-20s\n", "Model", "Memory Space", "ScreenSize", "Price");
	for (i = 0; i < lineCount(txtp); i++)
	{
		fread(&p, sizeof(phonedb_t), 1, fptr);
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
void exportToDB()
{
	remove("phoneDB.dat");
	FILE *newfptr;
	newfptr = fopen("phoneDB.dat", "wb");
	cur = root;
	while (cur != NULL)
	{
		fwrite(cur, sizeof(phonedb_t), 1, newfptr);
		cur = cur->next;
	}
	cur = root;
	fclose(newfptr);
}
void manualInsertion()
{
	char insert_choice;
	phonedb_t new_phone = readNode();

	printf("Enter 'b' or 'a' for inserting before or after current element: \n");
	scanf(" %c", &insert_choice);
	printf("%c\n", insert_choice);

	printf("hello1\n");
	if (insert_choice == 'A' || insert_choice == 'a')
	{
		insertAfterCurrent(new_phone);
		printf("Node added after current element successfully!\n");
	}
	else if (insert_choice == 'B' || insert_choice == 'b')
	{
		insertBeforeCurrent(new_phone);
		printf("Node added after before element successfully!\n");
	}
	else
	{
		printf("Syntax error\n");
		exit(1);
	}
}

// Linked-list-related functions
phonedb_t readNode()
{
	phonedb_t tmp;
	printf("Enter the phone model:");
	scanf("%s", &tmp.model);
	printf("Enter the phone's memory space(GB):");
	scanf("%s", &tmp.memSpace);
	printf("Enter the phone's screen size:");
	scanf("%s", &tmp.screenSize);
	printf("Enter the phone's price:");
	scanf("%s", &tmp.price);
	return tmp;
}
node_pmd_t *makeNewNode(phonedb_t pmd)
{
	node_pmd_t *new = (node_pmd_t *)malloc(sizeof(node_pmd_t));
	new->pmd = pmd;
	new->next = NULL;
	return new;
}

void insertAtHead(phonedb_t pmd)
{
	node_pmd_t *new = makeNewNode(pmd);
	new->next = root;
	root = new;
	cur = root;
}
void displayNode(node_pmd_t *p)
{
	if (p == NULL)
	{
		printf("ERROR! NULL pointer!\n");
		return;
	}
	phonedb_t tmp = p->pmd;
	printf("%-20s %-20s %-20s %-20s %-20p\n", tmp.model, tmp.memSpace, tmp.screenSize, tmp.price, p->next);
}
void traversingList()
{
	node_pmd_t *p;
	if (root == NULL || !root)
	{
		printf("There's no element in the list!");
		return;
	}
	printf("%-20s %-20s %-20s %-20s\n", "Model", "Memory Space", "ScreenSize", "Price");
	for (p = root; p != NULL; p = p->next)
		displayNode(p);
}
void insertAfterCurrent(phonedb_t pmd)
{
	node_pmd_t *new = makeNewNode(pmd);
	if (cur == NULL)
	{
		printf("Cannot identify current element in the list.\n");
		return;
	}
	if (root == NULL)
	{
		/* if there is no element */
		root = new;
		cur = root;
		printf("No element in the list. Node put at root!\n");
	}
	else
	{
		new->next = cur->next;
		cur->next = new;
		prev = cur;
		cur = new;
	}
}
void insertBeforeCurrent(phonedb_t addr)
{
	node_pmd_t *new = makeNewNode(addr);
	if (root == NULL)
	{
		/* if there is no element */
		root = new;
		cur = root;
		prev = NULL;
		printf("No element in the list. Node put at root!\n");
	}
	else
	{
		if (cur == root)
		{
			new->next = cur;
			root = new;
			cur = root;
		}
		else
		{
			new->next = cur;
			prev->next = new;
			cur = prev->next;
		}
	}
}