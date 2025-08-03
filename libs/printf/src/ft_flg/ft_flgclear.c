/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flgclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:01:11 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 16:03:43 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

/*
** ft_flgclear - Free all nodes in a flag list
** @lst: Pointer to pointer to the first node of the list
**
** Iterates through the entire flag list, freeing each node's memory
** and setting the list pointer to NULL. Essential for preventing
** memory leaks after processing format specifiers. Safely handles
** NULL list pointers. Used to clean up flag lists after printing.
*/
void	ft_flgclear(t_flglst **lst)
{
	t_flglst	*temp;		/* Temporary pointer for safe traversal */

	if (!lst)			/* Handle NULL list pointer */
		return ;
	while (*lst)			/* Traverse and free all nodes */
	{
		temp = (*lst)-> next;	/* Save next node */
		free (*lst);		/* Free current node */
		*lst = temp;		/* Move to next node */
	}
}
