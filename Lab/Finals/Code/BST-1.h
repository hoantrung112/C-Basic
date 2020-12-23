#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 15

typedef struct treeNode
{
    char username[MAX_LEN];
    char password[MAX_LEN];
    double score;
    struct treeNode *left, *right;
} treeNode;

treeNode *search(char username[], treeNode *root)
{
    if (root == NULL)
        return NULL;
    else if (strcmp(root->username, username) == 0)
        return root;
    else if (strcmp(root->username, username) < 0)
        return search(username, root->right);
    else
    {
        return search(username, root->left);
    }
}
void insertNode(char username[], char password[], double score, treeNode **root)
{
    if (*root == NULL)
    {
        *root = (treeNode *)malloc(sizeof(treeNode));
        strcpy((*root)->username, username);
        strcpy((*root)->password, password);
        (*root)->score = score;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else if (strcmp(username, (*root)->username) < 0)
        insertNode(username, password, score, &(*root)->left);
    else if (strcmp(username, (*root)->username) > 0)
        insertNode(username, password, score, &(*root)->right);
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
        printf("%s\t\t%s\t\t%lf\n", node->username, node->password, node->score);
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
        strcpy(k, (*root)->username);
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
        if (strcmp(ele, (*root)->username) < 0)
        {
            deleteNode(ele, &(*root)->left);
        }
        else if (strcmp(ele, (*root)->username) > 0)
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
            strcpy((*root)->username, deleteMin(&(*root)->right));
        }
    }
}
