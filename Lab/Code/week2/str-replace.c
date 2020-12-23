#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[]){
    int i=0, sizewhat;
    char buffer[200];
    char *p = argv[1];
    char *rpl_what = argv[2];
    char *rpl_with = argv[3];
    
    if(argc != 4){
    printf("Syntax error\n Please enter again!");
    return 1;
    }
    while(rpl_what[i] != '\0'){
        i++;
    }
    sizewhat=i;
    i=0;
    while(*p != '\0'){
        if(strstr(p,rpl_what)==p){
            strcat(buffer, rpl_with);
            p+=(sizewhat-1);
        } else {
            strncat(buffer,p,1);
        }
        p++;
    }
    printf("New string: %s", buffer);
    return 0;
}
    
    
