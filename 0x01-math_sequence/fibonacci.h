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
	int elt;
	struct cell *next;
} t_cell;

t_cell *add_node(t_cell **head, const int n);
t_cell *Fibonnaci();
t_cell *get_node(t_cell *head, int index);

#endif /* MAIN */
