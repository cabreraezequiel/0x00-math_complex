#ifndef MAIN
#define MAIN
#include <stddef.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * struct cell - cell
 * @elt: elt
 * @next: next
 */
typedef struct cell
{
	double elt;
	struct cell *next;
} t_cell;

t_cell *heron(double p, double x0);
t_cell *add_node(t_cell **head, const double n);

#endif /* MAIN */
