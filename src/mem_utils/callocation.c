/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callocation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:32:53 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:22:30 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** callocation - Allocate and zero-initialize memory
** @nmemb: Number of elements to allocate
** @size: Size of each element in bytes
**
** Allocates memory for an array of nmemb elements of size bytes each
** and initializes all bytes to zero. This is a custom implementation
** of the standard calloc function.
**
** Return: Pointer to allocated memory, or NULL if allocation fails
*/
void	*callocation(unsigned long nmemb, unsigned long size)
{
	int		len;		/* Total number of bytes to allocate */
	char	*result;	/* Pointer to allocated memory */

	len = nmemb * size;
	result = (char *)malloc(len);	/* Allocate memory */
	if (!result)
		return (0);		/* Return NULL if allocation fails */
	
	/* Zero-initialize all bytes */
	while (len--)
		result[len] = 0;
	return (result);
}
