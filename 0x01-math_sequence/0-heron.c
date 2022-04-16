#include "heron.h"

/**
 * heron - returns the Heron sequence until having convergence
 * with an error less or equal to 10^-7
 * @p: p
 * @x0: x0
 * Return: heron
 */

t_cell *heron(double p, double x0)
{
	t_cell *head;
	double m, err = 1, n = 10;

	for (m = 0; m < 7; m++)
	{
		n /= 10;
	}

	head = NULL;
	add_node(&head, 1);

	while (err > n)
	{
		x0 = ((0.5) * (x0 + (p / x0)));
		add_node(&head, x0);
		err = (x0 * x0) - p;
		if (err < 0)
			err *= -1;
	}

	return (head);
}

/**
 * add_node - adds a new node at the end of a t_cell list
 * @head: head
 * @n: n
 * Return: new end
 */

t_cell *add_node(t_cell **head, const double n)
{
	t_cell *nhead;

	nhead = malloc(sizeof(**head));
	if (nhead == NULL)
	{
		return (NULL);
	}
	nhead->elt = n;
	nhead->next = (*head);
	(*head) = nhead;

	return (nhead);
}
