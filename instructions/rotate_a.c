/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 06:46:25 by lomont            #+#    #+#             */
/*   Updated: 2025/01/31 07:16:15 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./LIB_C/LIB_C.h"
#include "push_swap.h"

list *rotate_a(list *stack_a)
{
	t_node *tmp_second;
	t_node *tmp_first;
	
	tmp_first = stack_a->first;
	stack_a->first = stack_a->first->next;
	tmp_second = stack_a->first;
	while (stack_a->first->next != NULL)
		stack_a->first = stack_a->first->next;
	stack_a->first->next = tmp_first;
	stack_a->first->next->next = NULL;
	stack_a->first = tmp_second;
	write(1, "ra\n", 3);
	return (stack_a);
}
