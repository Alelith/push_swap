/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:52:40 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 16:03:29 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_isdigit - Check if character is a decimal digit
** @c: Character to test
**
** Tests whether the given character is a decimal digit (0-9).
** Used during format string parsing to identify numeric values
** for width and precision specifiers. Returns 1 if digit, 0 otherwise.
*/
int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');		/* ASCII range check for digits */
}
