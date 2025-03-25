/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 06:46:25 by lomont            #+#    #+#             */
/*   Updated: 2025/03/25 05:52:19 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_node *stack_a, bool print)
{
	t_node *tmp_second;
	t_node *tmp_first;

	if (stack_a->next == NULL)
		return ;
	tmp_first = stack_a;
	stack_a = stack_a->next;
	tmp_second = stack_a;
	while (stack_a->next != NULL)
		stack_a = stack_a->next;
	stack_a->next = tmp_first;
	stack_a->next->next = NULL;
	stack_a = tmp_second;
	if (!print)
		write(1, "ra\n", 3);
}
