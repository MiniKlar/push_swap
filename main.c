#include "chain_list.h"

list	*initalisation()
{
	list *liste = malloc(sizeof(*liste));
	t_list *element = malloc(sizeof(*element));

	if (liste == NULL || element == NULL)
		exit(EXIT_FAILURE);
	element->nbr = 42;
	element->next = NULL;
	liste->first = element;

	return (liste);
}
void insertion(list *liste, int nvNombre)
{
	t_list *element = malloc(sizeof(*element));

	if (element == NULL)
		exit(EXIT_FAILURE);
	element->nbr = nvNombre;
	element->next = liste->first;
	liste->first = element;

	return (liste);
}

int main(void)
{
	list *first_list;

	first_list = initalisation();
	printf("%d\n", first_list->first->nbr);
	free(first_list->first);
	free(first_list);
	return (0);
}
