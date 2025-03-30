/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:28:09 by lomont            #+#    #+#             */
/*   Updated: 2025/03/30 01:49:35 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_node *stack)
{
	if (!stack)
	{
		return (1);
	}
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
		{
			return (false);
		}
		else
		{
			stack = stack->next;
		}
	}
	return (true);
}

t_node	*find_min(t_node *stack)
{
	long	min;
	t_node	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

void	rotate_both(t_node **stack_a, t_node **stack_b, t_node *cheapest_node)
{
	while (*stack_b != cheapest_node->target_node && *stack_a != cheapest_node)
		rotate_a_and_b(stack_a, stack_b, false);
	current_index(*stack_a);
	current_index(*stack_b);
}

void	reverse_rotate_both(t_node **stack_a, t_node **stack_b,
		t_node *cheapest_node)
{
	while (*stack_b != cheapest_node->target_node && *stack_a != cheapest_node)
		reverse_rotate_a_and_b(stack_a, stack_b, false);
	current_index(*stack_a);
	current_index(*stack_b);
}

void	prep_for_push(t_node **stack, t_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				rotate_a(stack, false);
			else
				reverse_rotate_a(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rotate_b(stack, false);
			else
				reverse_rotate_b(stack, false);
		}
	}
}
