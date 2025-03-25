/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 03:55:35 by lomont            #+#    #+#             */
/*   Updated: 2025/03/25 04:25:10 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_node *stack_a, bool print)
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
	if (!print)
		write(1, "sa\n", 3);
}
