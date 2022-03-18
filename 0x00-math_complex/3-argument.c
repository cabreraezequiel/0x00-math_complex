#include "holberton.h"

/**
 * argument - returns the argument of a given complex number
 * @c: complex number c
 * Return: argument
 */

double argument(complex c);
{
	return(atan(c.im / c.re));
}
