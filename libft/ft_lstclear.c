/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:02:23 by fmota             #+#    #+#             */
/*   Updated: 2021/10/31 17:46:33 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	**t;
	t_list	*tmp;

	if (!del)
		return ;
	t = lst;
	while (lst && *lst)
	{
		(*del)((*lst)->content);
		tmp = (*lst)->next;
		free(*lst);
		(*lst) = tmp;
	}
	if (t)
		*t = NULL;
}
