/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 01:15:51 by lomont            #+#    #+#             */
/*   Updated: 2025/01/31 05:10:11 by lomont           ###   ########.fr       */
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
	while (stack_a->first != NULL)
	{
		printf("|%d|\n", stack_a->first->nbr);
		stack_a->first = stack_a->first->next;
	}
	//printf("\n");
	stack_a->first = tmp;
	swap_a(stack_a);
	printf("-------------------------------\n");
	while (stack_a->first != NULL)
	{
		printf("|%d|\n", stack_a->first->nbr);
		stack_a->first = stack_a->first->next;
	}
	//printf("\n");
	return (0);
}
