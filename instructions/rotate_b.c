/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 07:11:25 by lomont            #+#    #+#             */
/*   Updated: 2025/01/31 07:16:26 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./LIB_C/LIB_C.h"
#include "push_swap.h"

list *rotate_b(list *stack_b)
{
	t_node *tmp_second;
	t_node *tmp_first;
	
	tmp_first = stack_b->first;
	stack_b->first = stack_b->first->next;
	tmp_second = stack_b->first;
	while (stack_b->first->next != NULL)
		stack_b->first = stack_b->first->next;
	stack_b->first->next = tmp_first;
	stack_b->first->next->next = NULL;
	stack_b->first = tmp_second;
	write(1, "rb\n", 3);
	return (stack_b);
}