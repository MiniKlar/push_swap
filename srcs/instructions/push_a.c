/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 05:19:11 by lomont            #+#    #+#             */
/*   Updated: 2025/03/25 04:24:52 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_node *stack_a, t_node *stack_b, bool print)
{
	t_node *tmp;
	if (!stack_b)
		return (NULL);
	else
	{
		if (!stack_a)
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
	if (!print)
		write(1, "pa\n", 3);
	return (stack_a);
}
