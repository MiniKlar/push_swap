/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a_and_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 07:13:23 by lomont            #+#    #+#             */
/*   Updated: 2025/03/27 20:42:49 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_and_b(t_node **stack_a, t_node **stack_b, bool print)
{
	rotate_a(stack_a, true);
	rotate_b(stack_b, true);
	if (!print)
		write(1, "rr\n", 3);
}
