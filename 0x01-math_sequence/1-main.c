#include <stdio.h>
#include "fibonacci.h"

void print_list(t_cell *head)
{
	if (head == NULL)
		return;
	print_list(head->next);
	printf("%d ", head->elt);
}

int main()
{
	t_cell *head;

	head = Fibonnaci();
	print_list(head);
	printf("\n");
	return (0);
}
