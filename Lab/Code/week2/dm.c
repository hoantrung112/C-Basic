#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student{
        int num;
        char id[8];
        char name[35];
        char phone[10];
        float score;
    }student_t;
student_t student_list[5];
int main(){
         
    
    printf("%d %s %s %s", student_list[0].num,student_list[1].id,student_list[1].name,student_list[1].phone);
    
    printf("No.  Student_ID | Student_Name | Phone | score");
    printf("No. | Student_ID | sdgdfgdddddddddddddd | 0000000000 | 2.3");
    printf("No. | Student_ID | dfgggggggggg | 0000000000 | 2.3");
    printf("No. | Student_ID | fgdfgfgfdgf | 0000000000 | 1.3");
    
    return 0; 
}