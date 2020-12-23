#include <stdio.h>
#include <stdlib.h>

typedef int elementType;
typedef struct node
{
    elementType element;
    struct node *left, *right;
} treeNode;

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
treeNode *makeNewNode(elementType data)
{
    treeNode *tmp;
    tmp = (treeNode *)malloc(sizeof(treeNode));
    if (tmp != NULL)
    {
        tmp->left = NULL;
        tmp->right = NULL;
        tmp->element = data;
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
treeNode *merge2Trees(elementType data, treeNode *left, treeNode *right)
{
    treeNode *tmp;
    tmp = (treeNode *)malloc(sizeof(treeNode));
    tmp->element = data;
    tmp->left = left;
    tmp->right = right;
    return tmp;
}

treeNode *insertLeftmost(treeNode **treeRoot, elementType data)
{
    treeNode *newNode = makeNewNode(data);
    if (newNode == NULL)
        return newNode;
    if (*treeRoot == NULL)
        *treeRoot = newNode;
    else
    {
        treeNode *leftNode = *treeRoot;
        while (leftNode->left != NULL)
        {
            leftNode = leftNode->left;
        }
        leftNode->left = newNode;
        newNode->left = newNode->right = NULL;
    }
    return newNode;
}
treeNode *insertRightmost(treeNode **treeRoot, elementType data)
{
    treeNode *newNode = makeNewNode(data);
    if (newNode == NULL)
        return newNode;
    if (*treeRoot == NULL)
        *treeRoot = newNode;
    else
    {
        treeNode *rightNode = *treeRoot;
        while (rightNode->right != NULL)
        {
            rightNode = rightNode->right;
        }
        rightNode->right = newNode;
        newNode->left = newNode->right = NULL;
    }
    return newNode;
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
void inOrderPrint(treeNode *node)
{
    if (node != NULL)
    {
        inOrderPrint(node->left);
        printf("%4d\n", node->element);
        inOrderPrint(node->right);
    }
}
void postOrderPrint(treeNode *node)
{
    if (node != NULL)
    {
        postOrderPrint(node->left);
        postOrderPrint(node->right);
        printf("%4d\n", node->element);
    }
}
void preOrderPrint(treeNode *node)
{
    if (node != NULL)
    {
        printf("%4d\n", node->element);
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