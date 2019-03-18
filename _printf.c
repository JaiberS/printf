#include "holberton.h"

/**
 * _printf -  produces output according to a format.
 * @format: format to be printed
 *
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */

int _printf(const char *format, ...)
{
	va_list valist;
	op_t operate;
	options formatto;
	char p;
	int i = 0, bytes = 0;

	va_start(valist, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			formatto = getformat(format, &i);
			if (formatto.type == 0)
			{
			}
		}
		else
		{
			p = format[i];
			if (p >= 32 &&  p <= 126)
			{
				write(1, &p, 1);
				bytes++;
			}
			else
			{
			}
			i++;
			continue;
		}
		operate.f = getfunction(formatto.type);
		if (operate.f != NULL)
		{
			bytes += operate.f(valist, formatto);
		}
		i++;
	}
	va_end(valist);
	return (bytes);
}
