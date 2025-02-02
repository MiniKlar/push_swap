/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 05:19:11 by lomont            #+#    #+#             */
/*   Updated: 2025/02/02 08:25:33 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./LIB_C/LIB_C.h"
#include "push_swap.h"

list *push_a(list *stack_a, list *stack_b)
{
	t_node *tmp;
	if (!stack_b->first)
		return (NULL);
	else
	{
		if (!stack_a->first)
		{
			stack_a = initalisation(stack_b->first->nbr);
			stack_b->first = stack_b->first->next;
		}
		else
		{
			tmp = stack_a->first;
			stack_a->first = stack_b->first;
			stack_b->first = stack_b->first->next;
			stack_a->first->next = tmp;
		}
	}
	write(1, "pa\n", 3);
	return (stack_a);
}
