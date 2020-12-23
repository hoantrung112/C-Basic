#include <stdio.h>

enum
{
    SUCCESS,
    FAIL
};

int main(void)
{
    FILE *read;
    FILE *write;
    int c;
    char sourcefile[] = "case.txt";
    char destfile[] = "casew.txt";
    int reval = SUCCESS;

    if ((read = fopen(sourcefile, "r")) == NULL)
    {
        printf("Cannot open %s.\n", sourcefile);
        reval = FAIL;
    }
    else if ((write = fopen(destfile, "w")) == NULL)
    {
        printf("Cannot open %s.\n", destfile);
        reval = FAIL;
    }
    else
    {
        while ((c = fgetc(read)) != EOF)
        {
            if (c >= 'a' && c <= 'z')
            {
                c -= 32;
                fputc(c, write);
            }
            else if (c >= 'A' && c <= 'Z')
            {
                c += 32;
                fputc(c, write);
            }
            else
            {
                fputc(c, write);
            }
        }
        fclose(read);
        fclose(write);
        return reval;
    }
}