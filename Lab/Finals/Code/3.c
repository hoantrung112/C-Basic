#include "BST-2.h"

void readFileAndCreateTree();
void displayResults();
void searchTeam();
void relegatedTeams();
void qualifiedTeams();

int choice = 0;
treeNode *root;
FILE *fptr;
void main()
{
    while (1)
    {
        printf("============== FOOTBALL LEAGUE MENU ============== \n");
        printf("0.Read file and create tree.\n");
        printf("1.Display results.\n");
        printf("2.Search for a team.\n");
        printf("3.Select teams with lower point than key to relagate. Then delete them.\n");
        printf("4.Print teams qualified for next season.\n");
        printf("5.Exit.\n");
        printf("Please enter your choice here:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            readFileAndCreateTree();
            break;
        case 1:
            displayResults();
            break;
        case 2:
            searchTeam();
            break;
        case 3:
            relegatedTeams();
            break;
        case 4:
            qualifiedTeams();
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
    static int count = 0;
    char club1[MAX_LEN], club2[MAX_LEN];
    int goal1, goal2;
    int point1, point2, temp;
    if ((fptr = fopen("results.txt", "r")) == NULL)
    {
        printf("Cannot open file results.txt to read!\n");
    }
    while (fscanf(fptr, "%s %s %d %d", club1, club2, &goal1, &goal2) != EOF)
    {
        if (goal1 > goal2)
        {
            point1 = 3;
            point2 = 0;
        }
        else if (goal1 < goal2)
        {
            point2 = 3;
            point1 = 0;
        }
        else
        {
            point1 = 1;
            point2 = 1;
        }

        if (search(club1, root) == NULL)
        {
            count++;
            insertNode(club1, point1, &root);
            printf("New node no.%d\t\t%p\n", count, search(club1, root));
        }
        else
        {
            temp = search(club1, root)->point;
            temp += point1;
            search(club1, root)->point = temp;
        }

        if (search(club2, root) == NULL)
        {
            count++;
            insertNode(club2, goal2, &root);
            printf("New node no.%d\t\t%p\n", count, search(club2, root));
        }
        else
        {
            temp = search(club2, root)->point;
            temp += point2;
            search(club2, root)->point = temp;
        }
    }
}

void displayResults()
{
    printf("Teams' points are as follows: \n");
    preOrderPrint(root);
}
void searchTeam()
{
    char team[MAX_LEN];
    printf("Enter a club name for info: ");
    scanf("%s", team);
    if (search(team, root) == NULL)
    {
        printf("There is no such team as \"%s\"!\n", team);
        return;
    }
    else
    {
        printf("Team %s has %d point(s).\n", team, search(team, root)->point);
    }
}
void relegatedTeams()
{
    int minPts;
    printf("Enter a minimum point for teams to qualifyfor next season: ");
    scanf("%d", &minPts);
    printf("List of relagated team(s) with lower point than %d:\n", minPts);
    lowerThanField(minPts, root);
}
void qualifiedTeams()
{
}