#include "holberton.h"

/**
 *
 *
 */

void display_complex_number(complex c)
{
	if (c.re != 0)
	{
		printf("%g", c.re);
		if (c.im != 0)
		{
			printf(" + ");
		}
	}
	if (c.im != 0)
	{
		printf("%gi", c.im);
	}
	if (c.re != 0 || c.im != 0)
	{
		printf("\n");
	}
}
