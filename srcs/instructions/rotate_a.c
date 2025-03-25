/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 06:46:25 by lomont            #+#    #+#             */
/*   Updated: 2025/03/25 04:25:04 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_node *stack_a, bool print)
{
	t_node *tmp_second;
	t_node *tmp_first;

	if (stack_a->first->next == NULL)
		exit(EXIT_FAILURE);
	tmp_first = stack_a->first;
	stack_a->first = stack_a->first->next;
	tmp_second = stack_a->first;
	while (stack_a->first->next != NULL)
		stack_a->first = stack_a->first->next;
	stack_a->first->next = tmp_first;
	stack_a->first->next->next = NULL;
	stack_a->first = tmp_second;
	if (!print)
		write(1, "ra\n", 3);
	return (stack_a);
}
