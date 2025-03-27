/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 01:15:51 by lomont            #+#    #+#             */
/*   Updated: 2025/03/27 21:41:21 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
	{
		ft_exit("Error\n");
		exit(EXIT_FAILURE);
	}
	else if (argc == 2)
		ft_split(argv[1], ' ');
	init_stack_a(&stack_a, argv + 1);
	if (!stack_sorted(&stack_a))
	{
		printf("TU ES ICI CHAKAL\n\n");
		if (stack_len(stack_a) == 2)
			swap_a(&stack_a, false);
		else if (stack_len(stack_a) == 3)
		{
			// printf("NBR STACK A = %d\n\n", stack_a->nbr);
			// printf("next->NBR STACK A = %d\n\n", stack_a->next->nbr);
			// printf("next->next->NBR STACK A = %d\n\n", stack_a->next->next->nbr);
			// printf("TU ES ICI CHAKAL\n\n");
			sort_three(&stack_a);
		}
		else
			sort_stacks(&stack_a, &stack_b);
	}
	free_stack(stack_b);
	printf("TU ES SORTI du main\n\n");
	exit(EXIT_SUCCESS);

// functions to handle errors && free;
// check OPERATIONS functions
// stack length function
// function to find last_node
// function to find min nbr and max nbr nodes

	// if (argc < 2)
	// 	exit(EXIT_FAILURE);
	// if (argv[1] == NULL || ft_strncmp(argv[1], "", 1) == 0)
	// {
	// 	ft_printf("TU EXIT ICI\n\n");
	// 	exit(EXIT_FAILURE);
	// }
	// else if (!(check_numbers(argc, argv)) == true)
	// 	ft_exit("Error\n");
	// else if (!(check_duplicate(argv)))
	// {
	// 	write(2, "Error\n", 6);
	// 	exit(EXIT_FAILURE);
	// }
	// //ft_printf("\nPlus de 1 arguments, voici argc[%d]\n", argc);
	// ft_printf("CHECK_NUMBERS & CHECK_DUPLICATE ok\n");
	// stack_a = fill_stack_a(argc, argv);
	// if (is_sorted(stack_a) == true)
	// {
	// 	ft_printf("LISTE TRIEE");
	// 	exit(EXIT_SUCCESS);
	// }
	// else
	// {
	// 	if (ft_lennbr(stack_a) == 2)
	// 	{
	// 		swap_a(stack_a);
	// 		printf("ON A SWAP A");
	// 	}
	// 	else if (ft_lennbr(stack_a) == 3)
	// 	{
	// 	}
	// 	else if (ft_lennbr(stack_a) > 3)
	// 	{
	// 		sort_algorithm(stack_a);
	// 	}
	// 	free(stack_a);
	// 	free(stack_b);
	// 	// il faut free les nodes puis la list
	// }















	// printf("|%d|\n", stack_a->first->nbr);
	// printf("stack a : | stack b :\n");
	// tmp = stack_a->first;
	// if (stack_a->first != NULL)
	// {
	// 	while (stack_a->first != NULL)
	// 	{
	// 		printf("|%d|\n", stack_a->first->nbr);
	// 		stack_a->first = stack_a->first->next;
	// 	}
	// }
	// else
	// {
	// 	printf("moins de 2 nombres dans la stack a");
	// 	exit(EXIT_FAILURE);
	// }
	//stack_a->first = tmp;
	//printf("a :|%d|\n", stack_a->first->nbr);
	// printf("-------------------------------\n");
	// while (stack_a->first != NULL)
	// {
	// 	printf("|%d|\n", stack_a->first->nbr);
	// 	stack_a->first = stack_a->first->next;
	// }
	// // while (stack_a->first != NULL && stack_b->first != NULL)
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
	// if (stack_a->first == NULL)
	// 	printf("stack a null");
	// else if (stack_b->first == NULL)
	// 	printf("stack_b null");
	// printf("\n");
	// return (0);
}
