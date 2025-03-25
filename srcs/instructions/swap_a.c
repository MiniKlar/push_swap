/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 03:55:35 by lomont            #+#    #+#             */
/*   Updated: 2025/03/25 05:52:43 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_node *stack_a, bool print)
{
	t_node *tmp;

	if (stack_a == NULL || stack_a->next == NULL)
		return ;
	else
	{
		tmp = stack_a;
		stack_a = stack_a->next;
		tmp->next = stack_a->next;
		stack_a->next = tmp;
	}
	if (!print)
		write(1, "sa\n", 3);
}
