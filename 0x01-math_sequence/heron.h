#ifndef MAIN
#define MAIN
#include <stddef.h>
#include <stdio.h>
#include <math.h>

typedef struct cell
{
	double elt;
	struct cell *next;
} t_cell;

t_cell *heron(double p, double x0);

#endif /* MAIN */
