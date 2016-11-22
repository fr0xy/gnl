/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:01:34 by rchoffar          #+#    #+#             */
/*   Updated: 2016/11/07 16:14:11 by rchoffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if ((str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)) != NULL)
	{
		ft_strcpy(str, s1);
		ft_strcat(str, s2);
	}
	return (str);
}
