#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 15

typedef struct treeNode
{
    char element[MAX_LEN];
    struct treeNode *left, *right;
} treeNode;

treeNode *search(char element[], treeNode *root)
{
    if (root == NULL)
        return NULL;
    else if (strcmp(root->element, element) == 0)
        return root;
    else if (strcmp(root->element, element) < 0)
        return search(element, root->right);
    else
    {
        return search(element, root->left);
    }
}
void insertNode(char element[], treeNode **root)
{
    if (*root == NULL)
    {
        *root = (treeNode *)malloc(sizeof(treeNode));
        strcpy((*root)->element, element);
        // strcpy((*root)->password, password);
        // (*root)->score = score;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else if (strcmp(element, (*root)->element) < 0)
        insertNode(element, &(*root)->left);
    else if (strcmp(element, (*root)->element) > 0)
        insertNode(element, &(*root)->right);
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
        strcpy(tmp->element, data);
    }
    return tmp;
}
int isLeaf(treeNode *node)
{
    if (node != NULL)
    {
        return (leftSubTree == NULL && rightSubTree == NULL);
    }
    return -1;
}
int nodeCount(treeNode *treeRoot)
{
    if (isEmptyTree(treeRoot))
    {
        return 0;
    }
    else
    {
        return (1 + nodeCount(leftSubTree(treeRoot)) + nodeCount((treeRoot)));
    }
}
int treeDepth(treeNode *node)
{
    int leftDepth = 0;
    int rightDepth = 0;
    if (node == NULL)
        return 0;
    else
    {
        leftDepth = treeDepth(node->left);
        rightDepth = treeDepth(node->right);

        if (leftDepth > rightDepth)
            return (leftDepth + 1);
        else
            return (rightDepth + 1);
    }
}
int leafCount(treeNode *treeRoot)
{
    if (treeRoot == NULL)
        return 0;
    else if (treeRoot->left == NULL && treeRoot->right == NULL)
        return 1;
    else
        return leafCount(treeRoot->left) + leafCount(treeRoot->right);
}
int internalCount(treeNode *node)
{
    if (node == NULL || (node->left == NULL && node->right == NULL))
    {
        return 0;
    }
    return 1 + internalCount(node->left) + internalCount(node->right);
}
int rightNodeCount(treeNode *node)
{
    if (isEmptyTree(node))
        return 0;
    if (node->right == NULL)
        return rightNodeCount(node->left);
    return 1 + rightNodeCount(node->left) + rightNodeCount(node->right);
}
int leftNodeCount(treeNode *node)
{
    if (isEmptyTree(node))
        return 0;
    if (node->left == NULL)
        return leftNodeCount(node->right);
    return 1 + leftNodeCount(node->right) + leftNodeCount(node->left);
}
void inOrderPrint(treeNode *node)
{
    if (node != NULL)
    {
        inOrderPrint(node->left);
        printf("%4s\n", node->element);
        inOrderPrint(node->right);
    }
}
void postOrderPrint(treeNode *node)
{
    if (node != NULL)
    {
        postOrderPrint(node->left);
        postOrderPrint(node->right);
        printf("%4s\n", node->element);
    }
}
void preOrderPrint(treeNode *node)
{
    if (node != NULL)
    {
        printf("%4s\n", node->element);
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
        strcpy(k, (*root)->element);
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
        if (strcmp(ele, (*root)->element) < 0)
        {
            deleteNode(ele, &(*root)->left);
        }
        else if (strcmp(ele, (*root)->element) > 0)
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
            strcpy((*root)->element, deleteMin(&(*root)->right));
        }
    }
}
int lowerThanKey(char key[], treeNode *root)
{
    static int count = 0;
    if (root == NULL)
    {
        return -1;
    }
    lowerThanKey(key, root->left);
    if (strcmp(key, root->element) > 0)
    {
        printf("%4s\n", root->element);
        count++;
        lowerThanKey(key, root->right);
    }
    return count;
}
int higherThanKey(char key[], treeNode *root)
{
    static int count = 0;
    if (root == NULL)
    {
        return -1;
    }
    higherThanKey(key, root->right);
    if (strcmp(key, root->element) < 0)
    {
        printf("%4s\n", root->element);
        count++;
        higherThanKey(key, root->left);
    }
    return count;
}
