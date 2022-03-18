#include "holberton.h"

/**
 * division - performs the division operation to complex numbers
 * @c1: first complex number
 * @c2: second complex number
 * @c3: result
 */

void division(complex c1, complex c2, complex *c3)
{
	double a = c1.re, b = c1.im, c = c2.re, d = c2.im;

	c3->re = (a * c + b * d) / (pow(c, 2) + pow(d, 2));
	c3->im = (b * c - a * d) / (pow(c, 2) + pow(d, 2));
}
