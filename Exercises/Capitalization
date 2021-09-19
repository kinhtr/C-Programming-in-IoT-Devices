#include <stdio.h>
#include <string.h>
#include <ctype.h>
#pragma warning(disable : 4996)

#define SIZE 100

void convert_upper(char* string);
int main(void) {
	char string[SIZE];
	int ongoing = 1;
	do {
		printf("Enter a string(\'stop\' or \'STOP\' to quit:");
		fgets(string, SIZE, stdin);
		if (strncmp(string, "stop", 4) == 0 || strncmp(string, "STOP", 4) == 0) {
			ongoing = 0;
		}
		else {
			convert_upper(string);
			printf("%s", string);
		}
	} while (ongoing);
	return 0;
}

void convert_upper(char* string) {
	if (isalpha(string[0])) {
		string[0] = toupper(string[0]);
	}
	for (int i = 1; string[i] != '\0'; i++) {
		if (isalpha(string[i]) && !isalpha(string[i-1])) {
			string[i] = toupper(string[i]);
		}
	}
}
