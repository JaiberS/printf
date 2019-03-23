#include "holberton.h"

/**
 * getfunction- selects the correct function to perform the operation
 * @format: Operator given
 *
 * Return: a pointer to the function that corresponds to the operator given
 */
int (*getfunction(const char format))(va_list, options)
{
	int i_struct = 0;
	op_t print[] = {
		{"c", print_char},
		{"i", print_integer},
//		{"f", print_float},
		{"s", print_string},
		{NULL, NULL}
	};

	while (format != '\0')
	{
		i_struct = 0;
		while (print[i_struct].op != NULL)
		{
			if (format == *(print[i_struct].op))
			{
				return (print[i_struct].f);
			}
			i_struct++;
		}
	}
	return (NULL);
}

/**
 * str_length - calculate length
 * @str: strint to calculate length
 * Return: length of array
 */
unsigned int str_length(char *str)
{
	unsigned int iterator = 0;

	while (str[iterator])
		iterator++;
	return (iterator);
}


/**
 * print_integer - print integer
 * @valist: valist
 */
int print_integer(va_list valist, options opt)
{
	char *str;
	char flag;

	str = number_to_string(va_arg(valist, int));
	if (opt.signp == 1)
	{
		flag = '+';
		write(1,&flag,1);
		return (_putchar(str, str_length(str)) + 1);
	}
	return (_putchar(str, str_length(str)));
}

/**
 * print_string - print string
 * @valist: valist
 */
int print_string(va_list valist, options opt)
{
	char *str = va_arg(valist, char*);
	(void) opt;

	return (_putchar(str, str_length(str)));
}
/**
 * print_string - print string
 * @valist: valist
 */
int print_float(va_list valist, options opt)
{
	char *str = va_arg(valist, char*);
	(void) opt;

	return (_putchar(str, str_length(str)));
}
