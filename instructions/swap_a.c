/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 03:55:35 by lomont            #+#    #+#             */
/*   Updated: 2025/01/31 05:08:28 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../LIB_C/LIB_C.h"

void swap_a(list *stack_a)
{
	t_node *tmp;
	t_node *tmp2;

	if (stack_a->first == NULL || stack_a->first->next == NULL)
		return ;
	else
	{
		tmp = stack_a->first;
		tmp2 = stack_a->first->next->next;
		stack_a->first = stack_a->first->next;
		stack_a->first->next = tmp;
		stack_a->first->next->next = tmp2;
	}
	write(1, "sa\n", 3);
}