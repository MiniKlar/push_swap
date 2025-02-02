/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 04:59:14 by lomont            #+#    #+#             */
/*   Updated: 2025/02/02 12:31:01 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../LIB_C/LIB_C.h"

void swap_b(list *stack_b)
{
	t_node *tmp;
	t_node *tmp2;

	if (stack_b->first == NULL || stack_b->first->next == NULL)
		return ;
	else
	{
		tmp = stack_b->first;
		tmp2 = stack_b->first->next->next;
		stack_b->first = stack_b->first->next;
		stack_b->first->next = tmp;
		stack_b->first->next->next = tmp2;
	}
	write(1, "sb\n", 3);
}