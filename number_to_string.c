#include "holberton.h"
/**
 * reverse_str - reverse string
 * @str: string to reverse
 * @size: size of string
 */
void reverse_str(char *str, int size)
{
	int length;
	int iterator;
	char aux;

	if (*str == '-')
		reverse_str(str + 1, size - 1);
	else
	{
		length = size % 2 == 0 ? size / 2 : ((size / 2) + 1);
		for  (iterator = 0; iterator < length; iterator++)
		{
			aux = str[iterator];
			str[iterator] = str[size - iterator - 1];
			str[size - iterator - 1] = aux;
		}
	}
}

/**
 * number_to_string - convert number to string
 * you should free the pointer returned
 * @number: number to be printed
 *
 * Return: string converted
 */
char *number_to_string(int number)
{
	int lengh = 0;
	int aux;
	char *p = malloc(1);

	if (p == NULL)
		return (NULL);
	do {
		if (number < 0)
		{
			p[0] = '-';
			lengh++;
			p = _realloc(p, lengh, lengh + 1);
			aux = number % 10;
			p[lengh] = (-aux) + '0';
			aux = number / 10;
			number = -aux;
		}
		else
		{
			p[lengh] = (number % 10) + '0';
			number /= 10;
		}
		lengh++;
		p = _realloc(p, lengh, lengh + 1);
		if (p == NULL)
			return (NULL);
		p[lengh] = '\0';
	} while (number);
	reverse_str(p, lengh);
	return (p);
}
/**
 * _realloc -  reallocates a memory block
 * @ptr: is a pointer to the memory previously allocated
 * @old_size: is the size, in bytes, of the allocated space for ptr
 * @new_size: is the new size, in bytes of the new memory block
 *
 * Return: pointer to the new allocation with the values from prev
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p, *ptr1 = ptr;
	unsigned int iterator = 0;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	p = malloc(new_size);
	if (p == NULL)
	{
		free(p);
		return (NULL);
	}
	while (iterator < new_size - 1)
	{
		p[iterator] = ptr1[iterator];
		iterator++;
	}
	free(ptr);
	return (p);
}
