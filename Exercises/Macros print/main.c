#include <stdio.h>
#pragma warning(disable : 4996)

#define SIZE 5
#ifdef _DEBUG 
#define DEBUGMSG(...) printf(__VA_ARGS__)
#else
#define DEBUGMSG(...)
#endif

int main(void) {
	int num[SIZE];
	printf("Enter 5 integers\n");
	for (int i = 0; i < SIZE; i++) {
		printf("Enter the %d number:", i + 1);
		scanf("%d", &num[i]);
	}
	for (int i = 0; i < SIZE; i++) {
		DEBUGMSG("%d\n", num[i]);
	}
	return 0;
}
