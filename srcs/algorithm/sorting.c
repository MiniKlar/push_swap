/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:25:02 by lomont            #+#    #+#             */
/*   Updated: 2025/03/27 21:50:22 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_node **stack_a)
{
	t_node *biggest_node;

	biggest_node = find_max(*stack_a);
	printf("BIGGEST NODE = %d\n\n", biggest_node->nbr);
	if (biggest_node == *stack_a)
		rotate_a(stack_a, false);
	else if ((*stack_a)->next == biggest_node)
		reverse_rotate_a(stack_a, false);
	printf("NBR STACK A = %d\n\n", (*stack_a)->nbr);
	printf("NBR STACK A = %d\n\n", (*stack_a)->next->nbr);
	printf("NBR STACK A = %d\n\n", (*stack_a)->next->next->nbr);
	if ((*stack_a)->nbr > (*stack_a)->next->nbr)
		swap_a(stack_a, false);
	printf("NBR STACK A = %d\n\n", (*stack_a)->nbr);
	printf("NBR STACK A = %d\n\n", (*stack_a)->next->nbr);
	printf("NBR STACK A = %d\n\n", (*stack_a)->next->next->nbr);
}

void move_a_to_b(t_node **stack_a, t_node **stack_b)
{
	t_node *cheapest_node;

	cheapest_node = get_cheapest(*stack_a); //or get_cheapest
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_a_and_b(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median))
		reverse_rotate_a_and_b(stack_a, stack_b, cheapest_node);
	prep_for_push(stack_a, cheapest_node, 'a');
	prep_for_push(stack_b, cheapest_node->target_node, 'b');
	push_b(*stack_a, *stack_b, false);
}

void	move_b_to_a(t_node **stack_a, t_node **stack_b)
{
	prep_for_push(stack_a, (*stack_b)->target_node, 'a');
	push_a(*stack_a, *stack_b, false);
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
		push_b(*stack_a, *stack_b, false);
	if (len_a-- > 3 && !stack_sorted(*stack_a))
		push_b(*stack_a, *stack_b, false);
	printf("NBR B%d\n\n",(*stack_b)->nbr);
	printf("NBR B%d\n\n",(*stack_b)->next->nbr);
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


// void sort_3_stack(list *stack_a)
// {
// 	int num1;
// 	int num2;
// 	int num3;

// 	if (!stack_a)
// 	{
// 		exit(EXIT_FAILURE);
// 	}
// 	num1 = stack_a->first->nbr;
// 	printf("%d\n\n", num1);
// 	num2 = stack_a->first->next->nbr;
// 	num3 = stack_a->first->next->next->nbr;
// 	if (num1 > num2 && num2 > num3)
// 	{
// 		rotate_a(stack_a);
// 		swap_a(stack_a);
// 	}
// 	else if (num1 > num2 && num2 < num3 && num1 < num3)
// 		swap_a(stack_a);
// 	else if (num1 < num2 && num2 > num3 && num3 > num1)
// 	{
// 		reverse_rotate_a(stack_a);
// 		swap_a(stack_a);
// 	}
// 	else if (num1 > num2 && num2 < num3 && num3 < num1)
// 		rotate_a(stack_a);
// 	else if (num1 < num2 && num2 > num3 && num3 < num1)
// 		reverse_rotate_a(stack_a);
// }
