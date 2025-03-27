/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 09:33:04 by lomont            #+#    #+#             */
/*   Updated: 2025/03/27 20:36:51 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_b(t_node **stack_b, bool print)
{
	t_node 	*end;
	t_node 	*address_first;

	if ((*stack_b)->next == NULL)
		return ;
	address_first = (*stack_b);
	while ((*stack_b)->next->next != NULL)
		(*stack_b) = (*stack_b)->next;
	end = (*stack_b);
	(*stack_b)->next->next = address_first;
	(*stack_b) = (*stack_b)->next;
	end->next = NULL;
	if (!print)
		write(1, "rrb\n", 4);
}
