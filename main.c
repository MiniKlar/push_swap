/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 01:15:51 by lomont            #+#    #+#             */
/*   Updated: 2025/02/02 14:11:12 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./LIB_C/LIB_C.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	list *stack_a;
	list *stack_b;
	t_node *tmp;
	
	if (argc < 2)
		exit(EXIT_FAILURE);
	else if (!(check_numbers(argc, argv)) == true)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	else if (!(check_duplicate(argv)))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	else
	{
		//ft_printf("\nPlus de 1 arguments, voici argc[%d]\n", argc);
		(void)argv;
	}
	ft_printf("CHECK_NUMBERS & CHECK_DUPLICATE ok\n");
	stack_a = fill_stack_a(argc, argv);
	(void)stack_b;
	printf("stack a : | stack b :\n");
	tmp = stack_a->first;
	if (stack_a->first->next != NULL)
	{
		while (stack_a->first != NULL)
		{
			printf("|%d|\n", stack_a->first->nbr);
			stack_a->first = stack_a->first->next;
		}
	}
	else
	{
		printf("moins de 2 nombres dans la stack a");
		exit(EXIT_FAILURE);
	}
	stack_b = NULL;
	stack_a->first = tmp;
	//stack_b = push_b(stack_a, stack_b);
	sort_3_stack(stack_a);
	//printf("a :|%d|\n", stack_a->first->nbr);
	printf("-------------------------------\n");
	while (stack_a->first != NULL)
	{
		printf("|%d|\n", stack_a->first->nbr);
		stack_a->first = stack_a->first->next;
	}
	// while (stack_a->first != NULL && stack_b->first != NULL)
	// {
	// 	if (stack_b->first == NULL)
	// 	{
	// 		printf("a |%d   &      |\n", stack_a->first->nbr);
	// 		stack_a->first = stack_a->first->next;
	// 	}
	// 	else
	// 	{
	// 		printf("|%d   &   %d|\n", stack_a->first->nbr, stack_b->first->nbr);
	// 		stack_a->first = stack_a->first->next;
	// 		stack_b->first = stack_b->first->next;
	// 	}
	// }
	if (stack_a->first == NULL)
		printf("stack a null");
	else if (stack_b->first == NULL)
		printf("stack_b null");
	printf("\n");
	return (0);
}
