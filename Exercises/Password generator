#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#pragma warning(disable : 4996)

#define SIZE 10
#define P_SIZE 10
void pass_generator(char* password, int size, const char* words[P_SIZE]);
char random_char(void);
int main(void) {
	srand((unsigned)time(NULL));
	char password[SIZE];
	const char* words[P_SIZE] = { "one", "two", "threeThoundsands", "fourEmperors", "fiveHigh", "six", "sevenUp", "eight", "nine", "tenOutofTen"};
	pass_generator(password, SIZE, words);
	return 0;
}

void pass_generator (char *password, int size, const char *words[P_SIZE]) {
	char* temp = (words[rand() % P_SIZE]);
	int position;
	for (int i = 0; i < size; i++) {
		if (i == size - 1) {
			password[i] = '\0';
		}
		else {
			password[i] = random_char();
		}
	}
	puts(password);
	puts(temp);
	if ((int)strlen(temp) <= size - 1) {
		position = rand() % (size - (int)strlen(temp));
		for (int i = 0; i < (int)strlen(temp); i++) {
			password[position] = temp[i];
			position++;
		}
		puts(password);
	}
	else {
		puts("The length of the password is too short for the random words!");
		exit(1);
	}
}

char random_char(void) {
	int character;
	do {
		character = (rand() % 256);
	} while (!isprint(character));
	return (char)character;
}
