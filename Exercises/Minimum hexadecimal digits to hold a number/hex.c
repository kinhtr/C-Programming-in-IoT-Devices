//Digit counter returns the minimum number of hexadecimal digits that are needed to print the number given as parameter

int digit_counter(unsigned int nr) {
    int count = 0;
    while (nr > 0) {
        nr = nr >> 4;
        count++;
    }
    if (count == 0) {
        count = 1;
    }
    return count;
}
