#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100

//------GENERIC DOUBLY LINKED LIST HEADER FILE--------
//------IN ORDER TO REUSE CODE, EDITING THE FOLLOWING STRUCT AND FUNCS ACCORDINGLY--------
// readNode, displayNode, structCmp, printList
typedef struct phoneDB
{
    char model[MAX_LEN];
    char memSpace[MAX_LEN];
    char screenSize[MAX_LEN];
    char price[MAX_LEN];
} phonedb_t;
typedef phonedb_t elementType;
typedef struct node node;
struct node
{
    elementType element;
    struct node *next;
    struct node *prev;
};

node *root, *tail, *cur;

void makeNullList();
int isEmpty(node *root);
node *makeNewNode(elementType student);
elementType readNode();
void displayNode(node *p);
void traversingList(node *root);
void insertAtHead(elementType ele);
void insertAtTail(elementType ele);
void insertAfterCurrent(elementType ele);
void insertBeforeCurrent(elementType ele);
node *insertAtPostion(node *root, elementType element, int n);
void deleteFirstElement();
void deleteLastElement();
void deleteCurrentElement();
node *deleteAtPostion(node *root, int n);
void deleteElement(elementType ele);
int structCmp(elementType element1, elementType element2);
void freeList();
void reverseList();
node *splitList(node *root, int start_index, int num);
void printList(node *root, FILE *fptr);

void makeNullList()
{
    root = NULL;
    tail = NULL;
    cur = NULL;
}

int isEmpty(node *root)
{
    return (root == NULL);
}

node *makeNewNode(elementType ele)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->element = ele;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

elementType readNode()
{
    elementType tmp;
    printf("Enter the phone model:");
    scanf("%s", &tmp.model);
    printf("Enter the phone's memory space(GB):");
    scanf("%s", &tmp.memSpace);
    printf("Enter the phone's screen size:");
    scanf("%s", &tmp.screenSize);
    printf("Enter the phone's price:");
    scanf("%s", &tmp.price);
    return tmp;
}

