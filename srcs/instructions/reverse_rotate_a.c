/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 08:45:38 by lomont            #+#    #+#             */
/*   Updated: 2025/03/25 04:24:58 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_node *stack_a, bool print)
{
	t_node 	*end;
	t_node 	*address_first;

	if (stack_a->first->next == NULL)
		exit(EXIT_FAILURE);
	address_first = stack_a->first;
	while (stack_a->first->next->next != NULL)
		stack_a->first = stack_a->first->next;
	end = stack_a->first;
	stack_a->first->next->next = address_first;
	stack_a->first = stack_a->first->next;
	end->next = NULL;
	if (!print)
		write(1, "rra\n", 4);
}
