/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:34:16 by acesteve          #+#    #+#             */
/*   Updated: 2025/07/16 09:55:36 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, unsigned long len)
{
	unsigned int	srclen;
	char			*result;

	srclen = ft_strlen(s);
	if (start > srclen)
		return (ft_strdup(""));
	if (len > srclen - start)
		len = srclen - start;
	result = malloc(len + 1);
	if (!result)
		return (0);
	ft_strlcpy(result, &s[start], len + 1);
	return (result);
}
