#include "queueCircular-10.h"
#include "stacklist.h"

void createQueue();
void displayTime();
void searchFlight();
void luggageTimeCalc();

int choice;
FILE *fptr;
queue *q;

void main()
{
    while (1)
    {
        printf("=============== MENU ===============\n");
        printf("1.Read file gateReq.txt.\n");
        printf("2.Display waiting and service time of flights.\n");
        printf("3.Search flight's info.\n");
        printf("4.Calculate luggage fetching time.\n");
        printf("5.Exit.\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            createQueue();
            break;
        case 2:
            displayTime();
            break;
        case 3:
            searchFlight();
            break;
        case 4:
            luggageTimeCalc();
            break;
        case 5:
            exit(1);
            break;

        default:
            printf("You must enter a number from 1-5!\n");
            break;
        }
    }
}

void createQueue()
{
    int time;
    char flight[MAX_LEN];
    makeNullQueue(&q); 
    if ((fptr = fopen("gateRequest.txt", "r")) == NULL)
    {
        printf("Cannot open file txt!");
        return;
    }
   printf("%d\n",isFull(q));
    while (fscanf(fptr, "%s %d", flight, &time) != EOF)
    {
        if (time > 0 && time <= 30)
        {
                printf("Hey!\n");
            enQueue(time, flight, &q);
        }
        else
        {
            printf("Invalid service time! Pls enter valid time here: ");
            scanf("%d", &time);
            enQueue(time, flight, &q);
        }
    }
    // printQueue(q);
}
void displayTime()
{
}
void searchFlight()
{
}
void luggageTimeCalc()
{
}