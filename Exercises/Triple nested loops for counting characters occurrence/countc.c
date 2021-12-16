/*The string contains characters to count from the file. Function returns the total count of occurrence of any characters in the string. 
For example if the string is "R" function counts number of capital Rs in the file. 
String "abc" counts the total number of letters a, b, and c in the file.*/

int count_chars(const char *characters, FILE *stream) {
    int total = 0;
    char line[100];
    while (fgets(line, 100, stream) != NULL) {
        for (int j = 0; j < (int)strlen(characters); j++) {
            for (int i = 0; i < (int)strlen(line); i++) {
                if(characters[j] == line[i]) {
                    total++;
                }
            }
        }
    }
    return total;
}
