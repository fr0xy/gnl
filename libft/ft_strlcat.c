/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:07:48 by rchoffar          #+#    #+#             */
/*   Updated: 2016/11/09 15:14:15 by rchoffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (size - i > 0 && dst[i])
		i++;
	size -= i;
	while (size > 1 && src[j])
	{
		dst[i + j] = src[j];
		j++;
		size--;
	}
	if (j > 0)
		dst[i + j] = '\0';
	while (src[j])
		j++;
	return (i + j);
}
