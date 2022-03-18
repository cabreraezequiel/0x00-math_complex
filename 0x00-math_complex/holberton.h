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
double argument(complex c);
void addition(complex c1, complex c2, complex *c3);
void substraction(complex c1, complex c2, complex *c3);
void multiplication(complex c1, complex c2, complex *c3);
void division(complex c1, complex c2, complex *c3);

#endif /* MAIN */
