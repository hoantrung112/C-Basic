#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char* argv[]){
    if(argc != 4){
    printf("Syntax error\n Please enter again!");
    return 1;
    }
    float a = atof(argv[1]);
    float b = atof(argv[2]);
    float c = atof(argv[3]);
 
    printf("Solution for the equation: %.2fx^2 + %.2fx + %.2f = 0 :\n", a,b,c);
    int delta = pow(b,2)-4*a*c;
    if(delta < 0){
        printf("No Solution\n");
    }else if(delta == 0){
        printf("Solution: x1=x2=%.2f", -b/(2*a));
    }else {
        printf("Solution: x1=%.2f, x2=%.2f", -b+sqrt(delta)/(2*a), -b-sqrt(delta)/(2*a));
    }
    return 0;
}
    
