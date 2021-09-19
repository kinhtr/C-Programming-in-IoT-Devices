void swap(int *a, int *b) {
	int x;
	x = *a;
	*a = *b;
	*b = x;
}

void sort(int* c, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (c[j+1] < c[j]) {
				swap(&c[j], &c[j + 1]);
			}
		}
	}
}
