#include<stdio.h>
enum{SUCCESS, FAIL};

int main(int argc, char* argv[]){
    FILE *read;
    FILE *write;
    int reval = SUCCESS;
    int c;
    if(argc != 3){
        printf("Syntax Error!\n");
        reval = FAIL;
    }else {
        if((read = fopen(argv[1], "r")) ==  NULL){
            printf("Cannot open file %s", argv[1]);
            reval = FAIL;
        }else if((write = fopen(argv[2], "w")) ==  NULL){
            printf("Cannot open file %s", argv[2]);
            reval = FAIL;
        }else {
            while((c = fgetc(read)) != EOF){
                fputc(c, write);
            }
        }
    }
    fclose(read);
    fclose(write);
    return reval;
}