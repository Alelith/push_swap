/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 23:56:38 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 16:03:30 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_isflag - Check if character is a printf format flag
** @c: Character to test
**
** Tests whether the given character is a valid printf format flag.
** Recognizes: space ( ), hash (#), plus (+), minus (-), asterisk (*),
** and zero (0). Used during format string parsing to identify and
** process formatting modifiers. Returns 1 if flag, 0 otherwise.
*/
int	ft_isflag(char c)
{
	return (c == ' ' || c == '#' || c == '+'		/* Standard printf flags */
		|| c == '-' || c == '*' || c == '0');
}
