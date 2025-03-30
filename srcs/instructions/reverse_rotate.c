/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 09:33:04 by lomont            #+#    #+#             */
/*   Updated: 2025/03/30 01:51:32 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_node **stack)
{
	t_node	*end;
	t_node	*address_first;

	if ((*stack)->next == NULL)
		return ;
	address_first = (*stack);
	while ((*stack)->next->next != NULL)
		(*stack) = (*stack)->next;
	end = (*stack);
	(*stack)->next->next = address_first;
	(*stack) = (*stack)->next;
	end->next = NULL;
}

void	reverse_rotate_a(t_node **stack, bool print)
{
	reverse_rotate(stack);
	if (!print)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_node **stack, bool print)
{
	reverse_rotate(stack);
	if (!print)
		write(1, "rrb\n", 4);
}

void	reverse_rotate_a_and_b(t_node **stack_a, t_node **stack_b, bool print)
{
	reverse_rotate_a(stack_a, true);
	reverse_rotate_b(stack_b, true);
	if (!print)
		write(1, "rrr\n", 4);
}
