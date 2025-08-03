/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspecifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:56:05 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 16:03:37 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_isspecifier - Check if character is a printf format specifier
** @c: Character to test
**
** Tests whether the given character is a valid printf format specifier.
** Recognizes: d/i (decimal), u (unsigned), x/X (hex), o (octal),
** p (pointer), c (character), s (string), % (literal percent).
** Used to validate format strings and determine argument types.
** Returns 1 if valid specifier, 0 otherwise.
*/
int	ft_isspecifier(char c)
{
	return (c == 'd' || c == 'i' || c == 'u'		/* Integer formats */
		|| c == 'x' || c == 'X' || c == 'o'		/* Hex and octal */
		|| c == 'p' || c == 'c' || c == 's'		/* Pointer, char, string */
		|| c == '%');					/* Literal percent */
}
