#include "BST-studentMana.h"

void insertStudent();
void searchLowerScore();
void searchHigherScore();

int choice;
char tmpName[NAME_LENGTH];
treeNode *root;
void main()
{
    while (1)
    {
        printf("==========MENU STUDENT MANAGEMENT==========\n");
        printf("1.Insert new student.\n");
        printf("2.Search students with lower score than key.\n");
        printf("3.Search students with higher score than key.\n");
        printf("4.Exit.\n");
        printf("Your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertStudent();
            break;
        case 2:
            searchLowerScore();
            break;
        case 3:
            searchHigherScore();
            break;
        case 4:
            freeTree(root);
            printf("Exiting program...\n");
            exit(1);
            break;

        default:
            printf("You must enter a number 1->4.\n");
            break;
        }
    }
}
void insertStudent()
{
    printf("Enter the name of the student:\n");
    scanf(" %s", tmpName);
    printf("Enter the score of the student:");
    scanf("%d", &choice);
    insertNode(choice, tmpName, &root);
    printf("Student added successfully!\n");
}
void searchLowerScore()
{
    printf("Enter a score to search for students with lower ones:");
    scanf("%d", &choice);
    printf("Here is the list of students with lower scores:\n");
    printf("The total student count: %d\n", lowerThanKey(choice, root));
}
void searchHigherScore()
{
    printf("Enter a score to search for students with higher ones:");
    scanf("%d", &choice);
    printf("Here is the list of students with higher scores:\n");
    printf("The total student count: %d\n", higherThanKey(choice, root));
}