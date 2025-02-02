/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a_and_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 09:34:43 by lomont            #+#    #+#             */
/*   Updated: 2025/02/02 09:36:01 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./LIB_C/LIB_C.h"
#include "push_swap.h"

void reverse_rotate_a_and_b(list *stack_a, list *stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_a(stack_b);
	write(1, "rrr\n", 4);
}