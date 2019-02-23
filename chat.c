#include <stdio.h>
#include <string.h>
/* #include "functions.c" */

int main() {
	char nameuser[12];
	int userChoice = 1;

	printf("Name(Max. 12 Characters): ");
	scanf("%s", &nameuser);

	do{
		char messageuser[127];
		FILE *fptr;

		printf("Message: ");
		scanf("%s", &messageuser);

		fptr = fopen("chat.txt", "a+");
		fprintf(fptr, "%s: %s\n", nameuser, messageuser);
		fclose(fptr);

		printf("Another Message? Yes = 1, No = 0: ");
		scanf("%d", &userChoice);
	}while(userChoice == 1);
	return 0;
}
