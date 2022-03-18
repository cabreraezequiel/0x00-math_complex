#include "holberton.h"

/**
 * display_complex_number - displays the complex numbers
 * @c: complex number c
 */

void display_complex_number(complex c)
{
	if (c.re == 0)
	{
		if (c.im == 0)
			printf("0\n");
		if (c.im < 0)
			printf("- %.9g\n", -(c.im));
		if (c.im > 0)
			printf("%.9g\n", c.im);
	}
	else
	{
		if (c.re > 0 && c.im > 0)
			printf("%.9g + %.9g\n", c.re, c.im);
		if (c.re < 0 && c.im > 0)
			printf("- %.9g + %.9g\n", -c.re, c.im);
		if (c.re > 0 && c.im < 0)
			printf("%.9g - %.9g\n", c.re, -c.im);
		if (c.re < 0 && c.im < 0)
			printf("- %.9g - %.9g\n", -c.re, -c.im);
		if (c.im == 0)
			printf("%.9g\n", c.re);
	}
}
