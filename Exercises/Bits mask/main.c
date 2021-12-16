uint32_t get_bits(uint32_t value, uint32_t shift, uint32_t bits) {
  uint32_t mask = 1;
  value = value >> shift; //number of bits to shift to right
  // create a mask according to the number of bits wanted
  for (uint32_t i = 0; i < bits; i++){
      mask *= 2; 
  }
  mask--;
  value = value & mask;
  return value;
}
