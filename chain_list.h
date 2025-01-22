#include <stdio.h>
#include <stdlib.h>

#ifndef CHAIN_LIST_H
#define CHAIN_LIST_H

typedef struct	s_list
{
	int 			nbr;
	struct s_list	*next;
}				t_list;

typedef struct	List
{
	t_list *first;
}				list;
#endif