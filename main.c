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
}
void suppresion(list *liste)
{
	t_list *tmp;

	tmp = liste->first->next;
	free(liste->first);
	liste->first = tmp;
}
void print_list(list *liste)
{
	while (liste->first->next != NULL)
	{
		printf("%d\n", liste->first->nbr);
		liste->first = liste->first->next;
	}
	printf("%d\n", liste->first->nbr);
}
void free_list(list *liste)
{
	t_list *tmp;	
	
	while (liste->first->next != NULL)
	{
		tmp = liste->first->next;
		free(liste->first);
		liste->first = tmp;
	}
	free(liste->first);
	free(liste);
}

int main(void)
{
	list *first_list;
	t_list *tmp;
	size_t	i;

	first_list = initalisation();
	i = 6;
	while (i <= 36)
	{
		insertion(first_list, i);
		i += 10;
	}
	tmp = first_list->first;
	print_list(first_list);
	first_list->first = tmp;
	tmp = first_list->first->next;
	suppresion(first_list);
	first_list->first = tmp;
	print_list(first_list);
	first_list->first = tmp;
	free_list(first_list);
	return (0);
}
