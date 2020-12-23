#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int choice = 0;
void main()
{
    while (choice != 5)
    {
        printf("==============  MENU ============== \n");
        printf("1. .\n");
        printf("2. .\n");
        printf("3. .\n");
        printf("4. .\n");
        printf("5. Exit.\n");
        printf("Please enter your choice here:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            break;
        case 2:

            break;
        case 3:
            relegatedTeams();
            break;
        case 4:

            break;
        case 5:
            printf("Exiting program..................\n");
            //free memory
            exit(1);
            break;
        default:
            printf("Please enter a number from 1-4!\n");
            break;
        }
    }

    return 0;
}

// BST
// #include"BST.h"
// treeNode *root;

//Queue
// #include"queueCircular.h"
// queue* q;
// makeNullQueue(q)

//stack
// #include"stackarr.h"
// stackType st;
// initialize(st);

//LL
// #include"GenSLL.h"

//useful functions

// int lineCount(FILE *fptr)
// {
//     char *c;
//     c = malloc(9999 * sizeof(char));
//     int count = 0;
//     while (fgets(c, 9999, fptr))
//         count++;
//     rewind(fptr);
//     free(c);
//     return count;
// }


// void importFromDB(FILE *fptr)
// {
// 	elementType tmp;
// 	freeList();
// 	while (fread(&tmp, sizeof(elementType), 1, fptr))
// 	{
// 		insertAfterCurrent(tmp);
// 	}
// 	printf("Linked list imported to phoneDB.dat successfully!\n");
// }


// void exportToDB()
// {
// 	FILE *newfptr;
// 	newfptr = fopen("phoneDB.dat", "wb");
// 	cur = root;
// 	while (cur != NULL)
// 	{
// 		fwrite(cur, sizeof(elementType), 1, newfptr);
// 		cur = cur->next;
// 	}
// 	cur = root;
// 	printf("Linked list exported to phoneDB.dat successfully!\n");
// 	fclose(newfptr);
// }