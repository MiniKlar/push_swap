/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 08:45:38 by lomont            #+#    #+#             */
/*   Updated: 2025/03/27 20:22:46 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_node **stack_a, bool print)
{
	t_node 	*end;
	t_node 	*address_first;

	if ((*stack_a)->next == NULL)
		;
	address_first = (*stack_a);
	while ((*stack_a)->next->next != NULL)
		(*stack_a) = (*stack_a)->next;
	end = (*stack_a);
	(*stack_a)->next->next = address_first;
	(*stack_a) = (*stack_a)->next;
	end->next = NULL;
	if (!print)
		write(1, "rra\n", 4);
}
