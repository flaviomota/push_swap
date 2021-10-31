/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 12:25:03 by fmota             #+#    #+#             */
/*   Updated: 2021/02/17 12:25:03 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *tmp;

	tmp = ft_lstnew(f(lst->content));
	new = tmp;
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		if (!(tmp->next = ft_lstnew(f(lst->content))))
		{
			ft_lstdelone(tmp->next, del);
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (new);
}