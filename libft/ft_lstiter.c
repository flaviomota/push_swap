/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:06:27 by fmota             #+#    #+#             */
/*   Updated: 2021/10/31 17:45:26 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*new;

	if (!lst)
		lst = NULL;
	if (f)
	{
		while (lst)
		{
			new = lst->next;
			f((lst)->content);
			lst = new;
		}
	}
}
