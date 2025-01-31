#include "push_swap.h"
#include "../LIB_C/LIB_C.h"

int ft_str_only_digit(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && (!strchr(str, '-')))
			return (0);
		else
			i++;
	}
	return (1);
}
