#include "holberton.h"

/**
 * complex_from_mod_arg - updates the real and the imaginary parts of a complex
 * number given its modulus and arguments
 * @m: modulus
 * @arg: argument
 * @c3: result
 */

void complex_from_mod_arg (double m, double arg, complex *c3)
{
	double PI = acos(-1.0);

	c3->re = tan((arg * 180) / PI) * m;
	c3->im = sin((arg * 180) / PI) * m;
}
