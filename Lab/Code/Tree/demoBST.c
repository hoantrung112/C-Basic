#include "BST-int.h"

void main()
{
    int a[10] = {4, 9, 5, 100, 26, 34, 13, 77, 1, -18};
    int i;
    treeNode *root;
    for (i = 0; i < 10; i++)
        insertNode(a[i], &root);
    printf("Min = %d\n", findMin(root)->element);
}