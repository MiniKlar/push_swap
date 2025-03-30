/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:25:02 by lomont            #+#    #+#             */
/*   Updated: 2025/03/30 04:11:15 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **stack_a)
{
	t_node	*biggest_node;

	biggest_node = find_max(*stack_a);
	if (biggest_node == *stack_a)
		rotate_a(stack_a, false);
	else if ((*stack_a)->next == biggest_node)
	{
		reverse_rotate_a(stack_a, false);
	}
	if ((*stack_a)->nbr > (*stack_a)->next->nbr)
		swap_a(stack_a, false);
}

void	move_a_to_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest_node;

	cheapest_node = get_cheapest(*stack_a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		reverse_rotate_both(stack_a, stack_b, cheapest_node);
	prep_for_push(stack_a, cheapest_node, 'a');
	prep_for_push(stack_b, cheapest_node->target_node, 'b');
	push_b(stack_a, stack_b, false);
}

void	move_b_to_a(t_node **stack_a, t_node **stack_b)
{
	prep_for_push(stack_a, (*stack_b)->target_node, 'a');
	push_a(stack_a, stack_b, false);
}

void	min_on_top(t_node **stack_a)
{
	while ((*stack_a)->nbr != find_min(*stack_a)->nbr)
	{
		if (find_min(*stack_a)->above_median)
			rotate_a(stack_a, false);
		else
			reverse_rotate_a(stack_a, false);
	}
}

void	sort_stacks(t_node **stack_a, t_node **stack_b)
{
	int	len_a;

	len_a = stack_len(*stack_a);
	if (len_a-- > 3 && !stack_sorted(*stack_a))
		push_b(stack_a, stack_b, false);
	if (len_a-- > 3 && !stack_sorted(*stack_a))
		push_b(stack_a, stack_b, false);
	while (len_a-- > 3 && !stack_sorted(*stack_a))
	{
		init_nodes_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		init_nodes_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	current_index(*stack_a);
	min_on_top(stack_a);
}
