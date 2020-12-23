#include <stdio.h> 
#include <string.h> 

int main(){
    int i,j,n;
    char std_list[15][35], *std_firstname[15], temp[20];
    char *firstname;

    printf("How many student? (<15) \n");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        printf("Enter student's full name no.%d (no more than 35 characters)\n",i+1);
        scanf(" %[^\n]s", std_list[i]);
    }
    for(i=0;i<n;i++){
        firstname=strrchr(std_list[i],' ');
        std_firstname[i]=firstname;
    }
    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(strcmp(std_firstname[i],std_firstname[j]) > 0){
                strcpy(temp,std_list[j]);
                strcpy(std_list[j],std_list[i]);
                strcpy(std_list[i],temp);
            }
        }
    }
    printf("\n-----------------------------------------\n");
    for(i=0; i<n; i++){
        printf("%d",i+1);
        printf("\t %s \n",std_list[i]);
    }
    return 0;
}