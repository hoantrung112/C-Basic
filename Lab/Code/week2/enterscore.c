#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum{SUCCESS, FAIL, MAX_LEN = 35, LIST_LEN = 20};
typedef struct student{
        int num;
        int id;
        char name[MAX_LEN];
        char phone[10];
        char score[5];
    }student_t;
student_t student_list[LIST_LEN];
int main(int argc, char* argv[]){
    FILE *fptr;
    int i;
    int reval = SUCCESS;
    if(argc != 3){
        printf("Syntax Error!\n");
        reval = FAIL;
        exit(1);
    };
    if((fptr = fopen(argv[1],"r")) == NULL){
        printf("CAN'T OPEN FILE.");
        reval = FAIL;
        exit(1);
    }else{
        for(i = 0; i < 20; i++){
            fscanf(fptr,"%d %d %s %s",&student_list[i].num,&student_list[i].id,&student_list[i].name,&student_list[i].phone);
            printf("%d %d %s %s \n", student_list[i].num,student_list[i].id,student_list[i].name,student_list[i].phone);
        };   
    }
    fclose(fptr);
    
     if((fptr = fopen(argv[2],"w")) == NULL){
        printf("Error");
        reval = FAIL;
    }; 
    for(i = 0; i < 20; i++){
            printf("Enter score for %s: ",student_list[i].name);
            scanf("%s", student_list[i].score);
    };
    fprintf(fptr,"No. \t Student_ID \t Student_Name \t Phone \t score \n");
    for(i = 0; i < 20; i++){
        fprintf(fptr,"%d \t %d \t %s \t %s \t %s \t\n", student_list[i].num,student_list[i].id,student_list[i].name,student_list[i].phone,student_list[i].score);
    }
    fclose(fptr);
    
    return reval; 
}