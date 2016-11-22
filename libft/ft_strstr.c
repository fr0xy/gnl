/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:52:22 by rchoffar          #+#    #+#             */
/*   Updated: 2016/11/09 17:15:46 by rchoffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_test_needle(const char *haystack,
	const char *needle, int i, int j)
{
	while (haystack[i] == needle[j] && needle[j] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

char		*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			tmp = i;
			j = ft_test_needle(haystack, needle, i, j);
			if (needle[j] == '\0')
				return ((char*)haystack + tmp);
			else
				i = tmp + 1;
		}
		else
			i++;
	}
	return (NULL);
}
