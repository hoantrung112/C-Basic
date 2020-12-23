#include<stdio.h>


int main(int argc ,char* argv[]){
int i;
if(argc > 51 || argc < 3){
    printf("Please enter no more than 50 words!\n");
    return 1;
}

printf("The sentence inverter is: \n");
for(i=argc-1; i > 0; i--){
    printf("%s ", argv[i]);
}
return 0;
} 