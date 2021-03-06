#include <stdio.h>
#pragma warning(disable : 4996)

#define SIZE 100
typedef struct myStruct
{
	char item[SIZE];
	char price[SIZE];
} itemPrice;
int main(void) {
	FILE* read;
	char name[SIZE], buffer[SIZE];
	itemPrice myList[20];
	int i = 0;
	
	printf("What is the name of the file you wanna open?");
	fgets(buffer, SIZE, stdin);
	sscanf(buffer, "%s", name);
	read = fopen(name, "r");

	if (read == NULL) {
		printf("Failed to open the file");
		return 1;
	}
	
	while (!feof(read)) {
		fgets(buffer, SIZE, read);
		if (sscanf(buffer, "%[^;];%[^\n]", myList[i].price, myList[i].item) == 2) {
			i++;
		}	
	}
	printf("%-50s", "Name");
	printf("%10s\n", "Price");
	for (int x = 0; x < i; x++) {
		printf("%-50s", myList[x].item);
		printf("%10s\n", myList[x].price);
	}
	return 0;
}
