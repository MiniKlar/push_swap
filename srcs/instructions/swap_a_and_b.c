/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a_and_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 05:10:57 by lomont            #+#    #+#             */
/*   Updated: 2025/03/25 04:25:08 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a_and_b(t_node *stack_a, t_node *stack_b, bool print)
{
	swap_a(stack_a, true);
	swap_b(stack_b, true);
	if (!print)
		write(1, "ss\n", 3);
}
