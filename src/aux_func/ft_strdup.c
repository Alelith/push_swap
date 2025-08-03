/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:55:14 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 16:04:42 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** ft_strdup - Create a duplicate copy of a string
** @s: Source string to duplicate
**
** Allocates memory and creates an exact copy of the input string.
** Used during argument processing to create independent copies of
** command line arguments for safe manipulation. Essential for string
** processing operations where the original must be preserved.
** Returns pointer to new string, or NULL if allocation fails.
*/
char	*ft_strdup(const char *s)
{
	char			*result;	/* New string copy */
	unsigned long	len;		/* Length of source string */
	unsigned long	i;		/* Loop counter */

	if (!s)					/* Handle NULL input */
		return (NULL);
	len = ft_strlen(s);			/* Get source length */
	result = callocation(len + 1, sizeof(char));	/* Allocate memory */
	if (!result)				/* Handle allocation failure */
		return (NULL);
	i = 0;
	while (i < len)				/* Copy characters */
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';			/* Null terminate */
	return (result);
}

#include "push_swap.h"

/*
** ft_strdup - Duplicate a string
** @s: String to duplicate
**
** Creates a copy of the string 's' by allocating sufficient memory
** and copying all characters including the null terminator.
**
** Return: Pointer to the duplicated string, or NULL if allocation fails
*/
char	*ft_strdup(const char *s)
{
	char	*result;	/* Pointer to newly allocated string */

	result = malloc(ft_strlen(s) + 1);	/* Allocate memory (+1 for null terminator) */
	if (!result)
		return (0);			/* Return NULL if allocation fails */
	ft_strlcpy(result, s, ft_strlen(s) + 1);	/* Copy string with null terminator */
	return (result);
}
