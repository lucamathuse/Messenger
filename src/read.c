#include <stdio.h>

void read()
{
  char c;
  FILE *fptr;
  fptr = fopen("./chat.txt","r");

  if(fptr == NULL)
  {
    printf("Something went wrong");
  }

  c = fgetc(fptr);
  while(c != EOF)
  {
    printf ("%c", c);
    c = fgetc(fptr);
  }
  fclose(fptr);
}
