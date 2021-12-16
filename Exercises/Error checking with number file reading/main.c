#include <stdio.h>
#pragma warning(disable : 4996)

int main(void) {
	FILE* file;
	int count;
	int count2 = 0;
	float n;
	float sum = 0;
	file = fopen("Text.txt", "r");
	
	if (file == NULL) {
		printf("Failed to open the file");
		return (1);
	}
	else {
		char temp[10];
		fgets(temp, 10, file);
		sscanf(temp, "%d", &count);
		for (int i = 0; i < count; i++) {
			if (fgets(temp, 10, file) != NULL) {
				if (sscanf(temp, "%f", &n) == 1) {
					sum += n;
					count2 += 1;
				}
				else {
					printf("Invalid read at line %d\n", i+1);
				}
			}
		}
		if (count2 == count) {
			printf("Average of numbers is: %.2f", sum / count2);
		}
		else {
			printf("Error! Tried to read %d numbers, %d numbers were read.\n", count, count2);
			printf("Average of %d numbers is: %.2f", count2, sum / count2);
		}
	}
	fclose(file);
	return 0;
}
