/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flgnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 00:21:58 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 16:03:40 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

/*
** ft_flgnew - Create a new flag list node
** @type: Type of flag (from t_flgtype enum)
** @value: Associated numeric value (width, precision, etc.)
**
** Allocates and initializes a new flag list node with the specified
** type and value. The node's next pointer is set to NULL. Used to
** build linked lists of formatting flags during format string parsing.
** Returns pointer to new node, or NULL if allocation fails.
*/
t_flglst	*ft_flgnew(t_flgtype type, int value)
{
	t_flglst	*result;	/* New flag node */

	result = malloc(sizeof(t_flglst));	/* Allocate memory */
	if (!result)
		return (NULL);			/* Handle allocation failure */
	result -> type = type;			/* Set flag type */
	result -> value = value;		/* Set associated value */
	result -> next = NULL;			/* Initialize next pointer */
	return (result);
}
