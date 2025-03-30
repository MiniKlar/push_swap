/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 06:46:25 by lomont            #+#    #+#             */
/*   Updated: 2025/03/30 01:52:16 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*tmp_second;
	t_node	*tmp_first;

	if ((*stack)->next == NULL)
		return ;
	tmp_first = (*stack);
	(*stack) = (*stack)->next;
	tmp_second = (*stack);
	while ((*stack)->next != NULL)
		(*stack) = (*stack)->next;
	(*stack)->next = tmp_first;
	(*stack)->next->next = NULL;
	(*stack) = tmp_second;
}

void	rotate_a(t_node **stack, bool print)
{
	rotate(stack);
	if (!print)
		write(1, "ra\n", 3);
}

void	rotate_b(t_node **stack, bool print)
{
	rotate(stack);
	if (!print)
		write(1, "rb\n", 3);
}

void	rotate_a_and_b(t_node **stack_a, t_node **stack_b, bool print)
{
	rotate_a(stack_a, true);
	rotate_b(stack_b, true);
	if (!print)
		write(1, "rr\n", 3);
}
