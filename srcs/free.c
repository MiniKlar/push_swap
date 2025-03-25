/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 02:17:58 by lomont            #+#    #+#             */
/*   Updated: 2025/03/25 04:24:45 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node *stack)
{
	t_node *tmp;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	while (stack->next != NULL)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	free(stack);
}
