#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 30

typedef struct treeNode
{
    char eng[MAX_LEN];
    char vie[MAX_LEN];
    struct treeNode *left, *right;
} treeNode;

treeNode *search(char ele[], treeNode *root)
{
    if (root == NULL)
        return NULL;
    else if (strcmp(root->eng, ele) == 0)
    {
        printf("%2s\n", root->eng);
        return root;
    }
    else if (strcmp(root->eng, ele) < 0)
    {
        printf("%2s\n", root->eng);
        return search(ele, root->right);
    }
    else
    {
        printf("%2s\n", root->eng);
        return search(ele, root->left);
    }
}
treeNode *search_NoPrint(char ele[], treeNode *root)
{
    if (root == NULL)
        return NULL;
    else if (strcmp(root->eng, ele) == 0)
    {
        return root;
    }
    else if (strcmp(root->eng, ele) < 0)
    {
        return search_NoPrint(ele, root->right);
    }
    else
    {
        return search_NoPrint(ele, root->left);
    }
}
void insertNode(char key[], char meaning[], treeNode **root)
{
    if (*root == NULL)
    {
        *root = (treeNode *)malloc(sizeof(treeNode));
        strcpy((*root)->eng, key);
        strcpy((*root)->vie, meaning);
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else if (strcmp(key, (*root)->eng) < 0)
        insertNode(key, meaning, &(*root)->left);
    else if (strcmp(key, (*root)->eng) > 0)
        insertNode(key, meaning, &(*root)->right);
}

void makeNullTree(treeNode **treeRoot)
{
    (*treeRoot) = NULL;
    (*treeRoot)->left = NULL;
    (*treeRoot)->right = NULL;
}
int isEmptyTree(treeNode *treeRoot)
{
    return treeRoot == NULL;
}
treeNode *leftSubTree(treeNode *node)
{
    if (node != NULL)
    {
        return node->left;
    }
    return NULL;
}
treeNode *rightSubTree(treeNode *node)
{
    if (node != NULL)
    {
        return node->right;
    }
    return NULL;
}
treeNode *makeNewNode(char data[])
{
    treeNode *tmp;
    tmp = (treeNode *)malloc(sizeof(treeNode));
    if (tmp != NULL)
    {
        tmp->left = NULL;
        tmp->right = NULL;
        strcpy(tmp->eng, data);
    }
    return tmp;
}

void preOrderPrint(treeNode *node)
{
    if (node != NULL)
    {
        printf(" %2s\n", node->eng);
        preOrderPrint(node->left);
        preOrderPrint(node->right);
    }
}
void freeTree(treeNode *node)
{
    if (node == NULL)
        return;
    freeTree(leftSubTree(node));
    freeTree(rightSubTree(node));
    free(node);
}
