#ifndef MAIN
#define MAIN
#include <stddef.h>
#include <stdio.h>
#include <math.h>

/**
 * struct complex - complex numbers
 * @re: Real part
 * @im: Imaginary part
 */

typedef struct complex
{
	double re;
	double im;
} complex;

void display_complex_number(complex c);
complex conjugate(complex c);
double modulus(complex c);

#endif /* MAIN */
