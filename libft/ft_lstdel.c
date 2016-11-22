/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:59:38 by rchoffar          #+#    #+#             */
/*   Updated: 2016/11/11 14:28:38 by rchoffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	while ((*alst) != NULL)
	{
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		(*alst) = (*alst)->next;
	}
	alst = NULL;
}
