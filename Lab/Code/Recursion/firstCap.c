#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_LEN 200

char findFirstCap(char str[MAX_LEN]);

int main()
{
    char letter;
    char str[MAX_LEN];
    printf("Enter a string here: ");
    scanf("%[^\n]s",str);
    letter = findFirstCap(str);
    if (letter != 0)
    {
        printf("The first capital letter in the string \"%s\" is %c.", str, letter);
    }
    return 0;
}

char findFirstCap(char str[MAX_LEN])
{
    static int i = 0;
    if (i < strlen(str))
    {
        if (isupper(str[i]))
        {
            return str[i];
        }
        else
        {
            i += 1;
            findFirstCap(str);
        }
    }
    else
    {
        printf("There's no capital letter in the given string!\n");
        return 0;
    }
}