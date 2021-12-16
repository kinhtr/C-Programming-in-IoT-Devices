/*The variabale arguments are pointers to strings. 
The end of arguments is indicated by a NULL pointer. 
The function returns the number of strings. 
Function also counts total number of characters in the strings and stores the total through the first parameter.*/

int count_args(int *number, ...) {
    int count = 0;
    int i;
    char *string = NULL;
    va_list ap;
    va_start(ap, number);
    for (i = 0; (string = va_arg(ap, char*)) != NULL; i++) {
        count += (int)strlen(string);
    }
    va_end(ap);
    *number = count;
    return i;
}
