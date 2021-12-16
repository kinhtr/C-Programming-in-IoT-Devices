void print_binaryw(uint32_t value, uint32_t width) {
  char binary[33];
  char binary1[33];
  int i;
  uint32_t zeros;
  for (i = 0; value != 0; i++) {
      if (value % 2) {
          binary[i] = '1';
      } else {
          binary[i] = '0';
      }
      value = value >> 1;
  }
  binary[i] = '\0';
  for (int i = (int)strlen(binary) - 1; i >= 0; i--) {
      binary1[(int)strlen(binary) -1 - i] = binary[i];
  }
  binary1[(int)strlen(binary)] = '\0';
  zeros = width - strlen(binary1);
  if (zeros > 0) {
      for (int z = 0; z < (int)zeros; z++) {
          for (int i = (int)strlen(binary1) + 1; i > 0; i--) {
              binary1[i] = binary1[i-1];
          }
          binary1[0] = '0';
      }
  }
  fputs(binary1, stdout);
}
