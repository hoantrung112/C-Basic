#include "queueCircular.h"
#include <stdlib.h>

typedef struct
{
    int id, memory;
} prog;
prog running[MaxLength];
queue waitingID;
queue waitingMem;

int maxProcess, memoryCap, choice, idTmp, memTmp, availMem, count_running = 0, count_waiting = 0, flag = 0, i;
void createProgramme();
void killProgramme();
void displayStatus();

void main()
{
    printf("============= PROCESS MANAGEMENT IN OPERATING SYSTEM =============\n");
    printf("Please enter the maximum number of processes the OS can handle at a time: ");
    scanf("%d", &maxProcess);
    printf("Please enter the OS's memory capacity: ");
    scanf("%d", &memoryCap);
    availMem = memoryCap;
    for (i = 0; i < maxProcess; i++) // set all running ID = -1
    {
        running[i].id = -1;
    }

    while (1)
    {
        printf("============= PROCESS MANAGEMENT IN OPERATING SYSTEM =============\n");
        printf("1. Create new program.\n");
        printf("2. Kill program.\n");
        printf("3. Status display.\n");
        printf("4. Exit.\n");
        printf("Enter your choice here: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            createProgramme();
            break;
        case 2:
            killProgramme();
            break;
        case 3:
            displayStatus();
            break;
        case 4:
            printf("OS shutting down....\n");
            exit(1);
            break;
        default:
            printf("Please enter a number from 1 to 4!\n");
            break;
        }
    }
}

void createProgramme()
{
    do
    {
        printf("Enter an ID (different from -1) for the new programme:\n");
        scanf("%d", &idTmp);
    } while (idTmp == -1);

    do
    {
        printf("Enter the memory (between 0 and %d) needed for running the new programme:\n", memoryCap);
        scanf("%d", &memTmp);
    } while (memTmp < 0 || memTmp > memoryCap);

    if (count_running == maxProcess || availMem < memTmp)
    {
        enQueue(idTmp, &waitingID);
        enQueue(memTmp, &waitingMem);
        printf("ele[front] = %d\n", (&waitingID)->element[(&waitingID)->rear]);
        count_waiting++;
        printf("wait = %d\n", count_waiting);
    }
    else
    {
        running[count_running].id = idTmp;
        running[count_running].memory = memTmp;
        availMem -= memTmp;
        count_running++;
        printf("running = %d\n", count_running);
    }
}

void killProgramme()
{
    printf("Please enter ID of program you wish to terminate:\n");
    scanf("%d", &idTmp);
    for (i = 0; i < maxProcess; i++)
    {
        if (running[i].id == idTmp)
        {
            running[i].id = -1;
            count_running--;
            availMem += running[i].memory;
            flag++;
        }
    }
    if (flag != 0)
    {
        printf("Program ID %d killed successfully!\n", idTmp);
        flag = 0;
    }
    else
    {
        printf("There is no such programme with ID %d!\n", idTmp);
    }
    printf("front after killing = %s\n", (&waitingMem)->element[(&waitingMem)->front+1]);
    if (count_waiting > 0 && (&waitingMem)->element[(&waitingMem)->front + 1] <= availMem)
    {
        running[count_running].id = deQueue(&waitingID);
        running[count_running].memory = deQueue(&waitingMem);
        availMem -= running[count_running].memory;
        count_running++;
        count_waiting--;
    }
}

void displayStatus()
{
    int tmp = (&waitingID)->front;
    printf("%-10s %-10s %-10s\n", "ID", "Memory", "In queue");
    for (i = 0; i < maxProcess; i++)
    {
        if (running[i].id != -1)
        {
            printf("%-10d %-10d %-10s\n", running[i].id, running[i].memory, "/");
        }
    }
    for (i = 1; i < count_waiting + 1; i++)
    {
        printf("%-10d %-10s %-10d\n", (&waitingID)->element[i], "/", (&waitingMem)->element[i]);
    }
}
