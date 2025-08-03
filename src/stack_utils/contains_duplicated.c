/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contains_duplicated.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 19:44:22 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:43:10 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** contains_duplicated - Check if the list contains any duplicate values
** @self: Pointer to the list structure to check
**
** Performs a nested loop comparison to detect duplicate values in the list.
** For each element, it compares it with all subsequent elements to find
** any duplicates. This validation is essential for push_swap as duplicate
** values would make sorting impossible or undefined.
**
** Return: 1 if duplicates are found, 0 if all values are unique
*/
int	contains_duplicated(t_list *self)
{
	int	i;		/* Outer loop index */
	int	j;		/* Inner loop index */
	int	temp;		/* Current element value to compare */

	i = 0;
	while (i < self -> length)
	{
		j = i + 1;				/* Start comparing from next element */
		temp = self -> get(self, i);		/* Get current element value */
		while (j < self -> length)
		{
			if (temp == self -> get(self, j))	/* Found duplicate */
				return (1);
			j++;
		}
		i++;
	}
	return (0);					/* No duplicates found */
}
