/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 03:55:41 by lomont            #+#    #+#             */
/*   Updated: 2025/03/30 05:19:20 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_nodes_b(t_node *stack_a, t_node *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_b(stack_a, stack_b);
}

void	set_target_b(t_node *stack_a, t_node *stack_b)
{
	t_node	*current_a;
	t_node	*target_node;
	long	best_match_index;

	while (stack_b)
	{
		best_match_index = LONG_MAX;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->nbr > stack_b->nbr && current_a->nbr
				< best_match_index)
			{
				best_match_index = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			stack_b->target_node = find_min(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

bool	check_char(char *argv)
{
	int	i;

	i = 0;
	if (!(argv[i] == '+') || !(argv[i] == '-') || !(ft_isdigit(argv[i])))
		return (false);
	while (argv[i])
	{
		if ((ft_isdigit(argv[i]) == 0))
			return (false);
		i++;
	}
	return (true);
}
