/*Binary reader takes a pointer to unsigned int as parameter and returns boolean value.
True means that a binary number was successfully read.
Call read_line to read strings that are to be converted to unsigned integers.
Read_line returns true when a line was successfully read and false when the end of input is reached.*/

bool binary_reader(unsigned int *pu) {
    char line[100];
    char *string = line;
    int offset;
    *pu = 0;
    // get rid of possible white space
    if (read_line(line, 100)) {
        for (offset = 0; isspace(string[offset]); offset++);
        string += offset; 
    }
    if (string[0] == '0' && string[1] == 'b') {
        int i = 2;
        while (string[i] == '0' || string[i] == '1') {
            *pu = *pu << 1;
            if (string[i] == '0') {
                *pu += 0;
            } else {
                *pu += 1;
            }
            i++;
        }
        if (i > 2) {
            return true;
        }
    }
    return false;
}

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
