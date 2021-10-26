int printd(const char *format, ...) {
 char buffer[256];
 int chars;
 char format1[256] = "DEBUG: ";
 strcat(format1, format);
 va_list aptr;
 va_start(aptr, format1);
 chars = vsprintf(buffer, format1, aptr);
 fputs(buffer, stdout);
 va_end(aptr);
 return chars;
}
