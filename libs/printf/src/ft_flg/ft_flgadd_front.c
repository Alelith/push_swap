/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flgadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 00:29:41 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 16:19:59 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_flgadd_front - Add a flag node to the front of the flag list
** @lst: Pointer to the flag list head pointer
** @new: New flag node to add
**
** Prepends a new flag node to the beginning of the flag linked list.
** The new node becomes the new head of the list. Handles null pointer
** safety checks. Used when flags need to be processed in reverse order
** or when building the flag list from front to back.
*/
void	ft_flgadd_front(t_flglst **lst, t_flglst *new)
{
	if (!lst || !new)		/* Safety check for null pointers */
		return ;
	new -> next = *lst;		/* Link new node to current head */
	*lst = new;			/* Update head to new node */
}
