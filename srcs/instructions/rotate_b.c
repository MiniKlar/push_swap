/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 07:11:25 by lomont            #+#    #+#             */
/*   Updated: 2025/03/27 20:40:34 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_b(t_node **stack_b, bool print)
{
	t_node *tmp_second;
	t_node *tmp_first;

	tmp_first = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	tmp_second = (*stack_b);
	while ((*stack_b)->next != NULL)
		(*stack_b) = (*stack_b)->next;
	(*stack_b)->next = tmp_first;
	(*stack_b)->next->next = NULL;
	(*stack_b) = tmp_second;
	if (!print)
		write(1, "rb\n", 3);
}
