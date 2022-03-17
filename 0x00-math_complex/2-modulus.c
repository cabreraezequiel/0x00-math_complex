#include "holberton.h"
#include <math.h>

/**
 * modulus - returns the modulus of a given complex number
 * @c: complex number c
 * Return: modulus
 */

double modulus(complex c)
{
	double result;
	double a = pow(c.re, 2);
	double b = pow(c.im, 2);

	result = sqrt(a + b);

	return(result);
}
