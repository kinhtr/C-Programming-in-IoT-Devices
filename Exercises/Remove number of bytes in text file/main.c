#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

#define SIZE 50
int main(void) {
	FILE *read, *write;
	int size, offset, remove;
	char buffer[SIZE], name[SIZE];
	char* string;
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
	string = (char*)calloc(size+1, sizeof(char));
	fread(string, 1, size, read);
	fclose(read);
	printf("The size of the file is %d bytes\n", size);
	do {
		printf("Enter the offset: ");
		scanf("%d", &offset);
		if (offset > size - 1 || offset < 0) {
			puts("Invalid offset! Try again");
		}
	} while (offset > size - 1 || offset < 0);
	do {
		printf("How many bytes you wanna remove? ");
		scanf("%d", &remove);
		if (offset + remove > size || remove < 0) {
			puts("Error occurs! Try again");
		}
	} while (offset + remove > size || remove < 0);
	for (int i = offset; string[i] != '\0'; i++) {
		string[i] = string[i + remove];
	}
	puts(string); 
	write = fopen(name, "wb");
	fwrite(string, 1, size - remove, write);
	free(string);
	fclose(write);
	return 0;
}
