#include "heron.h"
#include <math.h>

/**
 * display_complex_number - displays the complex numbers
 * @c: complex number c
 */

t_cell *fibonnaci()
{
	double un = x0;
	t_cell *head;
	t_cell *aux;
	int m = 1,;

	head = malloc(sizeof(*aux));
	while((sqrt(p)) + (pow(10, -7)) < un)
	{
		un = ((1 / 2) * (m + p / m));
		aux->elt = un;
		aux = aux->next;
		if (m == 1)
			head = aux;
		m++;
	}

	return (head);
}

/**
 * add_nodeint_end - adds a new node at the end of a t_cell list
 * @head: head
 * @n: n
 * Return: new end
 */

t_cell *add_nodeint_end(t_cell **head, const double n)
{
	listint_t *nend;
	listint_t *aux = *head;

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
