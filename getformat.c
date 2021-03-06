#include "holberton.h"

/**
 * getformat - get the char after the %
 * @c: the string
 * @pos: position of format
 *
 * Return: Option contain the char after %
 * 0 if fails
 */

options getformat(const char *c, int *pos)
{
	int i = *pos;
	options op;

	op.precision = 0;
	for (; c[i]; i++)
	{
		if (c[i + 1] > '0' && c[i + 1] <= '9')
			op.precision =  op.precision + c[i + 1] - 48;
		if (c[i + 1] == '-')
			op.signn = 1;
		if (c[i + 1] == '+')
			op.signp = 1;
		if (c[i + 1] == ' ')
			op.spc = 1;
		if (c[i + 1] == '0')
			op.zeros = 1;
		if (c[i + 1] == '#')
			op.hash = 1;
		if (c[i + 1] == '.')
			op.point = 1;
		if (c[i + 1] == 'l')
			op.longer = 1;
		if (c[i + 1] == 'h')
			op.sh = 1;
		if ((c[i + 1] > '0' && c[i + 1] <= '9') || c[i + 1] == '-'
		    || c[i + 1] == '+' || c[i + 1] == ' ' || c[i + 1] == '0'
		    || c[i + 1] == '#' || c[i + 1] == '.' || c[i + 1] == 'l'
		    || c[i + 1] == 'h')
			continue;
		*pos = i + 1;
		op.type = c[i + 1];
		return (op);
	}
	op.type = 0;
	return (op);
}