void displayNode(node *p)
{
    if (p == NULL)
    {
        printf("ERROR! NULL pointer!\n");
        return;
    }
    elementType tmp = p->element;
    printf("%-20s %-20s %-20s %-20s %p\n", tmp.model, tmp.memSpace, tmp.screenSize, tmp.price, p->next);
}
void traversingList(node *root)
{
    node *p;
    if (root == NULL || !root)
    {
        printf("There's no element in the list!\n");
        return;
    }
    for (p = root; p != NULL; p = p->next)
        displayNode(p);
}
//Return cur ptr to root
void insertAtHead(elementType ele)
{
    node *newNode = makeNewNode(ele);
    if (root == NULL)
    {
        root = newNode;
        tail = newNode;
        cur = newNode;
    }
    else
    {
        newNode->next = root;
        root->prev = newNode;
        root = newNode;
        cur = root;
    }
    printf("Node inserted at head successfully!\n");
}
//Return cur ptr to tail
void insertAtTail(elementType ele)
{
    node *newNode = makeNewNode(ele);
    if (tail == NULL)
    {
        root = newNode;
        tail = newNode;
        cur = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    cur = tail;
    printf("Node inserted at tail successfully!\n");
}
//Return cur ptr to newly added node
void insertAfterCurrent(elementType ele)
{
    node *newNode = makeNewNode(ele);
    if (root == NULL)
    {
        printf("Cannot identify root node! Node put at head!\n");
        root = newNode;
        cur = newNode;
        tail = newNode;
    }
    else if (cur == NULL)
    {
        printf("Cannot identify current node!\n");
        return;
    }

    if (cur != tail)
    {
        cur->next->prev = newNode;
        newNode->next = cur->next;
        cur->next = newNode;
        newNode->prev = cur;
        cur = newNode;
    }
    else
    {
        cur->next = newNode;
        newNode->next = NULL;
        newNode->prev = cur;
        tail = newNode;
        cur = newNode;
    }
    printf("Node inserted after current element successfully!\n");
}
//Return cur ptr to newly added node
void insertBeforeCurrent(elementType ele)
{
    node *newNode = makeNewNode(ele);
    if (root == NULL)
    {
        /* if there is no element */
        root = newNode;
        cur = newNode;
        tail = newNode;
        newNode->prev = NULL;
        printf("No element in the list. Node put at root!\n");
        return;
    }
    else
    {
        if (cur == root)
        {
            //insert at head
            newNode->next = root;
            root->prev = newNode;
            root = newNode;
            cur = root;
            newNode->prev = NULL;
        }
        else
        {
            newNode->next = cur;
            cur->prev->next = newNode;
            newNode->prev = cur->prev;
            cur->prev = newNode;
            cur = newNode;
        }
        printf("Node inserted before current element successfully!\n");
        return;
    }
    printf("Cannot identify current node!\n");
    return;
}

node *insertAtPostion(node *root, elementType element, int n)
{
    int index = 0;
    if (root == NULL || !root)
    {
        printf("Cannot identify root node!\n");
        return NULL;
    }
    if (n < 0)
    {
        printf("Please enter a non-negative integer!\n");
        return cur;
    }
    cur = root;
    if (n == 0)
    {
        insertAtHead(element);
        return root;
    }
    while (cur != NULL)
    {
        //(n == index +1) to AVOID the case : inserting at tail then cur = NULL, hence while loop broken
        if (n == index + 1)
        {
            insertAfterCurrent(element);
            printf("Node inserted at position successfully!\n");
            return cur;
        }
        index++;
        cur = cur->next;
    }
    printf("Cannot insert node at given position!\n");
    return NULL;
}

void deleteFirstElement()
{
    node *del = root;
    if (del == NULL)
    {
        printf("List empty!\n");
        return; // No element in the list
    }
    root = del->next;
    del->next->prev = NULL;
    free(del);
    cur = root;
    printf("First node deleted successfully!\n");
}
void deleteLastElement()
{
    node *del = tail;
    if (del == NULL)
    {
        printf("List empty!\n");
        return; // No element in the list
    }
    tail = del->prev;
    del->prev->next = NULL;
    free(del);
    cur = root;
    printf("Last node deleted successfully!\n");
}
//Return cur ptr to root
void deleteCurrentElement()
{
    if (cur == NULL)
    {
        printf("Cannot identify current node!\n");
        return;
    }
    else if (cur == root)
    {
        deleteFirstElement();
    }
    else
    {
        if (cur == tail)
        {
            cur->prev->next = NULL;
            tail = cur->prev;
        }
        else
        {
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
        }
        free(cur);
        cur = root;
    }
    printf("Current node deleted successfully!\n");
    return;
}

node *deleteAtPostion(node *root, int n)
{
    int index = 0;
    if (root == NULL || !root)
    {
        printf("Cannot identify root node!\n");
        return NULL;
    }
    if (n < 0)
    {
        printf("Please enter a non-negative integer!\n");
        return cur;
    }
    cur = root;
    if (cur == NULL)
    {
        printf("The list is already empty!\n");
        return NULL;
    }
    while (cur != NULL)
    {
        if (n == index)
        {
            deleteCurrentElement();
            printf("Node at position %d deleted successfully!\n", n);
            return cur;
        }
        index++;
        cur = cur->next;
    }
    printf("Cannot delete node at given position!\n");
    return NULL;
}

void deleteElement(elementType ele)
{
    cur = root;
    while (cur != NULL)
    {
        if (structCmp(cur->element, ele) == 0)
        {
            if (cur == root)
            {
                deleteFirstElement();
                return;
            }
            else
            {
                if (cur == tail)
                {
                    cur->prev->next = NULL;
                    tail = cur->prev;
                }
                else
                {
                    cur->prev->next = cur->next;
                    cur->next->prev = cur->prev;
                }
                free(cur);
                cur = root;
                return;
            }
        }
        cur = cur->next;
    }
    cur = root;
    printf("Cannot delete the inputted node!\n");
}
int structCmp(elementType element1, elementType element2)
{
    if (strcmp(element1.model, element2.model) == 0 && strcmp(element1.memSpace, element2.memSpace) == 0 && strcmp(element1.screenSize, element2.screenSize) == 0 && strcmp(element1.price, element2.price) == 0)
    {
        return 0;
    }
    return 1;
}

void freeList()
{
    cur = root;
    if (cur == NULL || !cur)
    {
        printf("Cannot identify the root node, thereby fail to free the list!\n");
        return;
    }
    while (cur != NULL)
    {
        root = root->next;
        free(cur);
        cur = root;
    }
    printf("List freed successfully!\n");
}

void reverseList()
{
    node *following, *tmp;
    following = root;
    while (following != NULL)
    {
        //Swap cur->next with cur->prev
        tmp = following->next;
        following->next = following->prev;
        following->prev = tmp;
        //Move cur to next node
        following = tmp;
    }
    //Swap tail with root
    tmp = root;
    root = tail;
    tail = tmp;
    tail->next = NULL;
    printf("List reversed successfully!\n");
}
// Return a ptr to the root of sublist1
node *splitList(node *root, int start_index, int num)
{
    node *root1; // Root1 will point to the head of sublist 1
    int index = 0;
    root1 = root;
    if (start_index < 0)
    {
        printf("Starting index must be a non-negative integer!\n");
        return NULL;
    }
    while (root1 != NULL) // Loop to find the pos of root1
    {
        if (start_index == index)
        {
            break; // *root1 pointed to the head of the sublist1, so break loop
        }
        index++;
        root1 = root1->next;
    }
    cur = root1;
    for (index = 0; index < num; index++)
    {
        cur = cur->next;
    }
    if (start_index == 0)
    {
        if (cur == NULL)
        {
            root = NULL;
            printf("Sublist 2 is empty!\n");
        }
        else
        {
            root = cur;
            cur->prev->next = NULL; // Terminate the sublist1
            cur->prev = NULL;
        }
    }
    else
    {
        if (cur == NULL)
        {
            root1->prev->next = NULL;
            root1->prev = NULL;
            tail = root1->prev;
        }
        else
        {
            root1->prev->next = cur;
            cur->prev = root1->prev;
            root1->prev = NULL;
            cur->prev->next = NULL; // Terminate the sublist1
        }
    }
    return root1;
}

void printList(node *root, FILE *fptr)
{
    node *tmp;
    fprintf(fptr, "%-20s\t%-20s\t%-30s %s\n", "Model", "Memory Space", "Screen Size", "Price");
    for (tmp = root; tmp != NULL; tmp = tmp->next)
    {
        fprintf(fptr, "%-20s\t%-20s\t%-30s %s\n", tmp->element.model, tmp->element.memSpace, tmp->element.screenSize, tmp->element.price);
    }
}