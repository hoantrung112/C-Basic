#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GenGlobalDLL.h"

void importFromDB(FILE *fptr);
void exportToDB();
void manualInsertion();
void insertPhoneAtPosition();
void deletePhoneAtPosition();
void searchAndUpdate();
void searchingOption();
int main()
{
    int choice;
    FILE *fptr;

    while (1)
    {
        printf("=============== PHONE DATABASE MENU (GENERIC GLOBAL - DOUBLY LINKED LIST) ===============\n");
        printf("1. Import DB from phoneDB.dat.\n");
        printf("2. Display database.\n");
        printf("3. Add new phone model.\n");
        printf("4. Insert at position.\n");
        printf("5. Delete at position.\n");
        printf("6. Delete current node.\n");
        printf("7. Delete first node.\n");
        printf("8. Delete last node.\n");
        printf("9. Search phone models & update.\n");
        printf("10. Reverse list.\n");
        printf("11. Save to file.\n");
        printf("12. Quit.\n");
        printf("Your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
        case (1):
            importFromDB(fptr);
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
            deleteLastElement();
            break;

        case (9):
            searchAndUpdate();
            searchingOption();
            break;

        case (10):
            reverseList();
            break;

        case (11):
            exportToDB(fptr);
            break;

        case (12):
            printf("PEACE!");
            exit(0);

        default:
            printf("Syntax error!\n");
            break;
        }
    }
}

void importFromDB(FILE *fptr)
{
    elementType tmp;
    freeList();
    if ((fptr = fopen("phoneDB.dat", "rb")) == NULL)
    {
        printf("File phoneDB.dat has yet to be created!\n");
        return;
    }
    while (fread(&tmp, sizeof(elementType), 1, fptr))
    {
        insertAfterCurrent(tmp);
    }
    printf("Linked list imported from phoneDB.dat successfully!\n");
    fclose(fptr);
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
    printf("====== Please enter 1, 2, 3 or 4 for manually inserting phone model =====\n");
    printf("1. After current node.\n");
    printf("2. Before current node.\n");
    printf("3. At head.\n");
    printf("4. At tail (appending).\n");
    scanf(" %d", &insert_choice);
    switch (insert_choice)
    {
    case 1:
        insertAfterCurrent(new_phone);
        printf("Node added after current element successfully!\n");
        break;
    case 2:
        insertBeforeCurrent(new_phone);
        printf("Node added before current element successfully!\n");
        break;
    case 3:
        insertAtHead(new_phone);
        break;
    case 4:
        insertAtTail(new_phone);
        break;
    default:
        printf("Syntax error!\n");
        break;
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
//return updated element to cur node
void searchAndUpdate()
{
    elementType tmp;
    int choice;
    printf("Enter the name of a phone model for updating: ");
    scanf(" %s", &tmp.model);
    cur = root;
    while (cur != NULL)
    {
        if (strcmp(strupr(cur->element.model), strupr(tmp.model)) == 0)
        {
            printf("\n Node found!\n");
            displayNode(cur);
            printf("Updated memory space: ");
            scanf(" %s", &tmp.memSpace);
            printf("Updated screen size space: ");
            scanf(" %s", &tmp.screenSize);
            printf("Updated price space: ");
            scanf(" %s", &tmp.price);
            printf("Are you sure to update the above node? You cannot reverse changes afterward!\n");
            printf("1.Yes\n2.No\n");
            scanf(" %d", &choice);
            if (choice == 1)
            {
                strcpy(cur->element.memSpace, tmp.memSpace);
                strcpy(cur->element.screenSize, tmp.screenSize);
                strcpy(cur->element.price, tmp.price);
                printf("Node updated successfully!\n");
                displayNode(cur);
            }
            return;
        }
        cur = cur->next;
    }
    printf("Cannot identify the phone model %s!\n", tmp.model);
    return;
}

void searchingOption()
{
    int choice;
    node *preCur;
    preCur = cur->prev;
    do
    {
        printf("Self-organising searching options:\n");
        printf("1. Move-to-front search.\n");
        printf("2. Transpose search.\n");
        printf("Please enter your choice here: \n");
        scanf("%d", &choice);
    } while (choice != 1 && choice != 2);
    // disconnect node at former position
    if (cur == tail)
    {
        preCur->next = NULL;
        tail = cur->prev;
    }
    else if (cur != root && cur != tail)
    {
        preCur->next = cur->next;
        cur->next->prev = preCur;
    }
    switch (choice)
    {
    case 1:
        // link to root node
        cur->prev = NULL;
        cur->next = root;
        root = cur;
        printf("Node moved to front successfully!\n");
        break;
    case 2:
        //link cur to new position
        preCur->prev->next = cur;
        cur->prev = preCur->prev;
        preCur->prev = cur;
        cur->next = preCur;
        printf("Node transposed successfully!\n");
        break;
    default:
        printf("Syntax Error!\n");
        break;
    }
}