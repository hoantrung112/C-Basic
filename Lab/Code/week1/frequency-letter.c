#include<stdio.h>
#include<ctype.h>

int main(){
    char str[99999], count[26]={0};
    int i, letterindex;
    printf("Enter a random string here: \n");
    gets(str);
    while(str[i] != '\0'){
        str[i] = tolower(str[i]);
        if(str[i] >= 'a' && str[i] <= 'z'){
            letterindex = str[i] - 'a';
            count[letterindex] += 1;
        }
        i++;
    }
    for(i=0; i<26; i++){
        if(count[i] != 0)
        printf("Letter %c in the string appeared %d time(s). \n", i + 'a' ,count[i]);
    }
    return 0;
}

