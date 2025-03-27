/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:28:09 by lomont            #+#    #+#             */
/*   Updated: 2025/03/27 21:50:20 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_node *stack)
{
	printf("\nNB == %d\n", stack->prev->nbr);
	if (!stack)
	{
		printf("TU ES SORTI DE LA FONCTION SORTED \n\n");
		exit(EXIT_FAILURE);
	}
	while ((stack)->next != NULL)
	{
		printf("\nNB == %d\n", stack->nbr);
		if ((stack)->nbr > (stack)->next->nbr)
		{
			printf("TU ES SORTI DE LA FONCTION SORTED 222 \n\n");
			return (false);
		}
		else
		{
			printf("TU ES dans le else\n\n");
			(stack) = (stack)->next;
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
	while(stack)
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

t_node	*find_max(t_node *stack)
{
	long	max;
	t_node	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while(stack)
	{
		if (stack->nbr > max)
		{
			max = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

void	rotate_both(t_node **stack_a, t_node **stack_b, t_node *cheapest_node)
{
	while (*stack_b != cheapest_node->target_node && *stack_a != cheapest_node)
		rotate_a_and_b(stack_a, stack_b, false);
	current_index(*stack_a);
	current_index(*stack_b);
}

void prep_for_push(t_node **stack, t_node *top_node, char stack_name)
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

