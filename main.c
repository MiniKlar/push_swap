#include "chain_list.h"

void note_addCount(list *liste);
void note_reduceCount(list *liste);

list	*initalisation()
{
	list *liste = malloc(sizeof(*liste));
	t_list *element = malloc(sizeof(*element));

	if (liste == NULL || element == NULL)
		exit(EXIT_FAILURE);
	element->nbr = 42;
	element->next = NULL;
	liste->first = element;
	liste->compteur = 0;
	note_addCount(liste);

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
	note_addCount(liste);
}
void insertion_middle(list *liste, t_list *node, int nvNombre)
{
	list *tmp;
	t_list *element = malloc(sizeof(*element));

	tmp = liste;
	if (tmp == NULL || node == NULL)
		exit(EXIT_FAILURE);
	while (tmp->first != node)
		tmp->first = tmp->first->next;
	element->nbr = nvNombre;
	element->next = tmp->first->next;
	node->next = element;
	note_addCount(liste);
}
void suppresion_middle(list *liste, t_list *deleteElement)
{
	t_list *tmp;

	if (liste == NULL || deleteElement == NULL)
		exit(EXIT_FAILURE);
	while (liste->first != deleteElement)
	{
		tmp = liste->first;
		liste->first = liste->first->next;
	}
	tmp->next = deleteElement->next;
	free(deleteElement);
	note_reduceCount(liste);
}

void suppresion(list *liste)
{
	t_list *tmp;

	if (liste == NULL)
		exit(EXIT_FAILURE);
	tmp = liste->first->next;
	free(liste->first);
	liste->first = tmp;
	note_reduceCount(liste);
}
void print_list(list *liste, t_list *tmp)
{
	if (liste == NULL)
		exit(EXIT_FAILURE);
	while (liste->first != NULL)
	{
		printf("%d -> ", liste->first->nbr);
		liste->first = liste->first->next;
	}
	printf("NULL\n");
	liste->first = tmp;
}
void free_list(list *liste)
{
	t_list *tmp;	
	
	if (liste == NULL)
		exit(EXIT_FAILURE);
	while (liste->first->next != NULL)
	{
		tmp = liste->first->next;
		free(liste->first);
		liste->first = tmp;
		note_reduceCount(liste);
	}
	free(liste->first);
	note_reduceCount(liste);
	free(liste);
}
void note_addCount(list *liste)
{
	liste->compteur += 1;
}

void note_reduceCount(list *liste)
{
	liste->compteur -= 1;
}

int main(void)
{
	list *first_list;
	t_list *tmp;
	size_t	i;

	first_list = initalisation();
	//printf("count premier : %d\n", first_list->compteur);
	i = 6;
	while (i <= 36)
	{
		insertion(first_list, i);
		i += 10;
	}
	tmp = first_list->first;
	print_list(first_list, tmp);
	insertion_middle(first_list, first_list->first->next->next, 2110);
	first_list->first = tmp;
	print_list(first_list, tmp);
	suppresion_middle(first_list, first_list->first->next->next->next);
	first_list->first = tmp;
	print_list(first_list, tmp);
	free_list(first_list);
	return (0);
}
