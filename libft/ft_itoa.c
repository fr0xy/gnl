/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:38:44 by rchoffar          #+#    #+#             */
/*   Updated: 2016/11/09 17:13:55 by rchoffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	taille(int size, int tmp)
{
	while (tmp >= 10)
	{
		size++;
		tmp = tmp / 10;
	}
	return (size);
}

static int	test_neg(int size, int *n)
{
	if (*n < 0)
	{
		size++;
		*n = *n * -1;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	unsigned int	size;
	char			*str;

	size = 2;
	if (n == -2147483648)
	{
		str = ft_strsub("-2147483648", 0, 12);
		return (str);
	}
	size = test_neg(size, &n);
	size = taille(size, n) - 2;
	if ((str = (char *)malloc(size + 2)) != NULL)
	{
		str[size + 1] = '\0';
		while (n >= 10)
		{
			str[size] = n % 10 + '0';
			n = n / 10;
			size--;
		}
		str[size] = n + '0';
		if (size == 1)
			str[0] = '-';
	}
	return (str);
}
