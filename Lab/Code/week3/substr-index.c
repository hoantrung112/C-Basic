#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* subStr(char *s1, int offset,int number)
{
  int i;
  int slen = strlen(s1);
  if(slen < number) {
    char *dest0 = (char*)malloc(sizeof(char) * (slen-offset + 1));

    for (i = offset; i < slen && (*(s1 + i) != '\0'); i++){
		*dest0 = *(s1 + i);
		dest0++;
	}
    return dest0 - slen + offset;
    free(dest0);
    
  } else {
	char *dest = (char*)malloc(sizeof(char) * (number + 1));

	for (i = offset; i < offset+number; i++){
		*dest = *(s1 + i);
		dest++;
	 }
   *dest = '\0';
   printf("%s", dest);
   return dest-number; /*RETURN A POINTER TO THE START OF THE SUBSTRING */
   free(dest);
  }
}

int main()
{
	char s1[] = "My name is Michael Scofield";
	char* dest = subStr(s1, 11, 16);
	printf("%s\n", dest); /* output will be "Michael Scofield" */
	return 0;
}