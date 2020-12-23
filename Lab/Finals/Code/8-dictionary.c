#include "BST-dict.h"

void readFileAndCreateTree();
void printTree();
void addNewWord();
void translateWord();
void translateSentence();

treeNode *root;
FILE *fptr;
int choice;

void main()
{
    while (1)
    {
        printf("============== DICTIONARY MENU ============== \n");
        printf("0.Read file and create tree.\n");
        printf("1.Preorder print.\n");
        printf("2.Add new word.\n");
        printf("3.Translate input word.\n");
        printf("4.Translate input sentence.\n");
        printf("5.Exit.\n");
        printf("Please enter your choice here:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            readFileAndCreateTree();
            break;
        case 1:
            printTree();
            break;
        case 2:
            addNewWord();
            break;
        case 3:
            translateWord();
            break;
        case 4:
            translateSentence();
            break;
        case 5:
            freeTree(root);
            exit(1);
            break;
        default:
            printf("Please enter a number from 1-4!\n");
            break;
        }
    }
}
void readFileAndCreateTree()
{
    char eng[MAX_LEN];
    char vie[MAX_LEN];
    if ((fptr = fopen("8-dictionary.txt", "r")) == NULL)
    {
        printf("Cannot open file text to fetch data!\n");
    }
    while (fscanf(fptr, "%s %s", eng, vie) != EOF)
    {
        insertNode(eng, vie, &root);
        printf("%s %s\n", eng, vie);
    }
}

void printTree()
{
    if (root == NULL)
        printf("Tree empty!\n");
    preOrderPrint(root);
}

void addNewWord()
{
    char eng[MAX_LEN];
    char vie[MAX_LEN];
    treeNode *tmp;

    printf("Please enter a new word in English:(max length = 30)");
    scanf("%s", eng);

    if (search(eng, root))
    {

        printf("Word existed.Wanna edit this word?\n");
        printf("1.Yes\n");
        printf("Otherwise. No\n");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Please enter its meaning:(max length = 30)");
            scanf("%s", vie);
            tmp = search(eng, root);
            strcpy(tmp->vie, vie);
            break;
        default:
            return;
            break;
        }
    }
    else
    {
        printf("Please enter its meaning:(max length = 30)");
        scanf("%s", vie);
        insertNode(eng, vie, &root);
    }
}
void translateWord()
{
    char tmp[MAX_LEN];
    printf("Please enter a word to translate:");
    scanf("%s", tmp);
    if (search(tmp, root) == NULL)
    {
        printf("Cannot identify word. Case-sensitive !\n");
    }
    else
    {
        printf("\nThe meaning of input word is: %s\n", search(tmp, root)->vie);
    }
}
void translateSentence()
{
    char *token;
    char tmp[MAX_LEN * 10];
    char tmp1[MAX_LEN * 10];
    treeNode *searchResult;
    printf("Please enter a sentence seperated by spaces without any other signs (dot, comma,...):\n");
    scanf(" %[^\n]s", tmp);
    strcpy(tmp1,tmp);

    token = strtok(tmp, " ");
    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }

    token = strtok(tmp1, " ");
    while (token != NULL)
    {
        // strcpy(tokenTmp, token);
        if (search_NoPrint(token, root) != NULL)
        {
            printf("%s\n", search_NoPrint(token, root)->vie);
        }
        else
        {
            printf("<Missing definition>\n");
        }
        token = strtok(NULL, " ");
    }
}
