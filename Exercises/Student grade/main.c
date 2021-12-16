#include <stdio.h>
#pragma warning(disable : 4996)

#define SIZE 100
float average(int* array, int size);

int main(void) {
	int grades[SIZE] = {0};
	int students;
	printf("How many students?");
	scanf("%d", &students);
	if (students > SIZE) {
		printf("Too many students in one class!");
		return 1;
	}
	for (int i = 0; i < students; i++) {
		int grade;
		do {
			printf("Enter student %d grade", 45000 + i);
			scanf("%d", &grade);
		} while (grade < 0 || grade > 5);
		grades[i] = grade;
	}
	float result = average(grades, students);
	printf("The average grade of the course is %.2f\n", result);
	return 0;
}
float average(int* array, int size) {
	int sum = 0;
	int count = 0;
	for (int i = 0; i < size; i++) {
		sum += array[i];
		count++;
	}
	return (float)sum / count;
}
