/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:14:44 by rchoffar          #+#    #+#             */
/*   Updated: 2016/11/07 17:10:13 by rchoffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	while ((s[j - 1] == ' ' || s[j - 1] == '\n' || s[j - 1] == '\t') && j > i)
		j--;
	if ((str = (char *)malloc(j - i + 1)) != NULL)
	{
		ft_strncpy(str, (s + i), j - i);
		str[j - i] = '\0';
	}
	return (str);
}
