#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curses.h>
//#include "readText.c"

void write(char message[128]) {
  FILE *fptr;

  fptr = fopen("./chat.txt", "a");
  fprintf(fptr,"%s\n", message);
  fclose(fptr);
}
