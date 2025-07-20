/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcopy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:14:48 by acesteve          #+#    #+#             */
/*   Updated: 2025/07/20 10:28:29 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*memcopy(void *dest, const void *src, unsigned long n)
{
	char	*d;
	char	*s;

	if (!dest && !src && n > 0)
		return (0);
	d = (char *)dest;
	s = (char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}
