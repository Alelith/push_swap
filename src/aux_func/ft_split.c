/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 23:15:38 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:22:25 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_split - Split string into array of substrings
**
** This file contains functions to split a string into an array of substrings
** based on a delimiter character. Used in push_swap to parse command line
** arguments that contain space-separated numbers.
*/

#include "push_swap.h"

/*
** ft_wordcount - Count words separated by delimiter
** @s: String to count words in
** @delimiter: Character that separates words
**
** Counts the number of words in the string, where words are sequences
** of characters separated by the delimiter character.
**
** Return: Number of words found in the string
*/
static int	ft_wordcount(char const *s, char delimiter)
{
	int	isdelimiter;	/* Flag to track if we're currently in a delimiter */
	int	wordcount;	/* Count of words found */

	isdelimiter = 1;
	wordcount = 0;
	while (s && *s)
	{
		if (*s == delimiter)
			isdelimiter = 1;			/* We're in a delimiter */
		else if (isdelimiter && *s != delimiter)
		{
			isdelimiter = 0;			/* Start of new word */
			wordcount++;
		}
		s++;
	}
	return (wordcount);
}

/*
** ft_fillarr - Fill result array with extracted substrings
** @result: Array to fill with substrings
** @str: Source string to extract from
** @wordcount: Number of words to extract
** @c: Delimiter character
**
** Extracts substrings from the source string and stores them in the result
** array. Each substring is created using ft_substr and represents one word.
*/
static void	ft_fillarr(char **result, const char *str, int wordcount, char c)
{
	int	i;		/* Index for result array */
	int	next;		/* Length of current word */

	i = 0;
	next = 0;
	while (wordcount-- && str && *str)
	{
		/* Find length of current word */
		while (str[next] != c && str[next])
			next++;
		
		/* Extract substring for current word */
		result[i] = ft_substr(str, 0, next);
		
		/* Move to start of next word */
		str += next + 1;
		while (*str == c)		/* Skip consecutive delimiters */
			str++;
		next = 0;
		i++;
	}
	result[i] = 0;			/* Null-terminate the array */
}

/*
** ft_split - Split string by delimiter into array of strings
** @s: String to split
** @c: Delimiter character
**
** Splits the string 's' using character 'c' as delimiter and returns
** an array of strings. The array is null-terminated and each substring
** is allocated separately.
**
** Return: Array of strings, or NULL if allocation fails
*/
char	**ft_split(char const *s, char c)
{
	int		wordcount;	/* Number of words in string */
	char	**result;	/* Array to store split strings */

	wordcount = ft_wordcount(s, c);		/* Count words first */
	result = malloc(sizeof(char *) * (wordcount + 1));	/* +1 for NULL terminator */
	if (!result)
		return (0);			/* Return NULL if allocation fails */
	ft_fillarr(result, s, wordcount, c);	/* Fill array with substrings */
	return (result);
}
