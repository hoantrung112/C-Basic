#include<stdio.h>
#include<string.h>
enum{SUCCESS, FAIL, MAX_LEN = 101};

int main(int argc, char* argv[]){
    FILE *read;
    FILE *write;
    int reval = SUCCESS;
    int c;
    char buff[MAX_LEN];
    int len;

    write = fopen("temp.txt", "w");
    if(argc != 2){
        printf("Syntax Error!\n");
        reval = FAIL;
    };
    if((read = fopen(argv[1], "r")) == NULL){
        printf("Syntax Error!\n");
        reval = FAIL;
    } else {
        while(fgets(buff, MAX_LEN, read) != NULL){
        len = strlen(buff)-1;
        fprintf(write, "%d %s", len, buff);
        printf("%s", buff);
      }
    }
    fclose(read);
    fclose(write);
    read = fopen("temp.txt", "r");
    write = fopen(argv[1], "r+");
    while((c = fgetc(read)) != EOF){
        fputc(c,write);
    }
    fclose(read);
    fclose(write);
    remove("temp.txt");
    return reval;
}

