/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 03:37:21 by lomont            #+#    #+#             */
/*   Updated: 2025/01/30 19:04:43 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./LIB_C/LIB_C.h"
#include "chain_list.h"

bool check_numbers(int argc, char **argv);

int	main(int argc, char **argv)
{
	if (argc < 2)
		exit(EXIT_FAILURE);
	else if (!(check_numbers(argc, argv) == true))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_printf("\nPlus de 1 arguments, voici argc[%d]\n", argc);
		(void)argv;
	}
	ft_printf("\nCHECK_NUMBERS ok");
	return (0);
}
bool check_numbers(int argc, char **argv)
{
	int		i;
	long long		tpmp_baba;

	i = 1;
	if (*argv == NULL)
		return (false);
	while (i != argc)
	{
		if ((ft_atol(argv[i]) == 0 && !(ft_strncmp(argv[i], "0", 1) == 0)) || ((ft_atol(argv[i]) < INT_MIN) || (ft_atol(argv[i]) > (long)2147483647)))
			{
				return (false);
			}
		else
		{
			tpmp_baba = ft_atol(argv[i]);
			printf("%lld\n", tpmp_baba );
		}
		i++;
	}
	return (true);
}