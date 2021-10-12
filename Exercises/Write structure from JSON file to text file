#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

#define SIZE 15
#define B_SIZE 30
typedef struct car {
	char brand[SIZE];
	char model[SIZE];
	int price;
	float co2_emission;
} car;

int main(void) {
	car cars[SIZE] = {
		{"Fiat",         "Panda",    16000, 91},
		{"Seat",         "Ibiza",    15000, 100},
		{"Volkswagen",   "Polo",     10000, 120},
		{"Dacia",        "Logan",    22000, 80},
		{"Aston Martin", "Vanquish", 11500, 70},
		{"Fiat",         "Punto",    30000, 50},
		{"Nissan",       "Micra",    26000, 120},
		{"Porsche",      "918",      25000, 100},
		{"Ford",         "Focus",    21000, 96},
		{"Ford",         "Fiesta",   13000, 250},
		{"Audi",         "A4",       23500, 150},
		{"Honda",        "Accord",   18000, 80},
		{"Skoda",        "Octavia",  23000, 50},
		{"Toyota",       "Yaris",    21750, 66},
		{"Chevrolet",    "Spark",    35000, 99}
	};
	int input = 0;
	char buffer[B_SIZE];
	car extra;
	FILE* write;
	write = fopen("text18.txt", "wb");
	fwrite(cars, sizeof(car), SIZE, write);
	fclose(write);
	while (input != 4) {
		printf("1. print all cars in the file\n2. add new car to the end of the file\n");
		printf("3. add new car from text file to the end of the file.\n4. quit the program\n");
		fgets(buffer, B_SIZE, stdin);
		sscanf(buffer, "%d", &input);
		if (input == 1) {
			car temp;
			FILE* read;	
			read = fopen("text18.txt", "rb");
			while (fread(&temp, sizeof(car), 1, read)) {
				printf("%s: %s: %d: %.2f\n", temp.brand, temp.model, temp.price, temp.co2_emission);
			}
			fclose(read);
		}
		else if (input == 2) {
			FILE* append, * read;
			printf("Enter the brand of the car: ");
			fgets(buffer, B_SIZE, stdin);
			sscanf(buffer, "%[^\n]", extra.brand);
			printf("Enter the model of the car: ");
			fgets(buffer, B_SIZE, stdin);
			sscanf(buffer, "%[^\n]", extra.model);
			printf("Enter the price of the car: ");
			fgets(buffer, B_SIZE, stdin);
			sscanf(buffer, "%d", &extra.price);
			printf("Enter the co2 emissions of the car: ");
			fgets(buffer, B_SIZE, stdin);
			sscanf(buffer, "%f", &extra.co2_emission);
			append = fopen("text18.txt", "ab");
			fwrite(&extra, sizeof(car), 1, append);
			fclose(append);
		}
		else if (input == 3) {
			FILE* read, *append;
			char name[SIZE];
			printf("Enter the name of the file to add from: ");
			fgets(buffer, B_SIZE, stdin);
			sscanf(buffer, "%s", name);
			read = fopen(name, "r");
			if (read == NULL) {
				puts("No such file found!");
			}
			else {
				int count = 0;
				char string[B_SIZE];
				while (!feof(read)) {
					fgets(buffer, B_SIZE, read);
					sscanf(buffer, "%[^\n]", string);
					if (strstr(string, "make") != NULL) {
						sscanf(string, "%*[^:]:\"%[^\"]",  extra.brand);
					}
					else if (strstr(string, "model") != NULL) {
						sscanf(string, "%*[^:]:\"%[^\"]",  extra.model);
					}
					else if (strstr(string, "price") != NULL) {
						sscanf(string, "%*[^:]:%d",  &extra.price);
					}
					else if (strstr(string, "emissions") != NULL) {
						sscanf(string, "%*[^:]:%f",  &extra.co2_emission);
					}
					count++;
				}
				append = fopen("text18.txt", "ab");
				fwrite(&extra, sizeof(car), 1, append);
				fclose(append);
			}
			fclose(read);
		}
		else if (input == 4) {
			puts("Quitting the program..");
		}
		else {
			puts("Invalid input!");
		}
	}
	return 0;
}
