/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 23:15:38 by acesteve          #+#    #+#             */
/*   Updated: 2025/07/19 18:23:03 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_wordcount(char const *s, char delimiter)
{
	int	isdelimiter;
	int	wordcount;

	isdelimiter = 1;
	wordcount = 0;
	while (s && *s)
	{
		if (*s == delimiter)
			isdelimiter = 1;
		else if (isdelimiter && *s != delimiter)
		{
			isdelimiter = 0;
			wordcount++;
		}
		s++;
	}
	return (wordcount);
}

static void	ft_fillarr(char **result, const char *str, int wordcount, char c)
{
	int	i;
	int	next;

	i = 0;
	next = 0;
	while (wordcount-- && str && *str)
	{
		while (str[next] != c && str[next])
			next++;
		result[i] = ft_substr(str, 0, next);
		str += next + 1;
		while (*str == c)
			str++;
		next = 0;
		i++;
	}
	result[i] = 0;
}

char	**ft_split(char const *s, char c)
{
	int		wordcount;
	char	**result;

	wordcount = ft_wordcount(s, c);
	result = malloc(sizeof(char *) * (wordcount + 1));
	if (!result)
		return (0);
	ft_fillarr(result, s, wordcount, c);
	return (result);
}
