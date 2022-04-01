#include "heron.h"
#include <math.h>

/**
 * display_complex_number - displays the complex numbers
 * @c: complex number c
 */

t_cell *heron(double p, double x0)
{
	double un;
	t_cell *head;

	while(pow(10, -7) > sqrt(p))
	{
		un = (1 / 2 * (x0 + p / x0));
		head->elt = un;
		head = head->next;
		p = un;
	}

	return (head);
}
