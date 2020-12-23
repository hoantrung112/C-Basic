#include<stdio.h>
#include<string.h>
#define STRING_LEN 100

void char_replace(char str[], char rpl_what, char rpl_with){
    int i;
    for(i = 0; str[i] != '\0'; ++i){
        if(str[i] == rpl_what){
            str[i] = rpl_with;
        }
    }
}
int main(void){
    char mystr[STRING_LEN+1];
    char rpl_what, rpl_with;
    printf("Enter a string without space\n");
    scanf("%s", mystr);

    printf("Enter a character you wanna replace: \n");
    scanf(" %c", &rpl_what);

    printf("Enter a character to replace with: \n");
    scanf(" %c", &rpl_with);

    char_replace(mystr, rpl_what, rpl_with);
    printf("NEW STRING: %s", mystr);
    return 0;
}