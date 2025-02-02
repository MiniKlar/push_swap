/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 03:55:35 by lomont            #+#    #+#             */
/*   Updated: 2025/02/02 14:23:53 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../LIB_C/LIB_C.h"

void swap_a(list *stack_a)
{
	t_node *tmp;

	if (stack_a->first == NULL || stack_a->first->next == NULL)
		exit(EXIT_FAILURE);
	else
	{
		tmp = stack_a->first;
		stack_a->first = stack_a->first->next;
		tmp->next = stack_a->first->next;
		stack_a->first->next = tmp;
	}
	write(1, "sa\n", 3);
}