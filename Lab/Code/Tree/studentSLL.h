#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ID_LEN 8
#define NAME_LEN 35

//------GENERIC SINGLY LINKED LIST HEADER FILE--------
//------IN ORDER TO REUSE CODE, EDIT THE FOLLOWING STRUCT AND FUNCS ACCORDINGLY--------
// readNode, displayNode, structCmp, printList

typedef struct Student_t
{
    char id[ID_LEN];
    char name[NAME_LEN];
    int grade;
    struct Student_t *next;
} Student;

typedef Student elementType;
typedef struct node node;

struct node
{
    elementType element;
    node *next;
};
node *root, *cur, *prev;

node *makeNewNode(elementType element);
elementType readNode();
void displayNode(node *p);
void insertAtHead(elementType element);
void insertAfterCurrent(elementType element);
void insertBeforeCurrent(elementType element);
void traversingList(node *root);
void deleteFirstElement();
void deleteCurrentElement();
void deleteElement(elementType element);
int structCmp(elementType element1, elementType element2);
void freeList();
void reverseList();
node *insertAtPostion(node *root, elementType element, int n);
node *deleteAtPostion(node *root, int n);
node *splitList(node *root, int start_index, int num);
void printList(node *root, FILE *fptr);

// Function to create a new node(not in the list YET)
node *makeNewNode(elementType element)
{
    node* newNode = (node *)malloc(sizeof(node));
    newNode->element = element;
    newNode->next = NULL;
    return newNode;
}
// Function to read node from input
elementType readNode()
{
    elementType tmp;
    printf("Enter the name of the student:");
    scanf(" %s", &tmp.name);
    printf("Enter the student ID of the student:");
    scanf(" %s", &tmp.id);
    printf("Enter the (integer) grade of the student:");
    scanf(" %s", &tmp.grade);
    return tmp;
}
// Function to display node to screen
void displayNode(node *p)
{
    if (p == NULL)
    {
        printf("ERROR! NULL pointer!\n");
        return;
    }
    elementType tmp = p->element;
    printf("%-20s\t%-20s\t%-30d %p\n", tmp.name, tmp.id, tmp.grade, p->next);
}
// Return cur to root
void insertAtHead(elementType element)
{
    node *newNode = makeNewNode(element);
    newNode->next = root;
    root = newNode;
    cur = root;
}
// Return cur to new node inserted
void insertAfterCurrent(elementType element)
{
    node *newNode = makeNewNode(element);
    if (cur == NULL)
    {
        printf("Cannot identify current element in the list.\n");
        return;
    }
    if (root == NULL)
    {
        /* if there is no element */
        root = newNode;
        cur = root;
        printf("No element in the list. Node put at root!\n");
    }
    else
    {
        newNode->next = cur->next;
        cur->next = newNode;
        prev = cur;
        cur = newNode;
    }
}
// Return cur to newly inserted node
void insertBeforeCurrent(elementType element)
{
    node *newNode = makeNewNode(element);
    if (root == NULL)
    {
        /* if there is no element */
        root = newNode;
        cur = root;
        prev = NULL;
        printf("No element in the list. Node put at root!\n");
    }
    else
    {
        if (cur == root)
        {
            //insert at head
            newNode->next = cur;
            root = newNode;
            cur = root;
            prev = NULL;
        }
        else
        {
            if (prev != NULL)
            {
                newNode->next = cur;
                prev->next = newNode;
                cur = prev->next;
            }
            else
            {
                printf("Cannot identify prev node!\n");
            }
        }
    }
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
// Return cur to root
void deleteFirstElement()
{
    node *del = root;
    if (del == NULL)
    {
        printf("List empty!\n");
        return; // No element in the list
    }
    root = del->next;
    free(del);
    cur = root;
    prev = NULL;
    printf("First node deleted successfully!\n");
}
//Return cur to root
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
        return;
    }
    else
    {
        prev->next = cur->next;
        free(cur);
        cur = root;
    }
}
// Return cur to root
void deleteElement(elementType element)
{
    prev = NULL;
    cur = root;
    while (cur != NULL)
    {
        if (structCmp(cur->element, element) == 0)
        {
            if (cur == root)
            {
                deleteFirstElement();
                return;
            }
            else if (prev != NULL)
            {
                prev->next = cur->next;
                free(cur);
                prev = NULL;
                cur = root;
                return;
            }
        }
        prev = cur;
        cur = cur->next;
    }
    cur = root;
    printf("Cannot delete the inputted node!\n");
}
// Return 0 if structs equal each other, 1 otherwise
int structCmp(elementType element1, elementType element2)
{
    if (strcmp(element1.name, element2.name) == 0 && strcmp(element1.id, element2.id) == 0 && element1.grade == element2.grade)
    {
        return 0;
    }
    return 1;
}
void freeList()
{
    node *to_free = root;
    if (to_free == NULL || !to_free)
    {
        printf("Cannot identify the root node, thereby fail to free the list!\n");
        return;
    }
    while (to_free != NULL)
    {
        root = root->next;
        free(to_free);
        to_free = root;
    }
    printf("List freed successfully!\n");
}
void reverseList()
{
    node *cur, *prev, *following;
    prev = NULL;
    cur = root;
    following = NULL;
    while (cur != NULL)
    {
        following = cur->next;
        cur->next = prev;
        prev = cur;
        cur = following;
    }
    root = prev;
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
    prev = NULL;
    if (n == 0)
    {
        insertAtHead(element);
        printf("Node inserted at position successfully!\n");
        return root;
    }
    while (cur != NULL)
    {
        //(n == index +1) to AVOID the case : inserting at tail then cur = NULL, hence while loop broken
        if (n == index + 1)
        {
            insertAfterCurrent(element);
            return cur;
        }
        index++;
        prev = cur;
        cur = cur->next;
    }
    printf("Cannot insert node at given position!\n");
    return NULL;
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
    prev = NULL;
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
        prev = cur;
        cur = cur->next;
    }
    printf("Cannot delete node at given position!\n");
    return NULL;
}
node *splitList(node *root, int start_index, int num)
{
    node *root1, *prev_root1; // Root1 will point to the head of sublist 1
    int index = 0;
    root1 = root;
    prev_root1 = NULL;
    if (start_index < 0)
    {
        printf("Starting index must be a non-negative integer!\n");
        return NULL;
    }
    while (root1 != NULL) // Loop to find the pos of root1
    {
        if (start_index == index)
        {
            break; // Root1* pointed to the head of the sublist1, so break loop
        }
        index++;
        prev_root1 = root1;
        root1 = root1->next;
    }
    cur = root1;
    prev = prev_root1;
    for (index = 0; index < num; index++)
    {
        prev = cur;
        cur = cur->next;
    }
    if (start_index == 0)
    {
        if (cur == NULL)
        {
            root == NULL;
            printf("Sublist 2 is empty!\n");
        }
        else
        {
            root = cur;
            prev->next = NULL; // Terminate the sublist1
        }
    }
    else
    {
        prev_root1->next = cur;
        prev->next = NULL; // Terminate the sublist1
    }
    return root1; // Return a ptr to the root of sublist1
}
