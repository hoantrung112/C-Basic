#include <stdio.h>
#include <stdlib.h>

typedef int treeType;
typedef struct treeNode
{
    treeType element;
    struct treeNode *left, *right;
} treeNode;

treeNode *search(treeType ele, treeNode *root)
{
    if (root == NULL)
        return NULL;
    else if (root->element == ele)
        return root;
    else if (root->element < ele)
        return search(ele, root->right);
    else
    {
        return search(ele, root->left);
    }
}
void insertNode(treeType ele, treeNode **root)
{
    if (*root == NULL)
    {
        *root = (treeNode *)malloc(sizeof(treeNode));
        (*root)->element = ele;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else if (ele < (*root)->element)
        insertNode(ele, &(*root)->left);
    else if (ele > (*root)->element)
        insertNode(ele, &(*root)->right);
}

treeType deleteMin(treeNode **root)
{
    treeType k;
    if ((*root)->left == NULL)
    {
        k = (*root)->element;
        (*root) = (*root)->right;
        return k;
    }
    else
        return deleteMin(&(*root)->left);
}
void deleteNode(treeType ele, treeNode **root)
{
    if (*root != NULL)
    {
        if (ele < (*root)->element)
        {
            deleteNode(ele, &(*root)->left);
        }
        else if (ele > (*root)->element)
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
            (*root)->element = deleteMin(&(*root)->right);
        }
    }
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
treeNode *makeNewNode(treeType data)
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

int lowerThanKey(int key, treeNode *root)
{
    static int count = 0;
    if (root == NULL)
    {
        return -1;
    }
    lowerThanKey(key, root->left);
    if (key > root->element)
    {
        printf("%4d\n", root->element);
        count++;
        lowerThanKey(key, root->right);
    }
    return count;
}
int higherThanKey(int key, treeNode *root)
{
    static int count = 0;
    if (root == NULL)
    {
        return -1;
    }
    higherThanKey(key, root->right);
    if (key < root->element)
    {
        printf("%4d\n", root->element);
        count++;
        higherThanKey(key, root->left);
    }
    return count;
}

treeNode *findMin(treeNode *root)
{
    if (root->left != NULL)
    {
        findMin(root->left);
    }
    else
    {
        return root;
    }
}

treeNode *findMax(treeNode *root)
{
    if (root->right != NULL)
    {
        findMax(root->right);
    }
    else
    {
        return root;
    }
}