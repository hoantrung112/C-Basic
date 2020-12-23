#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc ,char* argv[]){
    char word[100];
    int rep;
    if(argc != 3){
        printf("Wrong number of arguments!\n");
        printf("CORRECT SYNTAX: word-rep <WORD> <TIMES>\n");
        return 1;
    }
    strcpy(word,argv[1]);
    rep = atof(argv[2]);
    for(int i=0; i<rep; i++){
        printf("%s", word);
    }
    return 0;
}