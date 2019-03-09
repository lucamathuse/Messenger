#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curses.h>
//#include "readText.c"

void write()
{
  char nameuser[12];
  int userChoice;

  printf("Name(Max. 12 Characters): ");
  gets(nameuser);

  do
  {

    FILE *fptr;

    fptr = fopen("chat.txt", "a");
    fprintf(fptr, "%s: %s\n", nameuser, messageuser);
    fclose(fptr);


    printf("Another Message? Yes = 1, No = 0: ");
    scanf("%d", &userChoice);


  }
  while(userChoice == 1);

  return 0;
}
