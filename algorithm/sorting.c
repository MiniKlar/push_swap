/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:25:02 by lomont            #+#    #+#             */
/*   Updated: 2025/02/02 14:39:34 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./LIB_C/LIB_C.h"
#include "push_swap.h"

void sort_3_stack(list *stack_a)
{
	int num1;
	int num2;
	int num3;

	if (!stack_a)
	{
		exit(EXIT_FAILURE);
	}
	num1 = stack_a->first->nbr;
	num2 = stack_a->first->next->nbr;
	num3 = stack_a->first->next->next->nbr;
	if (num1 > num2 && num2 > num3)
	{
		rotate_a(stack_a);
		swap_a(stack_a);
	}
	else if (num1 > num2 && num2 < num3 && num1 < num3)
		swap_a(stack_a);
	else if (num1 < num2 && num2 > num3 && num3 > num1)
	{
		reverse_rotate_a(stack_a);
		swap_a(stack_a);
	}
	else if (num1 > num2 && num2 < num3 && num3 < num1)
		rotate_a(stack_a);
	else if (num1 < num2 && num2 > num3 && num3 < num1)
		reverse_rotate_a(stack_a);
}
