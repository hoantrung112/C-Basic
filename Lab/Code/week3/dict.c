#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LENG 100

typedef struct  {
    char *english;
    char *viet;
    char line[2 * MAX_LENG];
}word_t;

int lineCount(FILE* fptr);
void fileRead(FILE* fptr);

int main() {
    word_t* dic;
    FILE* ifp;
    FILE* ifpb;
    FILE* ofp;
    int lineNum;
    if ((ifp = fopen("vnedict.txt", "r")) == NULL)
    {
        printf("vnedict.txt does not exist");
        exit(1);
    }
    if ((ofp = fopen("vnedict.dat", "wb+")) == NULL)
    {
        printf("vnedict.dat does not exist");
        exit(1);
    }
    //Count lines and allocating memory
    lineNum = lineCount(ifp);
    dic = malloc(sizeof(word_t) * lineNum);
    //Writing to dat
    int i;
    const char delimiter[2] = ":";
    i = 0;
    while (fgets(dic[i].line, MAX_LENG * 2, ifp))
    {
        dic[i].viet = strtok(dic[i].line, ":");
        dic[i].english = strtok(NULL, ":");
        i++;
    }
    fwrite(dic, sizeof(word_t), i, ofp);
    fclose(ofp);

    fclose(ifp);

    ofp = fopen("vnedict.dat", "rb");

    fileRead(ofp);
    fclose(ofp);
  

    free(dic);
}

int lineCount(FILE* fptr) {
    int lineNum = 0;
    char str[2 * MAX_LENG];
    while (fgets(str, MAX_LENG, fptr) != NULL)
    {
        lineNum++;
    }
    rewind(fptr);
    return lineNum;
}

void fileRead(FILE* fptr)
{
    long int start, end;
    word_t w;
    printf("Enter the begin and the end point: ");
    scanf("%ld %ld", &start, &end);
    fseek(fptr, (start - 1) * sizeof(word_t) , SEEK_SET);

    int count = 0;
    while ((fread(&w, sizeof(word_t), 1, fptr)) && count < (end - start + 1))
    {
        printf("%s \t:\t %s", w.viet, w.english);
        count++;
    }
        

    fclose(fptr);
}