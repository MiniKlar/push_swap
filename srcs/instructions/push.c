/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 05:19:11 by lomont            #+#    #+#             */
/*   Updated: 2025/03/30 04:28:14 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **dest, t_node **src)
{
	t_node	*tmp;

	if (!(*src))
		return ;
	else
	{
		if (!(*dest))
		{
			tmp = (*src);
			append_node(dest, (*src)->nbr);
			(*src) = (*src)->next;
			free(tmp);
		}
		else
		{
			tmp = (*dest);
			(*dest) = (*src);
			(*src) = (*src)->next;
			(*dest)->next = tmp;
		}
	}
}

void	push_a(t_node **stack_a, t_node **stack_b, bool print)
{
	push(stack_a, stack_b);
	if (!print)
		write(1, "pa\n", 3);
}

void	push_b(t_node **stack_a, t_node **stack_b, bool print)
{
	push(stack_b, stack_a);
	if (!print)
		write(1, "pb\n", 3);
}
