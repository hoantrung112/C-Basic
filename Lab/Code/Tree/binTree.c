#include "binTree.h"

void main()
{
    int choice;
    treeNode *root = NULL;
    treeNode *node1 = NULL;
    treeNode *node2 = NULL;
    treeNode *node3 = NULL;
    treeNode *node4 = NULL;
    treeNode *node5 = NULL;
    treeNode *node6 = NULL;
    treeNode *node7 = NULL;
    treeNode *node8 = NULL;
    treeNode *node9 = NULL;
    treeNode *node10 = NULL;
    root = makeNewNode(0);
    node1 = insertLeftmost(&root, 1);
    node2 = insertRightmost(&root, 2);
    node3 = insertLeftmost(&root, 3);
    node4 = insertRightmost(&node1, 4);
    node5 = insertLeftmost(&node2, 5);
    node6 = insertRightmost(&root, 6);
    node7 = insertLeftmost(&root, 7);
    node8 = insertRightmost(&node4, 8);
    node9 = insertRightmost(&node5, 9);
    node10 = insertRightmost(&node6, 10);

    while (1)
    {
        printf("========== Some special tree operations ==========\n");
        printf("1. Return the height of binary tree.\n");
        printf("2. Return the number of leaves.\n");
        printf("3. Return the number of internal nodes.\n");
        printf("4. Return the number of right children.\n");
        printf("5. Exit.\n");
        printf("Enter your choice here:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("The height of given tree is %d.\n", treeDepth(root));
            break;
        case 2:
            printf("The number of leaves of given tree is %d.\n", leafCount(root));
            break;
        case 3:
            printf("The number of internal nodes of given tree is %d.\n", internalCount(root));
            break;
        case 4:
            printf("The number of right children of given tree is %d.\n", rightNodeCount(root));
            break;
        case 5:
            printf("Exiting program...\n");
            exit(1);
            break;
        default:
            printf("Please entere a number from 1->5");
            break;
        }
    }
}