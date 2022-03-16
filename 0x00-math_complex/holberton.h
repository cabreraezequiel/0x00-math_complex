#ifndef MAIN
#define MAIN
#include <stddef.h>
#include <stdio.h>

typedef struct complex
{
	double re;
	double im;
} complex;

void display_complex_number(complex c);

#endif /* MAIN */
