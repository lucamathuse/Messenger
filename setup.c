#include <stdio.h>

int main()
{
  FILE *fptr;
  int setupChoice = 0;

  printf("Choose your OS\n");
  printf("[1] Linux\n");
  printf("[2] MacOS\n");

  do {
    printf(">>> ");
    scanf("%d", &setupChoice);
  } while(setupChoice == 0);

  if(setupChoice == 1){

    fptr = fopen("./setup/linux.txt", "w");
    fprintf(fptr, "Linux");
    fclose(fptr);
  }
  if (setupChoice == 2){
    fptr = fopen("./setup/mac.txt", "w");
    fprintf(fptr, "Mac");
    fclose(fptr);
  }
  return 0;

}
