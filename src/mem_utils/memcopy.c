/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcopy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:14:48 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:22:30 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** memcopy - Copy memory area
** @dest: Destination memory area
** @src: Source memory area
** @n: Number of bytes to copy
**
** Copies n bytes from memory area src to memory area dest.
** This is a custom implementation of the standard memcpy function.
** The memory areas must not overlap (use memmove for overlapping areas).
**
** Return: Pointer to dest
*/
void	*memcopy(void *dest, const void *src, unsigned long n)
{
	char	*d;		/* Destination pointer cast to char* */
	char	*s;		/* Source pointer cast to char* */

	/* Handle null pointers with non-zero size */
	if (!dest && !src && n > 0)
		return (0);
	
	d = (char *)dest;
	s = (char *)src;
	
	/* Copy bytes one by one */
	while (n--)
		*d++ = *s++;
	
	return (dest);
}
