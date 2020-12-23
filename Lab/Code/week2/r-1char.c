#include <stdio.h>
enum {SUCCESS, FAIL};

int main(void){
    FILE *read;
    FILE *write;
    int c;
 char sourcefile[]= "lab1.txt";
 char destfile[]= "lab1w.txt";
 int reval = SUCCESS;

 if ((read = fopen(sourcefile, "r")) == NULL){
    printf("Cannot open %s.\n", sourcefile);
    reval = FAIL;
 } else if((write = fopen(destfile, "w")) == NULL){
    printf("Cannot open %s.\n", destfile);
    reval = FAIL;
 }else {
    while((c=fgetc(read)) != EOF){
        fputc(c,write);
    }
 }
 fclose(read);
 fclose(write);
 return reval;
 
}