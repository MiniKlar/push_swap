/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 02:38:46 by lomont            #+#    #+#             */
/*   Updated: 2025/01/31 04:14:08 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./LIB_C/LIB_C.h"
#include "push_swap.h"

list *fill_stack_a(int argc, char **argv)
{
	list 	*first_p;
	int 	i;

	i = 1;
	first_p = initalisation(ft_atol(argv[argc - i]));
	//printf("\n premiere node cree : %d", first_p->first->nbr);
	i++;
	while (argc - i != 0)
	{
		insertion(first_p, ft_atol(argv[argc - i]));
		i++;
	}
	return (first_p);
}
list *fill_stack_b(void)
{
	list 	*first_p;
	first_p = initalisation(0);
	printf("\n premiere node cree : %d", first_p->first->nbr);
	return (first_p);
}