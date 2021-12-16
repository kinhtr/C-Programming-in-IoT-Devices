#include <stdio.h>
#pragma warning(disable : 4996)

#define SIZE_V 3

void matrix_multiplication(int *a, int *b, int matrix[][SIZE_V]);
void print_vector(int* x, int size);
int main(void) {
	int v[SIZE_V];
	int matrix[SIZE_V][SIZE_V];
	int result[SIZE_V] = {0};

	printf("The value of the result vector now is:\n");
	print_vector(result, SIZE_V);
	for (int i = 0; i < SIZE_V; i++) {
		printf("Enter values for vector: ");
		scanf("%d", &v[i]);
	}

	for (int x = 0; x < SIZE_V; x++) {
		printf("Enter values for row %d of the matrix\n", x + 1);
		for (int i = 0; i < SIZE_V; i++) {
			printf("Add value: ");
			scanf("%d", &matrix[x][i]);
		}
	}

	printf("Vector:\n");
	print_vector(v, SIZE_V);

	printf("Matrix:\n");
	for (int x = 0; x < SIZE_V; x++) {
		for (int i = 0; i < SIZE_V; i++) {
			if (i == SIZE_V - 1) {
				printf("%d\n", matrix[x][i]);
			}
			else {
				printf("%d ", matrix[x][i]);
			}
		}
	}

	matrix_multiplication(result, v, matrix);
	printf("The value of the result vector now is:\n");
	print_vector(result, SIZE_V);
	return 0;
}

void matrix_multiplication(int *a, int *b, int matrix[][SIZE_V]) {	
	for (int x = 0; x < SIZE_V; x++) {
		int sum = 0;
		for (int y = 0; y < SIZE_V; y++) {
			sum = sum + matrix[x][y] * b[y];
		}
		a[x] = sum;
	}
}

void print_vector(int* x, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d\n", x[i]);
	}
} 
