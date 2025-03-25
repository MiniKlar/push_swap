/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 05:19:09 by lomont            #+#    #+#             */
/*   Updated: 2025/03/25 05:55:42 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_node *stack_a, t_node *stack_b, bool print)
{
	t_node *tmp;

	if (!stack_a)
		return ;
	else
	{
		if (stack_b == NULL)
		{
			append_node(&stack_b, stack_a->nbr);; ///???
			stack_a = stack_a->next;
		}
		else
		{
			tmp = stack_b;
			stack_b = stack_a;
			stack_a = stack_a->next;
			stack_b->next = tmp;
		}
	}
	if (!print)
		write(1, "pb\n", 3);
}
