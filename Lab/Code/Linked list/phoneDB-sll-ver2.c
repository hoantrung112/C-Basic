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
void insertPhoneAtPosition();
void deletePhoneAtPosition();
node *divideList();

int main()
{
    int choice;
    FILE *fptr;
    FILE *fptr2;

    while (1)
    {
        printf("=============== PHONE DATABASE MENU VERSION 2 ===============\n");
        printf("1. Import DB from phoneDB.dat.\n");
        printf("2. Display database.\n");
        printf("3. Add new phone model.\n");
        printf("4. Insert at position.\n");
        printf("5. Delete at position.\n");
        printf("6. Delete current node.\n");
        printf("7. Delete first node.\n");
        printf("8. Search phone models & update.\n");
        printf("9. Divide and extract.\n");
        printf("10. Reverse list.\n");
        printf("11. Save to file.\n");
        printf("12. Search phone models under inputted price.\n");
        printf("13. Quit.\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case (1):
            if ((fptr = fopen("phoneDB.dat", "rb")) == NULL)
            {
                printf("File phoneDB.dat has yet to be created!\n");
                break;
            }
            importFromDB(fptr);
            fclose(fptr);
            break;

        case (2):
            traversingList(root);
            break;

        case (3):
            manualInsertion();
            break;

        case (4):
            insertPhoneAtPosition();
            break;

        case (5):
            deletePhoneAtPosition();
            break;

        case (6):
            deleteCurrentElement();
            break;

        case (7):
            deleteFirstElement();
            break;

        case (8):
            fptr = fopen("phoneDB.dat", "rb");
            modelSearch(fptr);
            fclose(fptr);
            break;

        case (9):
            traversingList(divideList());
            printf("The sublist 2 is as follows:\n");
            traversingList(root);
            break;

        case (10):
            reverseList();
            break;

        case (11):
            exportToDB(fptr);
            break;

        case (12):
            fptr = fopen("phoneDB.dat", "rb");
            maxPriceSearch(fptr);
            fclose(fptr);
            break;

        case (13):
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
void insertPhoneAtPosition()
{
    int n;
    elementType tmp = readNode();
    printf("Enter (non-negative) position to insert new model:\n");
    scanf(" %d", &n);
    cur = insertAtPostion(root, tmp, n);
}
void deletePhoneAtPosition()
{
    int n;
    printf("Enter (non-negative) position to delete model:\n");
    scanf(" %d", &n);
    cur = deleteAtPostion(root, n);
}
node *divideList()
{
    node *root_sl1;
    int start_index, num;
    printf("Enter the starting index of sublist 1:\n");
    scanf("%d", &start_index);
    printf("Enter the number of phone models of sublist 1:\n");
    scanf("%d", &num);
    root_sl1 = splitList(root, start_index, num);
    printf("The sublist 1 is as follows:\n");
    return root_sl1;
}