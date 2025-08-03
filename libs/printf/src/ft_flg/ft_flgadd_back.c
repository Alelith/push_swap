/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flgadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 00:32:07 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 16:19:49 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_flgadd_back - Add a flag node to the end of the flag list
** @lst: Pointer to the flag list head pointer
** @new: New flag node to add
**
** Appends a new flag node to the end of the flag linked list.
** If the list is empty, the new node becomes the head.
** Otherwise, traverses to the last node and links the new node.
** Used during format string parsing to build the flag list.
*/
void	ft_flgadd_back(t_flglst **lst, t_flglst *new)
{
	t_flglst	*last;		/* Pointer to traverse to end */

	if (!*lst)			/* Empty list case */
	{
		*lst = new;		/* New node becomes head */
		return ;
	}
	last = *lst;
	while (last -> next)		/* Traverse to last node */
		last = last -> next;
	last -> next = new;		/* Link new node at end */
}
