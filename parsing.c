/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 03:37:21 by lomont            #+#    #+#             */
/*   Updated: 2025/03/30 05:23:48 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_numbers(char *argv)
{
	if (!argv)
		return (false);
	if ((ft_atol(argv) == 0 && !(ft_strncmp(argv, "0", 1) == 0))
		|| ((ft_atol(argv) < INT_MIN) || (ft_atol(argv) > INT_MAX)))
		return (false);
	else if (!(ft_str_only_digit(argv)))
		return (false);
	else
		return (true);
}

bool	check_duplicate(t_node *stack_a, int n)
{
	if (!stack_a)
		return (true);
	while (stack_a)
	{
		if (stack_a->nbr == n)
			return (false);
		stack_a = stack_a->next;
	}
	return (true);
}

void	push_swap(t_node *stack_a, t_node *stack_b)
{
	if (!stack_sorted(stack_a))
	{
		if (stack_len(stack_a) == 2)
			swap_a(&stack_a, false);
		else if (stack_len(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort_stacks(&stack_a, &stack_b);
	}
	free_stack(stack_a);
}

void	init_stack_a(t_node **stack_a, char **argv, bool list)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (check_numbers(argv[i]) == false)
			free_errors(*stack_a, argv, list);
		n = ft_atol(argv[i]);
		if (check_duplicate(*stack_a, (int)n) == false)
			free_errors(*stack_a, argv, list);
		append_node(stack_a, n);
		i++;
	}
}

void	append_node(t_node **stack, int n)
{
	t_node	*node;
	t_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(*node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	node->cheapest = 0;
	if (!(*stack))
	{
		(*stack) = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}
