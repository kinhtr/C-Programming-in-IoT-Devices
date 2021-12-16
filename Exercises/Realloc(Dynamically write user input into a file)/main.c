#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

#define SIZE 16
int main(void) {
	FILE* write;
	write = fopen("text13.txt", "w");
	char* input;
	do {
		printf("Enter a string: ");
		input = (char*)calloc(SIZE, sizeof(char));
		fgets(input, SIZE, stdin);
		int extra = 1;
		while (input[strlen(input) - 1] != '\n') {
			input = realloc(input, (SIZE + extra) * sizeof(char));
			input = input + SIZE - 2 + extra;
			fgets(input, 2, stdin);
			input = input - SIZE + 2 - extra;
			extra++;
		}
		if (input[strlen(input) - 1] == '\n') {
			input[strlen(input) - 1] = '\0';
		}

		if (strcmp(input, ".") != 0) {
			fprintf(write, "%d:%s\n", strlen(input), input);
			free(input);
		}
	} while (strcmp(input, ".") != 0);
	free(input);
	fclose(write);
	return 0;
}
