#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 10

typedef struct treeNode
{
    char club[MAX_LEN];
    int point;
    struct treeNode *left, *right;
} treeNode;

treeNode *search(char club[], treeNode *root)
{
    if (root == NULL)
        return NULL;
    else if (strcmp(root->club, club) == 0)
        return root;
    else if (strcmp(root->club, club) < 0)
        return search(club, root->right);
    else
    {
        return search(club, root->left);
    }
}
void insertNode(char club[],int point, treeNode **root)
{
    if (*root == NULL)
    {
        *root = (treeNode *)malloc(sizeof(treeNode));
        strcpy((*root)->club, club);
        (*root)->point = point;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else if (strcmp(club, (*root)->club) < 0)
        insertNode(club, point, &(*root)->left);
    else if (strcmp(club, (*root)->club) > 0)
        insertNode(club, point, &(*root)->right);
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
void preOrderPrint(treeNode *node)
{
    if (node != NULL)
    {
        printf("%s\t\t%d\n", node->club, node->point);
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
char *deleteMin(treeNode **root)
{
    char *k;
    if ((*root)->left == NULL)
    {
        strcpy(k, (*root)->club);
        (*root) = (*root)->right;
        return k;
    }
    else
        return deleteMin(&(*root)->left);
}
void deleteNode(char ele[], treeNode **root)
{
    if (*root != NULL)
    {
        if (strcmp(ele, (*root)->club) < 0)
        {
            deleteNode(ele, &(*root)->left);
        }
        else if (strcmp(ele, (*root)->club) > 0)
        {
            deleteNode(ele, &(*root)->right);
        }
        else if ((*root)->left == NULL && (*root)->right == NULL)
        {
            *root = NULL;
        }
        else if ((*root)->left == NULL)
        {
            *root = (*root)->right;
        }
        else if ((*root)->right == NULL)
        {
            *root = (*root)->left;
        }
        else
        {
            strcpy((*root)->club, deleteMin(&(*root)->right));
        }
    }
}
void lowerThanField(int key,treeNode *node)
{
    if (node != NULL)
    {
        if(node->point < key){
            printf("%s\n",node->club);
        }
        preOrderPrint(node->left);
        preOrderPrint(node->right);
    }
}