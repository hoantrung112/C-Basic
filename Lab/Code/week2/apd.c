#include<stdio.h>
enum{SUCCESS, FAIL};

int main(int argc, char* argv[]){
    FILE *read;
    FILE *append;
    int reval = SUCCESS;
    int c;
    if(argc != 3){
        printf("Syntax Error!\n");
        reval = FAIL;
    }else {
        if((read = fopen(argv[1], "r")) ==  NULL){
            printf("Cannot open file %s", argv[1]);
            reval = FAIL;
        }else if((append = fopen(argv[2], "a+")) ==  NULL){
            printf("Cannot open file %s", argv[2]);
            reval = FAIL;
        }else {
            while((c = fgetc(read)) != EOF){
                fputc(c, append);
            }
        }
    }
    fclose(read);
    fclose(append);
    return reval;
}