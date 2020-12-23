#include <stdio.h> 
#include <string.h> 
  
int main() 
{ 
    char str[100];
    const char delim[2]=" ";
    printf("Enter some words: \n");
    gets(str);
    
    char *tokenptr = strtok(str, delim);
    while(tokenptr != NULL){
        printf("%s\n", tokenptr);
        tokenptr = strtok(NULL, delim);
    }
    return 0; 
} 