#ifndef HOLBERTON_H
#define HOLBERTON_H

/*#include <stdio.h>
  #include <stdlib.h>*/
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
int _putchar(char *c, unsigned int lenght);
int _printf(const char *format, ...);
void reverse_str(char *str, int size);
char *number_to_string(int number);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif /* HOLBERTON_H */
