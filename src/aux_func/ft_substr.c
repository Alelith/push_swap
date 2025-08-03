/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:34:16 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:22:29 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** ft_substr - Extract substring from string
** @s: Source string to extract from
** @start: Starting index for extraction
** @len: Maximum length of substring to extract
**
** Allocates and returns a substring from string 's'. The substring
** begins at index 'start' and is of maximum size 'len'. Handles
** bounds checking to prevent reading beyond the source string.
**
** Return: Pointer to the extracted substring, or NULL if allocation fails
*/
char	*ft_substr(char const *s, unsigned int start, unsigned long len)
{
	unsigned int	srclen;		/* Length of source string */
	char			*result;	/* Pointer to result substring */

	srclen = ft_strlen(s);
	
	/* If start is beyond string length, return empty string */
	if (start > srclen)
		return (ft_strdup(""));
	
	/* Adjust len if it would read beyond end of string */
	if (len > srclen - start)
		len = srclen - start;
	
	result = malloc(len + 1);	/* Allocate memory for substring (+1 for null) */
	if (!result)
		return (0);		/* Return NULL if allocation fails */
	
	ft_strlcpy(result, &s[start], len + 1);	/* Copy substring */
	return (result);
}
