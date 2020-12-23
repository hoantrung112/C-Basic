#include <stdio.h>
#include <stdlib.h>
enum
{
    SUCCESS,
    FAIL
};

int main(int argc, char *argv[])
{
    FILE *read;
    FILE *write;
    int reval = SUCCESS;
    int c, low = 97, up = 65;
    int arrlow[52], arrup[52];
    int offset = (int)atof(argv[2]);

    if (argc != 3)
    {
        printf("Syntax Error!\n");
        reval = FAIL;
    }
    else
    {
        if ((read = fopen(argv[1], "r")) == NULL)
        {
            printf("Cannot open file %s", offset);
            reval = FAIL;
        }
        else if ((write = fopen("temp.txt", "w")) == NULL)
        {
            reval = FAIL;
        }
        else
        {
            if (offset >= 26)
            {
                printf("Please enter offset value < 26!");
                reval = FAIL;
            };
            for (int i = 0; i < 52; i++)
            {
                if (low <= 122)
                {
                    arrlow[i] = low;
                    low++;
                }
                else
                    low = 97;
                if (up <= 90)
                {
                    arrup[i] = up;
                    up++;
                }
                else
                    up = 65;
            };
            while ((c = fgetc(read)) != EOF)
            {
                if (c >= 'a' && c <= 'z')
                {
                    c = arrlow[c - 97 + offset];
                    fputc(c, write);
                }
                else if (c >= 'A' && c <= 'Z')
                {
                    c = arrlow[c - 65 + offset];
                    fputc(c, write);
                }
                else
                {
                    fputc(c, write);
                }
            }
        }
    }
    fclose(read);
    fclose(write);
    read = fopen("temp.txt", "r");
    write = fopen(argv[1], "a");
    fputs("\n\n\t THE ENCODED TEXT IS AS FOLLOWS: \n", write);

    while ((c = fgetc(read)) != EOF)
    {
        fputc(c, write);
    }
    fclose(read);
    fclose(write);
    remove("temp.txt");
    return reval;
}