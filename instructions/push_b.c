/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 05:19:09 by lomont            #+#    #+#             */
/*   Updated: 2025/02/02 07:30:02 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./LIB_C/LIB_C.h"
#include "push_swap.h"

list *push_b(list *stack_a, list *stack_b)
{
	t_node *tmp;
	if (!stack_a->first)
		return (NULL);
	else
	{
		if (stack_b == NULL)
		{
			stack_b = initalisation(stack_a->first->nbr);
			stack_a->first = stack_a->first->next;
		}
		else
		{
			tmp = stack_b->first;
			stack_b->first = stack_a->first;
			stack_a->first = stack_a->first->next;
			stack_b->first->next = tmp;
		}
	}
	write(1, "pb\n", 3);
	return (stack_b);
}