#include "holberton.h"

/**
 * display_complex_number - displays the complex numbers
 * @c: complex number c
 */

void display_complex_number(complex c)
{
	if (c.re != 0)
	{
		printf("%.9g", c.re);
		if (c.im > 0)
		{
			printf(" + ");
		}
	}
	if (c.im > 1 || c.im == 0)
	{
		printf("%.9g", c.im);
	}
	if (c.im < 0)
	{
		printf(" - %.9g", -(c.im));
	}
	if (c.im != 0)
	{
		printf("i");
	}
	printf("\n");
}
