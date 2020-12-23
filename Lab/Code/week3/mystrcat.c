#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_LEN 51
int main(){
    char *mystr;
    char str1[MAX_LEN], str2[MAX_LEN];
    printf("Enter string 1 here:\n");
    gets(str1);
    printf("Enter string 2 here:\n");
    gets(str2);
    mystr = (char *) malloc (strlen(str1)*sizeof(char)+ strlen(str2)*sizeof(char));
    strcpy(mystr,str1);
    strcat(mystr, str2);
    printf("Concat str: %s", mystr);
    return 0;
}