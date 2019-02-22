#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "readText.c"

int main()
{
  char nameuser[12];
  int userChoice;

  printf("Name(Max. 12 Characters): ");
  gets(nameuser);

  do
  {
    char messageuser[127];
    char showFile[10][20] = {"show", "chat", "messages"};
    FILE *fptr;

    printf("Message: ");
    gets(messageuser);

    if(!strcmp(messageuser, "chat"))
    {
      //readText();
      printf("Nice work\n");
    }
    else
    {
      fptr = fopen("/Users/lucamathuse/Desktop/Test/chat.txt", "a");
      fprintf(fptr, "%s: %s\n", nameuser, messageuser);
      fclose(fptr);
    }

    //userChoice = userChoice1;

    printf("Another Message? Yes = 1, No = 0: ");
    scanf("%d", &userChoice);


  }
  while(userChoice == 1);

  return 0;
}
