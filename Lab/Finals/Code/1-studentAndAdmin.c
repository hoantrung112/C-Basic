#include "BST-1.h"

void signIn();
void adminMenu();
void studentMenu();
void saveToFile();
void writeToFile(treeNode *node);

treeNode *root;
int choice;
FILE *fptr = NULL;
char username[MAX_LEN];
char password[MAX_LEN];
double score;
void main()
{
    while (1)
    {
        printf("=============== MAIN MENU ===============\n");
        printf("1.Sign in.\n");
        printf("2.Exit.\n");
        printf("YOur choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            signIn();
            fclose(fptr);
            break;

        case 2:
            freeTree(root);
            exit(1);
            break;

        default:
            break;
        }
    }
}
void signIn()
{
    char usernameTmp[MAX_LEN];
    char passwordTmp[MAX_LEN];
    double scoreTmp;
    treeNode *user;
    int count = 0;
    if ((fptr = fopen("users.txt", "r")) == NULL)
    {
        printf("Cannot open file users.txt!\n");
        exit(1);
    }
    while (fscanf(fptr, "%s %s %lf", usernameTmp, passwordTmp, &scoreTmp) != EOF)
    {
        printf("%s\t\t%s\t\t%lf\n", usernameTmp, passwordTmp, scoreTmp);
        insertNode(usernameTmp, passwordTmp, scoreTmp, &root);
    }
    while (count != -1)
    {
        printf("=============== SIGN IN MENU ===============\n");
        printf("Please enter your username: ");
        scanf("%s", usernameTmp);
        printf("Please enter your password: ");
        scanf("%s", passwordTmp);
        strcpy(username, usernameTmp);
        strcpy(password, passwordTmp);
        user = search(usernameTmp, root);
        if (user != NULL)
        {
            //attention: must try if user != NULL or else in case of NULL->username prog will crash
            if (strcmp(usernameTmp, user->username) == 0 && strcmp(passwordTmp, user->password) == 0)
            {
                count = -1;
                if (strcmp(usernameTmp, "admin") == 0)
                {
                    adminMenu();
                }
                else
                {
                    studentMenu();
                }
            }
            else
            {
                if (count == 3)
                {
                    printf("Too many failed attempts!\n");
                    exit(1);
                }
                count++;
                printf("Wrong! Pls try again! You have %d efforts left!\n", 3 - count);
            }
        }
        else
        {
            if (count == 3)
            {
                printf("Too many failed attempts!\n");
                exit(1);
            }
            count++;
            printf("Wrong! Pls try again! You have %d efforts left!\n", 3 - count);
        }
    }
}
void adminMenu()
{
    char usernameTmp[MAX_LEN];
    char passwordTmp[MAX_LEN];
    double scoreTmp;

    while (1)
    {
        printf("=============== ADMIN MENU ===============\n");
        printf("1.Add student\n");
        printf("2.Print students\n");
        printf("3.Delete student\n");
        printf("4.Save to file and exit\n");
        printf("Your choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            do
            {
                printf("Enter new student's username (MUST BE NON-EXISTENT YET): ");
                scanf("%s", usernameTmp);
            } while (search(usernameTmp, root) != NULL);
            do
            {
                printf("Enter password(MUST BE OVER 6 CHARACTERS): ");
                scanf("%s", passwordTmp);
            } while (strlen(passwordTmp) < 6);
            printf("Enter score: ");
            scanf("%lf", &scoreTmp);
            insertNode(usernameTmp, passwordTmp, scoreTmp, &root);
            printf("Username added!\n");
            break;

        case 2:
            preOrderPrint(root);
            break;

        case 3:
            printf("Enter a username to delete: ");
            scanf("%s", usernameTmp);
            if (usernameTmp == "admin")
            {
                printf("Cannot delete admin account!\n");
            }
            else if (search(usernameTmp, root) != NULL)
            {
                deleteNode(usernameTmp, &root);
                printf("Username deleted!\n");
            }
            break;

        case 4:
            saveToFile();
            return;

        default:
            break;
        }
    }
}

void studentMenu()
{
    char pass[MAX_LEN];
    char pass1[MAX_LEN];
    while (1)
    {
        printf("=============== STUDENT MENU ===============\n");
        printf("1.View my score\n");
        printf("2.Change password\n");
        printf("3.Save to file and exit\n");
        printf("Your choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Your score is: %lf.\n", search(username, root)->score);
            break;

        case 2:
            printf("Enter old password: ");
            scanf("%s", pass);
            if (strcmp(password, pass) == 0)
            {
                printf("Enter new password: ");
                scanf("%s", pass);
                printf("Re-enter new password: ");
                scanf("%s", pass1);
                if (strcmp(pass, pass1) == 0)
                {
                    strcpy(search(username, root)->password, pass);
                }
                else
                {
                    printf("Your new password didnt match!\n");
                }
            }
            else
            {
                printf("Wrong password!\n");
            }
            break;

        case 3:
            saveToFile();
            return;
        default:
            break;
        }
    }
}
void saveToFile()
{
    if ((fptr = fopen("users.txt", "w")) == NULL)
    {
        printf("Cannot open file users.txt to save data to file!\n");
    }
    writeToFile(root);
    fclose(fptr);
}
void writeToFile(treeNode *root)
{
    if (root != NULL)
    {
        fprintf(fptr, "%s\t%s\t%lf\n", root->username, root->password, root->score);
        writeToFile(root->left);
        writeToFile(root->right);
    }
}