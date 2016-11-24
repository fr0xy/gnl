/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:14:17 by rchoffar          #+#    #+#             */
/*   Updated: 2016/11/09 17:16:48 by rchoffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			nb_word(char const *s, char c)
{
	int	i;
	int	word;

	word = 0;
	i = 0;
	if (s[0] != c && s[0] != '\0')
		word++;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			if (s[i] != '\0')
				word++;
		}
		else
			i++;
	}
	return (word);
}

static unsigned int	find_next(const char *str, char c)
{
	unsigned int	i;

	i = 0;
	while (str[i] == c)
		i++;
	return (i);
}

static size_t		size_word(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**tab;
	int				i;
	unsigned int	start;

	start = 0;
	i = 0;
	if ((tab = (char **)malloc(sizeof(char *) * (nb_word(s, c) + 1))) != NULL)
	{
		while (i <= nb_word(s, c))
		{
			tab[i] = 0;
			i++;
		}
		i = 0;
		while (i < nb_word(s, c))
		{
			start = start + find_next(s + start, c);
			tab[i] = ft_strsub(s, start, size_word(s + start, c));
			start = start + size_word(s + start, c);
			i++;
		}
	}
	return (tab);
}
