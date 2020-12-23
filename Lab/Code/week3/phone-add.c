#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum
{
    SUCCESS,
    FAIL,
    MAX_ELEMENT = 20
};
typedef struct phoneaddress
{
    char name[20];
    char tel[11];
    char email[25];
} phoneaddress_t;

int main(void)
{
    FILE *fptr;
    phoneaddress_t phonearr[MAX_ELEMENT];
    int i, n, irc; // return code
    int reval = SUCCESS;
    printf("How many contacts do you want to enter (<20)?");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("name:");
        scanf("%s", phonearr[i].name);
        printf("tel:");
        scanf("%s", phonearr[i].tel);
        printf("email:");
        scanf("%s", phonearr[i].email);
    }
    if ((fptr = fopen("phonebook.dat", "w+b")) == NULL)
    {
        printf("Can not open %s.\n", "phonebook.dat");
        reval = FAIL;
    }

    // write the entire array into the file
    irc = fwrite(phonearr, sizeof(phoneaddress_t), n, fptr);
    printf(" fwrite return code = %d\n", irc);
    fclose(fptr);

    // read from this file to array again
    if ((fptr = fopen("phonebook.dat", "rb")) == NULL)
    {
        printf("Can not open %s.\n", "phonebook.dat");
        reval = FAIL;
    }
    irc = fread(phonearr, sizeof(phoneaddress_t), n, fptr);
    printf(" fread return code = %d\n", irc);
    for (i = 0; i < n; i++)
    {
        printf("%s-", phonearr[i].name);
        printf("%s-", phonearr[i].tel);
        printf("%s\n", phonearr[i].email);
    }
    fclose(fptr);
    return reval;
}