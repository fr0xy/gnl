/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:53:58 by rchoffar          #+#    #+#             */
/*   Updated: 2016/11/07 13:37:36 by rchoffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*str;
	int		i;

	i = 0;
	if ((str = (char *)malloc(size)) != NULL)
	{
		while (i < (int)size)
		{
			str[i] = '\0';
			i++;
		}
	}
	return ((void *)str);
}
