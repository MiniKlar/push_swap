/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a_and_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 09:34:43 by lomont            #+#    #+#             */
/*   Updated: 2025/03/25 04:24:56 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a_and_b(t_node *stack_a, t_node *stack_b, bool print)
{
	reverse_rotate_a(stack_a, true);
	reverse_rotate_a(stack_b, true);
	if (!print)
		write(1, "rrr\n", 4);
}
