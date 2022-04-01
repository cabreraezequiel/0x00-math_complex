#include "heron.h"
#include <math.h>

/**
 * heron - returns the Heron sequence until having convergence
 * with an error less or equal to 10^-7
 * @p: p
 * @x0: x0
 * Return: heron
 */

t_cell *heron(double p, double x0)
{
	double un = x0;
	t_cell *head;
	double m = 1;

	head = NULL;
	while ((sqrt(p)) + (pow(10, -7)) < un)
	{
		un = ((0.5) * (m + p / m));
		add_node(&head, un);
		m++;
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
	t_cell *nend;
	t_cell *aux = *head;

	nend = malloc(sizeof(t_cell));
	if (nend == NULL)
	{
		return (NULL);
	}
	nend->elt = n;
	nend->next = NULL;

	if (*head == NULL)
	{
		*head = nend;
	}
	else
	{
		while (aux->next != NULL)
		{
			aux = aux->next;
		}
		aux->next = nend;
	}
	return (nend);
}
