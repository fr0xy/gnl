/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 20:38:57 by rchoffar          #+#    #+#             */
/*   Updated: 2016/11/09 17:16:14 by rchoffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_test_needle_n(const char *haystack,
		const char *needle, int *tab, size_t len)
{
	while (haystack[tab[0]] == needle[tab[1]]
			&& needle[tab[1]] != '\0' && tab[0] < (int)len)
	{
		tab[0]++;
		tab[1]++;
	}
	return (tab[1]);
}

char			*ft_strnstr(const char *haystack,
		const char *needle, size_t len)
{
	int	tab[3];

	tab[0] = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[tab[0]] != '\0' && tab[0] < (int)len)
	{
		tab[1] = 0;
		if (haystack[tab[0]] == needle[tab[1]])
		{
			tab[2] = tab[0];
			tab[1] = ft_test_needle_n(haystack, needle, tab, len);
			if (needle[tab[1]] == '\0')
				return ((char*)haystack + tab[2]);
			else
				tab[0] = tab[2] + 1;
		}
		else
			tab[0]++;
	}
	return (NULL);
}
