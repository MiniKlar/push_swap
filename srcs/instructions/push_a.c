/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 05:19:11 by lomont            #+#    #+#             */
/*   Updated: 2025/03/25 06:23:57 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_node *stack_a, t_node *stack_b, bool print)
{
	t_node *tmp;

	if (!stack_b)
		return ;
	else
	{
		if (!stack_a)
		{
			append_node(&stack_a, stack_b->nbr); //???
			stack_b = stack_b->next;
		}
		else
		{
			tmp = stack_a;
			stack_a = stack_b;
			stack_b = stack_b->next;
			stack_a->next = tmp;
		}
	}
	if (!print)
		write(1, "pa\n", 3);
}
