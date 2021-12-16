#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#pragma warning(disable : 4996)

#define SIZE 100

uint16_t crc16(const uint8_t* data_p, unsigned int length);
typedef struct chunk {
	uint8_t data[64];
	uint16_t size;
	uint16_t crc;
} crc_data;

int main(void) {
	FILE* read;
	char buffer[SIZE];
	char name[SIZE];
	crc_data* chunks;
	chunks = (crc_data*)calloc(1, sizeof(crc_data));

	printf("Enter the file name:");
	fgets(buffer, SIZE, stdin);
	sscanf(buffer, "%s", name);
	read = fopen(name, "rb");
	if (read == NULL) {
		puts("No such file found!");
		return 1;
	}
	int i = 0;
	int extra = 1;
	while (!feof(read)) {	
		chunks[i].size = fread(chunks[i].data, 1, 64, read);
		chunks = realloc(chunks, (1 + extra) * sizeof(crc_data));
		extra++;
		i++;
	}
	fclose(read);
	for (int a = 0; a < i; a++) {
		chunks[a].crc = crc16(chunks[a].data, chunks[a].size);
		printf("%d: %d: %04x\n", a+1, chunks[a].size, chunks[a].crc);
	}
	free(chunks);
	return 0;
}

uint16_t crc16(const uint8_t* data_p, unsigned int length) {
	uint8_t x;
	uint16_t crc = 0xFFFF;
	while (length--) {
		x = crc >> 8 ^ *data_p++;
		x ^= x >> 4;
		crc = (crc << 8) ^ ((uint16_t)(x << 12)) ^ ((uint16_t)(x << 5)) ^ ((uint16_t)x);
	}
	return crc;
}
