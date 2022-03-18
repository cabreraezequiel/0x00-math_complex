#include "holberton.h"

/**
 * display_complex_number - displays the complex numbers
 * @c: complex number c
 */

void display_complex_number(complex c)
{
	if (c.re == 0)
	{
		printf("0");
		if (c.im == 1)
			printf(" + i");
		if (c.im == -1)
			printf(" - i");
		if (c.im < -1)
			printf(" - %.9gi", -(c.im));
		if (c.im > 1)
			printf(" + %.9gi", c.im);
	}
	else
	{
		if (c.re > 0)
			printf("%.9g", c.re);
		if (c.re < 0)
			printf("- %.9g", -(c.re));
		if (c.im == 1)
			printf(" + i");
		if (c.im == -1)
			printf(" - i");
		if (c.im < -1)
			printf(" - %.9gi", -(c.im));
		if (c.im > 1)
			printf(" + %.9gi", c.im);
	}
	printf("\n");
}
