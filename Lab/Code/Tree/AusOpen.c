#include "binTree.h"
#include <string.h>
#define MAX 30

treeNode *root;
treeNode *leaf1, *leaf2, *leaf3, *leaf4, *leaf5, *leaf6, *leaf7, *leaf8, *leaf9, *leaf10, *leaf11, *leaf12, *leaf13, *leaf14, *leaf15, *leaf16;
treeNode *leaf17, *leaf18, *leaf19, *leaf20, *leaf21, *leaf22, *leaf23, *leaf24, *leaf25, *leaf26, *leaf27, *leaf28, *leaf29, *leaf30, *leaf31, *leaf32;
void main()
{
    char player1[MAX], player2[MAX];
    FILE *fptr;
    if ((fptr = fopen("AusOpen.txt", "r")) == NULL)
    {
        printf("Cannot open file AusOpen.txt to read!\n");
        exit(1);
    }
    else
    {
        while (fgets(player1, MAX, fptr) != NULL && fgets(player2, MAX, fptr) != NULL)
        {

            if (rand() % 2)
            {
                merge2Trees()
            }
        }
    }
}