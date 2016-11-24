/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:54:37 by rchoffar          #+#    #+#             */
/*   Updated: 2016/11/04 15:54:38 by rchoffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;

	if ((str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)) != NULL)
		str = ft_strcpy(str, s);
	return (str);
}
