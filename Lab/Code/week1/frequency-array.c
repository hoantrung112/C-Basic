#include<stdio.h>

int main(){
  int n,i,j,counter, arr[20], freq[20];
  do {
  printf("How many elements to input? (<20) \n");
  scanf("%d", &n);
  } while (n<1 || n>19);
  printf("Input %d numbers seperated by a space \n", n);
  for(i=0; i<n; i++) {
    scanf("%d", &arr[i]);
    freq[i]=-1; 
  }
  for(i=0; i<n; i++){
    counter =1;
    for(j=i+1; j<n; j++){
      if(arr[i]== arr[j]) {
        counter++;
        freq[j]=0;
      }
    }
      if(freq[i] != 0) {
        freq[i]=counter;
    }
  }
  for(i=0; i<n; i++){
    if(freq[i] !=0) {
      printf("Number %d appeared %d time(s) \n",arr[i],freq[i]);
    }
  }
  return 0;
}