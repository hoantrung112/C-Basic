#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stacklist1.h"
#include "stacklist1Str.h"

void main()
{
    node* top;
    nodeStr* top1;
   char* str = "Heloooooooo", *strptr;
   int num = 112211;
   int choice;
   /*push(num,&top);
    choice = pop(&top);
   itoa(choice, str, 10);
   printf("str = %s\n", str);
   pushStr(str--,&top1);
   
   printf("popped = %s\n", popStr(&top1));

   
   pushStr("HELLO",&top1);
   printf(" %s", peekStr(&top1));
   printf("Enter string: \n");
   scanf(" %s", str);*/
   strptr = str;
   printf("%s", strptr);
}