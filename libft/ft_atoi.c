/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:34:57 by rchoffar          #+#    #+#             */
/*   Updated: 2016/11/11 17:04:02 by rchoffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	signe;
	int	result;

	signe = 1;
	i = 0;
	while ((*(nptr + i) < 27 && (*nptr + i) >= 0) || *(nptr + i) == 127 ||
	(*(nptr + i) > 27 && *(nptr + i) <= 32))
		i++;
	if (*(nptr + i) == '+')
	{
		i++;
	}
	else if (*(nptr + i) == '-')
	{
		i++;
		signe = -1;
	}
	while (*(nptr + i) >= '0' && *(nptr + i) <= '9')
	{
		result = result * 10 + *(nptr + i) - '0';
		i++;
	}
	return (result * signe);
}
