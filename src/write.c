#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void write(char message[128]) {
  FILE *fptr;
  time_t rawtime;
  struct tm *info;
  char buffer[80];

  time( &rawtime );

  info = localtime( &rawtime );

  strftime(buffer,80,"%x - %I:%M:%p", info);

  fptr = fopen("./chat.txt", "a");
  fprintf(fptr,"%s: %s\n", buffer,message);
  fclose(fptr);
}
