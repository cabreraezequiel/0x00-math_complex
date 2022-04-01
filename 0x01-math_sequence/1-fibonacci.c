#include "fibonacci.h"
#include <math.h>

/**
 * display_complex_number - displays the complex numbers
 * @c: complex number c
 */

t_cell *Fibonnaci()
{
	int n = 1, f, a, b;
	t_cell *head;

	head = NULL;
	for (n = 1; f < 6800; n++)
	{
		if (n <= 2)
			add_node(&head, 1);

		else
		{
			a = (get_node(head, n - 1))->elt;
			b = (get_node(head, n - 2))->elt;
			f = a + b;
			add_node(&head, f);
		}
	}

	return (head);
}

/**
 * add_node - adds a new node at the end of a t_cell list
 * @head: head
 * @n: n
 * Return: new end
 */

t_cell *add_node(t_cell **head, const int n)
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

/**
 * get_node - returns the nth node of a t_cell linked list
 * @head: head
 * @index: index
 * Return: node at index
 */

t_cell *get_node(t_cell *head, int index)
{
	t_cell *aux = head;
	int n = 0;

	while (n < index)
	{
		if (aux->next == NULL)
			return (NULL);
		aux = aux->next;
		n++;
	}
	return (aux);
}
