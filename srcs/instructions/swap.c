/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 03:55:35 by lomont            #+#    #+#             */
/*   Updated: 2025/03/30 03:11:52 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node **stack)
{
	t_node	*tmp;
	t_node	*tmp2;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	else
	{
		tmp = (*stack);
		tmp2 = (*stack)->next->next;
		(*stack) = (*stack)->next;
		tmp->next = (*stack)->next;
		(*stack)->next = tmp;
		(*stack)->next->next = tmp2;
	}
}

void	swap_a(t_node **stack, bool print)
{
	swap(stack);
	if (!print)
		write(1, "sa\n", 3);
}

void	swap_b(t_node **stack, bool print)
{
	swap(stack);
	if (!print)
		write(1, "sb\n", 3);
}

void	swap_a_and_b(t_node **stack_a, t_node **stack_b, bool print)
{
	swap(stack_a);
	swap(stack_b);
	if (!print)
		write(1, "ss\n", 3);
}
