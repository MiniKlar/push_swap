/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 01:15:51 by lomont            #+#    #+#             */
/*   Updated: 2025/03/30 05:11:36 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**list;

	stack_a = NULL;
	stack_b = NULL;
	list = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
	{
		ft_exit("Error\n");
		exit(EXIT_FAILURE);
	}
	else if (argc == 2)
	{
		list = ft_split(argv[1], ' ');
		init_stack_a(&stack_a, list, true);
	}
	else
		init_stack_a(&stack_a, argv + 1, false);
	push_swap(stack_a, stack_b);
	if (list != NULL)
		free_tab(list);
	exit(EXIT_SUCCESS);
}
