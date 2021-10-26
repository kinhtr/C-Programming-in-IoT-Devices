#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

#define SIZE 50
#define A_SIZE 256
#define TEN 10
void print_frequency(int* numbers, int size);
int main(void) {
	FILE* read;
	int size;
	char buffer[SIZE], name[SIZE];
	char* string = NULL;
	int count[A_SIZE] = {0};
	printf("Enter the file name:");
	fgets(buffer, 20, stdin);
	sscanf(buffer, "%s", name);

	read = fopen(name, "rb");
	if (read == NULL) {
		puts("No such file found!");
		return 1;
	}
	fseek(read, 0, SEEK_END);
	size = ftell(read);
	fseek(read, 0, SEEK_SET);
	// dynamic string for holding the content of the file
	string = (char*)calloc(size + 1, sizeof(char));
	fread(string, 1, size, read);
	fclose(read);

	for (int i = 0; i < size; i++) {
		count[(int)string[i]]++;
	} 
	printf("Top 10 characters with the most frequency:\n");
	for (int i = 0; i < TEN; i++) {
		printf("%d. ", i + 1);
		print_frequency(count, A_SIZE);
	}
	return 0;
}

void print_frequency(int *numbers, int size) {
	int max = 0;
	char character = '\0';
	for (int i = 0; i < size; i++) {
		if (numbers[i] > max) {
			max = numbers[i];
			character = (char)i;
		}
	}
	//printf("<<%c>>  <<%d>> <<%d>>\n", character, max, character);
	numbers[(int)character] = 0;

	if (character == '\n') {
		printf("'\\n': %d\n", max);
	}
	else if (character == '\r') {
		printf("'\\r': %d\n", max);
	}
	else {
		printf("'%c': %d\n", character, max);
	}
}
