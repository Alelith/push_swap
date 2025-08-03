/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:54:50 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 16:04:07 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_isupper - Check if character is an uppercase letter
** @c: Character to test
**
** Tests whether the given character is an uppercase ASCII letter (A-Z).
** Used in printf implementation to determine case for hexadecimal output
** formatting (X vs x specifier). Returns 1 if uppercase, 0 otherwise.
*/
int	ft_isupper(char c)
{
	return (c >= 'A' && c <= 'Z');		/* ASCII range check for uppercase */
}
