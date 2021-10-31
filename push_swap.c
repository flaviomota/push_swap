/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 13:26:00 by fmota             #+#    #+#             */
/*   Updated: 2021/10/31 17:17:43 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		len;
	int		*nb;
	char	*str;
	char	**str2;
	t_list	*stack;

	if (argc > 1)
	{
		check(argv + 1);
		str = ft_join(argv + 1, " ");
		str2 = ft_split(str, ' ');
		nb = 0;
		len = converter(str2, &nb);
		wipe_up1(str, str2);
		if (!len)
			ft_error(1);
		stack = 0;
		while (len--)
			ft_lstadd_front(&stack, ft_lstnew(&nb[len]));
		if (!arranged(stack))
			sort(&stack);
		wipe_up2(nb, stack);
	}
	return (0);
}