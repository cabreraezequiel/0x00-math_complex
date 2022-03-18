#include "holberton.h"

/**
 * conjugate - returns the conjugate of a given complex number
 * @c: complex number c
 * Return: conjugate
 */

complex conjugate(complex c)
{
	c.im = -(c.im);
	return (c);
}
