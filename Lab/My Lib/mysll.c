#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GenSLL.h"

int main()
{
    FILE *fptr;
    int start_index, num;
    printf("============ Test function displayNode ============ \n");
    elementType tmp = readNode();
    root = makeNewNode(tmp);
    displayNode(root);

    printf("============ Test function insertAfterCurrent ============ \n");
    elementType tmp1 = readNode();
    cur = root;
    insertAfterCurrent(tmp1);
    traversingList(root);

    printf("============ Test function insertBeforeCurrent ============ \n");
    elementType tmp2 = readNode();
    insertBeforeCurrent(tmp2);
    traversingList(root);

    printf("============ Test function insertAtHead ============ \n");
    elementType tmp3 = readNode();
    insertAtHead(tmp3);
    traversingList(root);

    printf("============ Test function  splitList============ \n");
    printf("Enter starting index of sublist1:");
    scanf("%d", &start_index);
    printf("Enter the number of nodes of sublist1:");
    scanf("%d", &num);
    node *sublist1 = splitList(start_index, num);
    printf("The sublist 1 is as follows:\n");
    traversingList(sublist1);
    printf("The sublist 2 is as follows:\n");
    //root = NULL;
    traversingList(root);

    // printf("============ Test function printList ============ \n");
    // if ((fptr = fopen("demoPrintList.txt", "w")) == NULL)
    // {
    //     printf("Cannot open file to print the list!\n");
    // }
    // else
    // {
    //     fprintf(fptr,"Sublist 1 is as follows:\n");
    //     printList(sublist1, fptr);
    //     fprintf(fptr,"Sublist 2 is as follows:\n");
    //     printList(root, fptr);
    // }

    // printf("============ Test function deleteFirstElement ============ \n");
    // deleteFirstElement();
    // traversingList(root);

    printf("============ Test function insertAfterCurrent ============ \n");
    elementType tmp10 = readNode();
    cur = root;
    insertAfterCurrent(tmp10);
    traversingList(root);

    // printf("============ Test function deleteCurrentElement ============ \n");
    // deleteCurrentElement();
    // traversingList(root);

    printf("============ Test function insertAtPosition============ \n");
    elementType tmp4 = readNode();
    int j;
    printf("Which index to insert node after?\n");
    scanf("%d", &j);
    insertAtPostion(root, tmp4, j);
    traversingList(root);

    // printf("============ Test function deleteAtPosition============ \n");
    // int delatpos;
    // printf("Enter a position to delete:");
    // scanf("%d", &delatpos);
    // deleteAtPostion(root,delatpos);
    // traversingList(root);

    // printf("============ Test function  swapNodes============ \n");
    // char email[25];
    // printf("Enter email1: ");
    // scanf("%s", email);
    // node *A = getNodeByKey(email);
    // printf("Enter email2: ");
    // scanf("%s", email);
    // node *B = getNodeByKey(email);
    // swapNodes(A, B);
    // traversingList(root);

    printf("============ Test function reverseList============ \n");
    reverseList();
    traversingList(root);

    printf("============ Test function freeList============ \n");
    freeList();
    traversingList(root);

    return 0;
}
