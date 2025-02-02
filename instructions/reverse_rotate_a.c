/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 08:45:38 by lomont            #+#    #+#             */
/*   Updated: 2025/02/02 11:13:28 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./LIB_C/LIB_C.h"
#include "push_swap.h"

list *reverse_rotate_a(list *stack_a)
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
	write(1, "rra\n", 4);
	return (stack_a);
}