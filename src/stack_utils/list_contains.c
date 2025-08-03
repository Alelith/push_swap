/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_contains.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:40:24 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:43:13 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** list_contains - Check if the list contains a specific value
** @self: Pointer to the list structure to search
** @num: Integer value to search for
**
** Performs a linear search through the list to find if the specified
** value exists. This is particularly useful during the LIS phase of
** the sorting algorithm to determine if an element should be kept
** in stack A or moved to stack B.
**
** Return: 1 if the value is found, 0 if not found
*/
int	list_contains(t_list *self, int num)
{
	int	i;		/* Loop counter */

	i = 0;
	while (i < self -> length)			/* Search through all elements */
	{
		if (num == self -> get(self, i))	/* Found the value */
			return (1);
		i++;
	}
	return (0);					/* Value not found */
}
