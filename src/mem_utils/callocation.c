/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callocation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:32:53 by acesteve          #+#    #+#             */
/*   Updated: 2025/07/19 18:24:28 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*callocation(unsigned long nmemb, unsigned long size)
{
	int		len;
	char	*result;

	len = nmemb * size;
	result = (char *)malloc(len);
	if (!result)
		return (0);
	while (len--)
		result[len] = 0;
	return (result);
}
