/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 09:33:04 by lomont            #+#    #+#             */
/*   Updated: 2025/02/02 11:17:51 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./LIB_C/LIB_C.h"
#include "push_swap.h"

list *reverse_rotate_b(list *stack_b)
{
	t_node 	*end;
	t_node 	*address_first;
	
	if (stack_b->first->next == NULL)
		exit(EXIT_FAILURE);
	address_first = stack_b->first;
	while (stack_b->first->next->next != NULL)
		stack_b->first = stack_b->first->next;
	end = stack_b->first;
	stack_b->first->next->next = address_first;
	stack_b->first = stack_b->first->next;
	end->next = NULL;
	write(1, "rrb\n", 4);
	return (stack_b);
}
