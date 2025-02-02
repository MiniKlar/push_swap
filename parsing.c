/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 03:37:21 by lomont            #+#    #+#             */
/*   Updated: 2025/02/02 05:17:19 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./LIB_C/LIB_C.h"
#include "push_swap.h"

bool check_numbers(int argc, char **argv)
{
	int		i;

	i = 1;
	if (*argv == NULL)
		return (false);
	while (i != argc)
	{
		if ((ft_atol(argv[i]) == 0 && !(ft_strncmp(argv[i], "0", 1) == 0)) || ((ft_atol(argv[i]) < INT_MIN) || (ft_atol(argv[i]) > INT_MAX)))
			return (false);
		else if (!ft_str_only_digit(argv[i]))
			return (false);
		i++;
	}
	return (true);
}
bool check_duplicate(char **argv)
{
	int i;
	int k;

	i = 1;
	k = i + 1;
	while(argv[i])
	{
		k = i + 1;
		while (argv[k])
		{
			if (ft_atol(argv[i]) != ft_atol(argv[k]))
				k++;
			else
				return (false);
		}
		i++;
	}
	return (true);
}
