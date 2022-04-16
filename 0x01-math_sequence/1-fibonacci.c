#include "fibonacci.h"
#include <math.h>

/**
 * Fibbonaci - fibonnaci sequence
 * Return: linked list
 */

t_cell *Fibonnaci()
{
	double f = 1, a = 0, b = 0;
	t_cell *head;

	head = NULL;
	add_node(&head, 1);

	while (f < 6180)
	{
		a = b;
		b = f;
		f = a + b;
		add_node(&head, f);
	}

	return (head);
}

/**
 * add_node - adds a new node at the beggining of a t_cell list
 * @head: head
 * @n: n
 * Return: new head
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

/**
 * gold_number - calculates gold number
 * @head: head
 * Return: gold number
 */

double gold_number(t_cell *head)
{
	t_cell *aux = head;
	double golden;
	double a = aux->elt, b = aux->next->elt;

	golden = a / b;
	return (golden);
}
