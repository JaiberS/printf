#include "holberton.h"

/**
 * print_char - print character
 * @valist: character to be printed
 * @opt: option to be printer
 * Return: num of bytes printed
 */
int print_char(va_list valist, options opt)
{
	char p = va_arg(valist, int);
	(void)opt;

	if ((p >= 32 &&  p <= 126) || (p >= 7 && p <= 13) || p == '\0')
	{
		return (write(1, &p, 1));
	}
	return (0);
}
