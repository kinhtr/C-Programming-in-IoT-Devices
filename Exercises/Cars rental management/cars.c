#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

#define SIZE 15
#define PLATE_SIZE 7

typedef struct rental_cars {
	char brand[SIZE];
	char model[SIZE];
	char rental_category[SIZE];
	char plate[SIZE];
	int mileage;
	int available;
} rental; // create a nickname of the struct using typedef

void print_available(char* type, rental *cars);
int change_state(char* plate, rental* cars);
int main(void) {
	// use the nickname to declare a struct array
	rental cars[SIZE] = {
		{"Fiat",         "Panda",    "NBCN", "REU 269", 150000, 0},
		{"Seat",         "Ibiza",    "INMN", "TEQ 413", 70540,  1},
        {"Volkswagen",   "Polo",     "MENE", "PSR 680", 294157, 1},
        {"Dacia",        "Logan",    "FNAV", "DJD 385", 89901,  0},
        {"Aston Martin", "Vanquish", "XNMV", "LCB 690", 13871,  1},
        {"Fiat",         "Punto",    "ECAQ", "YRY 818", 282439, 0},
        {"Nissan",       "Micra",    "ECAQ", "AKS 194", 66075,  1},
        {"Porsche",      "918",      "XNMV", "FRU 886", 120134, 0},
        {"Ford",         "Focus",    "CENE", "LHD 668", 249621, 1},          
		{"Ford",         "Fiesta",   "ETNH", "LNF 229", 97896,  0},                       
		{"Audi",         "A4",       "XWDZ", "YHP 205", 276653, 1},             
		{"Honda",        "Accord",   "MBDV", "NFP 736", 123405, 0},            
		{"Skoda",        "Octavia",  "CCNV", "CKA 983", 116977, 0},              
		{"Toyota",       "Yaris",    "IWNE", "XZQ 603", 58821,  0},             
		{"Chevrolet",    "Spark",    "XTDD", "JLT 243", 257177, 1}
	};

	char temp[SIZE];
	int input;
	do {
		printf("What do you wanna do?\n");
		printf("1. Print all cars\n2. Print free cars of given category\n3. Change state of a car\n4. Quit\n");
		fgets(temp, SIZE, stdin);
		sscanf(temp, "%d", &input);
		if (input == 1) {
			const char astra = '*';
			print_available(&astra, cars);
		}
		else if (input == 2) {
			char type;
			do {
				printf("Enter rental car category(* is not accepted): ");
				fgets(temp, SIZE, stdin);
				sscanf(temp, "%c", &type);
			} while (type == '*');	
			print_available(&type, cars);
		}
		else if (input == 3) {
			int found;
			printf("Enter registration plate of the car you want to change its availability: ");
			fgets(temp, SIZE, stdin);
			found = change_state(temp, cars);
			if (found) {
				printf("Car availability changed\n");
			} else {
				printf("Car not found!\n");
			}
		}
		else if (input == 4) {
			printf("Exiting the program...");
		}
		else {
			printf("Wrong input!\n");
		}
	} while (input != 4); 
	return 0;
}

void print_available(char *type, rental *cars) {
	printf("%-15s%-15s%-15s%-15s%7s%15s\n", "Brand", "Model", "Category", "Plate", "Mileage", "Availability");
	for (int i = 0; i < SIZE; i++) {
		if ((strncmp(cars[i].rental_category, type, 1) == 0  && cars[i].available) || *type == '*') {
			printf("%-15s", cars[i].brand);
			printf("%-15s", cars[i].model);
			printf("%-15s", cars[i].rental_category);
			printf("%-15s", cars[i].plate);
			printf("%7d", cars[i].mileage);
			printf("%15d\n", cars[i].available);
		}
	}
	printf("\n");
}

int change_state(char *plate, rental *cars) {
	int found = 0;
	for (int i = 0; i < SIZE; i++) {
		if (strncmp(plate, cars[i].plate, PLATE_SIZE) == 0) {
			found = 1;
			cars[i].available = !cars[i].available;
		}
	}
	return found;
}
