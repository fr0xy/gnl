/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoffar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:32:12 by rchoffar          #+#    #+#             */
/*   Updated: 2016/11/11 16:35:56 by rchoffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*result;

	if ((new = ft_lstnew((f(lst))->content, (f(lst))->content_size)) == NULL)
		return (NULL);
	result = new;
	while (lst->next != NULL)
	{
		lst = lst->next;
		if ((new->next = ft_lstnew((f(lst))->content,
						(f(lst))->content_size)) == NULL)
			return (NULL);
		new = new->next;
	}
	return (result);
}
