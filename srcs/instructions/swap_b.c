/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 04:59:14 by lomont            #+#    #+#             */
/*   Updated: 2025/03/27 20:35:13 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_node **stack_b, bool print)
{
	t_node *tmp;
	t_node *tmp2;

	if ((*stack_b) == NULL || (*stack_b)->next == NULL)
		return ;
	else
	{
		tmp = (*stack_b);
		tmp2 = (*stack_b)->next->next;
		(*stack_b) = (*stack_b)->next;
		(*stack_b)->next = tmp;
		(*stack_b)->next->next = tmp2;
	}
	if (!print)
		write(1, "sb\n", 3);
}
