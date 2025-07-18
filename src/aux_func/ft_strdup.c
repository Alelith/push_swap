/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:16:25 by acesteve          #+#    #+#             */
/*   Updated: 2025/07/16 09:55:23 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *s)
{
	char	*result;

	result = malloc(ft_strlen(s) + 1);
	if (!result)
		return (0);
	ft_strlcpy(result, s, ft_strlen(s) + 1);
	return (result);
}
