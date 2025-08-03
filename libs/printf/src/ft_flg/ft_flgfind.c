/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flgfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 00:11:44 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 16:20:08 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_flgfind - Find a specific flag type in the flag list
** @lst: Flag list to search
** @type: Type of flag to find
**
** Searches through the flag linked list for a node with the specified
** flag type. Used to check if specific formatting flags are present
** (like zero-padding, left-alignment, etc.) during output formatting.
** Returns pointer to the flag node if found, NULL otherwise.
*/
t_flglst	*ft_flgfind(t_flglst *lst, t_flgtype type)
{
	while (lst)				/* Traverse the flag list */
	{
		if (lst -> type == type)	/* Check for matching flag type */
			return (lst);		/* Return found flag node */
		lst = lst -> next;		/* Move to next node */
	}
	return (NULL);				/* Flag type not found */
}
