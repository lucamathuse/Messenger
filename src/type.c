#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curses.h>
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

    FILE *fptr;

    printf("Message: ");
    for(;;) {
        int c = getch();
        if(c == 10){
            break;
          }
        }


    fptr = fopen("/Users/lucamathuse/Desktop/Private/Coding/C/messenger/chat.txt", "a");
    fprintf(fptr, "%s: %s\n", nameuser, messageuser);
    fclose(fptr);


    printf("Another Message? Yes = 1, No = 0: ");
    scanf("%d", &userChoice);


  }
  while(userChoice == 1);

  return 0;
}
